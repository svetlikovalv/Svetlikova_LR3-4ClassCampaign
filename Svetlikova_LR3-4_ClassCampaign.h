#ifndef CAMPAIGN
#define CAMPAIGN

#include <iostream>
#include <functional>
#include <string>
#include <vector>

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
    Campaign(string &n, double b,double c, const vector<double>& r): name(n), budget(b), cost(c),results(r) {}
    //конструктор копирования
    Campaign(const Campaign& other);
    


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

    double ROI ()const{
        if (cost == 0) return 0; // избегаем деление на ноль
        
        return (budget / cost) * 100;
    }
    //перегрузки
    bool operator<(const Campaign& other) const { return budget < other.budget; }//сравнение компаний по бюджету
    friend Campaign operator+(const Campaign& c1, const Campaign& c2);
    Campaign& operator++(); //префиксный инкремент для стоимости
    Campaign operator++(int); //постфиксный инкремент для стоимости
    Campaign& operator=(const Campaign& other);
    //дружественные ввод и вывод
    friend ostream& operator<<(ostream& mystream,const Campaign &obj);
    friend istream& operator>>(istream& mystream, Campaign &obj);

};

#endif
