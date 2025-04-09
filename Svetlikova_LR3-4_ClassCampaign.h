#ifndef CAMPAIGN
#define CAMPAIGN

#include <iostream>
#include <functional>
#include <string>
#include <vector>
// делегирование +done
// все оператры сравнения +done
// тестирование сравнения +done
// вынести ROI из h в methods +done
// проверка ввода в переопеределении >> +done
// доделать контроль ввода - добавить параметр проверки в поток istream. oh shit, here we go again.. +done
// после копирования и суммы добавить новые компании в общий вектор :.( +done
using namespace std;
class Campaign{
    string name;//название фирмы
    double budget;//доходы-расходы=бюджет
    double cost;//затраты для вычисления ROI=(бюджет/затраты)*100%
    vector<double>results;//рейтинги фирм
public:
    Campaign(); //по умолчанию
    Campaign(const string& n) : name(n), budget(0.0), cost(0.0),results({0.0}){} //преобразования?
    //с параметрами
    // Campaign(string &n, double b,double c, const vector<double>& r): name(n), budget(b), cost(c),results(r) {}
    Campaign(const string& n, double b, double c, const vector<double>& r)
        : name(n), budget(b), cost(c), results(r) {}

    //конструктор копирования
    Campaign(const Campaign& other);
    //конструктор спихивания задачи(делегирования) вызывает параметризированный
    Campaign(const string& n, double b) : Campaign(n, b, 0.0, {}) {}

   ~Campaign()=default;
    //геты
    string get_name()const {return name;}
    double get_budget()const{ return budget;}
    double get_cost()const{ return cost;}
    vector<double>get_results() const{return results;}
    //сеты
    void set_name(const string& n) { name = n; }
    void set_budget(double r){budget=r;};
    void set_cost(double r){cost=r;};
    void set_results(const vector<double>& r) { results = r; }

    double ROI ()const;

    //перегрузки
    bool operator<(const Campaign& other) const { return budget < other.budget; }//для сортировки компаний по бюджету
    bool operator>(const Campaign& other) const;
    bool operator>=(const Campaign& other) const;
    bool operator<=(const Campaign& other) const;
    friend Campaign operator+(const Campaign& c1, const Campaign& c2);
    Campaign& operator++(); //префиксный инкремент для стоимости
    Campaign operator++(int); //постфиксный инкремент для стоимости
    Campaign& operator=(const Campaign& other);
    //дружественные ввод и вывод
    friend ostream& operator<<(ostream& mystream,const Campaign &obj);
    friend istream& operator>>(istream& mystream, Campaign &obj);

};

#endif
