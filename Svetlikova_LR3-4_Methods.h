#ifndef CAMPAIGN_METHODS_H 
#define CAMPAIGN_METHODS_H
#include <map>
#include <functional>
#include <algorithm> 
#include <numeric>
#include "Svetlikova_LR3-4_ClassCampaign.h"

using namespace std;

vector<Campaign> campaigns;



bool user_choice(string input) {
	if (input.empty()) return false;
	try {
		int number = stoi(input);
		if (number < 0) return false;
	}
	catch (...) 
	{ return false; }
	return true;
}
function<void()> enter_choice(unsigned& varLink, string label) {
    return [&varLink, label]() {
        string raw_input;
		cout << label << " = ";
        getline(cin, raw_input);

        while (!user_choice(raw_input)) {
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varLink = stoi(raw_input);
    };
}


bool user_input(string input) {
	if (input.empty()) return false;
	try {
		int number = stod(input);
		if (number < 0) return false;
	}
	catch (...) 
	{ return false; }
	return true;
}
function<void()> enter_number(unsigned& varLink, string label) {
    return [&varLink, label]() {
        string raw_input;
		cout << label << " = ";
        getline(cin, raw_input);

        while (!user_input(raw_input)) {
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varLink = stod(raw_input);
    };
}

function<void()> enter_string(string& varLink, string label) {
    return [&varLink, label]() {
		cout << label << " = ";
        getline(cin, varLink);
    };
}
//структура для менюшки
struct menu_item {
    string title;
    function<void()> action;
};



function<void()> show_array_campaign(vector<Campaign> &v){
    return [&v]() {
    if (v.size() > 0){
        cout << "\nThe list of Campaigns\n" ;
        for (auto it = v.begin(); it != v.end(); it++)
            cout << (it - v.begin()) << ") " << *it << endl;
        cout << "\nThe end of list\n";

    }
    else
        cerr << "Errror, list of Campaigns is empty\n";
    };
}
//создает несколько компаний с дефолтным конструктором 
void create_campaign_default(){
    Campaign c1,c2;
    campaigns.push_back(c1);
    campaigns.push_back(c2);
    cout<<"campaign 1: "<<c1<<endl;
    cout<<"campaign 2: "<<c2<<endl;
}
//создает компанию с помощью констр копирования
void create_campaign_copy (){
    Campaign c2;
    cout<<"campaign 2: "<<c2<<endl;
    Campaign c3=c2;
    cout<<"campaign 3: "<<c3<<endl;
}

//создает компанию при воде пользователем с клавиатуры каждого поля
void create_campaign_consol(){
    Campaign c5;
    cin>>c5;
    campaigns.push_back(c5);
    cout<<"введеннная компания: "<<c5<<endl;
}


//для инкриментов
void add_campaign(){
    if (campaigns.size() > 0){
        //вывод списка компаний
      cout << "\n The list of campaigns\n" ;
      for (auto it = campaigns.begin(); it != campaigns.end(); it++)
          cout << (it - campaigns.begin()) << ") " << *it << endl;
      //ввод номера компании для вычислений
      unsigned number = 0;
      enter_choice(number, "Input number of campaign for calculation increments: ")();
      try{
        cout<<"постфиксный инкримент до"<<endl;
        cout<<campaigns[number]++<<endl;
        cout<<"после: "<<campaigns[number]<<endl;
        cout<<"префиксный инкримент: "<<++campaigns[number]<<endl;
        
        }
      catch(...){
          cerr << "Errror, try enter another number of campaign";
      }
  }
}
//складывает 2 компании добавляя 2ой вектор в конец первого
void sum_array_campaign(){
    cout<<"вычисление суммы компаний и тест присваивания"<<endl;
    //Campaign camp=campaigns[num1]=campaigns[num2];
    if (campaigns.size() > 0){
        //вывод списка компаний
      cout << "\n The list of campaigns\n" ;
      for (auto it = campaigns.begin(); it != campaigns.end(); it++)
          cout << (it - campaigns.begin()) << ") " << *it << endl;
      //ввод номера компании для вычислений
      unsigned num1 = 0;
      enter_choice(num1, "Input number of first campaign: ")();
      unsigned num2 = 0;
      enter_choice(num2, "Input number of second campaign: ")();
      try{
        cout<<"сумма компаний: "<<campaigns[num1]+campaigns[num2]<<endl;
        Campaign camp=campaigns[num1]=campaigns[num2];
        cout<<"тест присваивания: "<< camp<<endl;
        }
      catch(...){
          cerr << "Errror, try enter another number of campaign";
      }
  }
}
//sets
void methods(){
    Campaign c6;
    cout<<"начальная компания: "<<c6<<endl;
    c6.set_name("new name");
    c6.set_budget(300.0);
    c6.set_cost(250.0);
    c6.set_results({2.3,3.4,5.6});
    cout<<"измененная компания: "<<c6<<endl;
    
}

void roi(){
    cout<<"вычисление roi компаний "<<endl;
    if (campaigns.size() > 0){
        //вывод списка компаний
      cout << "\n The list of campaigns\n" ;
      for (auto it = campaigns.begin(); it != campaigns.end(); it++)
          cout << (it - campaigns.begin()) << ") " << *it << endl;
      //ввод номера компании для вычислений
      unsigned num1 = 0;
      enter_choice(num1, "Input number of first campaign: ")();
      
      try{
        cout<< campaigns[num1].ROI() <<endl;
        }
      catch(...){
          cerr << "Errror, try enter another number of campaign";
      }
  }
}


vector<Campaign> sortCampaignsByBudget() {
    vector<Campaign> camps = campaigns;
    sort(camps.begin(), camps.end());
    return camps;
    
}
void sorted_campaigns(){
    vector<Campaign> camp=sortCampaignsByBudget();
    cout<<"отсортированные компании: "<<endl;
    for(const auto&c:camp){
        cout<<c<<endl;
    }
}

#endif