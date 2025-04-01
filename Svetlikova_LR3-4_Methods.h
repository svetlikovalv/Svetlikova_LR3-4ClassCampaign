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
//создает компанию с помощью констр преобразования
void create_campaign_trans(){
    //Campaign c4();
}
//создает компанию при воде пользователем с клавиатуры каждого поля
void create_campaign_consol(){
    
}


//складывает 2 компании добавляя 2ой вектор в конец первого
void add_campaign(){
    
}
//
void sum_array_campaign(){
    
}

// функция, возвращающая список кампаний, отсортированных по бюджету
vector<Campaign> sort_campaigns_by_budget(vector<Campaign>& campaigns) {
    sort(campaigns.begin(), campaigns.end());
    return campaigns;
}






#endif