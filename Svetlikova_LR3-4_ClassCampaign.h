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
    Campaign(const string& n, double b); //: name(n), budget(b), cost(0); //с параметром
    //преобразования?
    Campaign(double c);//: cost(c);
    //конструктор копирования
    Campaign(const Campaign& other); //: name(other.name), budget(other.budget), cost(other.cost), results(other.results); 

    //explicit Campaign(const string& name): Campaign(name, 0.0, 0.0, {}){}//запрет на неявные преобразования
    Campaign(string&& n, double b); //: name(move(n)), budget(b), cost(0); 



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
    void setResults(const vector<double>& r) { results = r; }

    double ROI ()const{
        if (cost == 0) return 0; // Избегаем деления на ноль
        
        return (budget / cost) * 100;
    }
    //перегрузки
    bool operator<(const Campaign& other) const { return budget < other.budget; }//сравнение компаний по бюджету
    Campaign& operator+(const Campaign& other)const;
    Campaign& operator++(); //префиксный инкремент для стоимости
    Campaign& operator++(int); //постфиксный инкремент для стоимости
    Campaign& operator=(const Campaign& other);
    //дружественные ввод и вывод
    friend ostream& operator<<(ostream& mystream,const Campaign &obj);
    friend istream& operator>>(istream& mystream, Campaign &obj);
};

#endif
