#ifndef CAMPAIGN
#define CAMPAIGN

#include <iosteram>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Campaign{
    string name;//название фирмы
    unsigned budget;//доходы-расходы
    unsigned cost;//затраты для вычисления ROI
    vector<double>results;//рейтинги фирм
public:
    Campaign();//по умолчанию
    Campaign(unsigned r);//констрктор с параметром
    Campaign(unsigned r, vector<double>mas);//конструктор с параметром
    Campaign(const Campaign &ob);//конструктор копирования
   ~Campaign(){}
    void set_campaign(unsigned r,const vector<double>&mas){
        if(r<=mas.size()){
            budget=r;
            results.resize(r);
            results.assign(mas.begin(),mas.begin()+r);
        }
        else{
            cerr<<"error: budget exceeds results count "<<endl;
        }
    }
    void set_degree(unsigned r){budget=r;};

    unsigned get_budget()const{ return budget;};
    const vector<double> get_results() const {return results;}
    //void ROI {}
};

#endif
