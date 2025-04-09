#ifndef CAMPAIGN_METHODS_H //the beginning of shitty code
#define CAMPAIGN_METHODS_H
#include <map>
#include <functional>
#include <algorithm> 
#include <numeric>
#include "Svetlikova_LR3-4_ClassCampaign.h"

using namespace std;

vector<Campaign> campaigns;
// перегруженные(как и я) операторы сравнения
bool Campaign::operator>(const Campaign& other) const { return budget > other.budget; }
bool Campaign::operator>=(const Campaign& other) const { return budget >= other.budget; }
bool Campaign::operator<=(const Campaign& other) const { return budget <= other.budget; }



bool user_input(string input) {
	if (input.empty()) return false;
	try {
		int number = stold(input);
		if (number < 0) return false;
	}
	catch (...) 
	{ return false; }
	return true;
}
//для менюшки берем лямбда-функцию, тк она напрямую с вводом взаимодействует
function<void()> enter_choice(unsigned& varLink, const string& label) {
    return [&varLink, label]() {
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!user_input(raw_input)) {
            cout << "Некорректный ввод. Пожалуйста, введите положительное целое число: " << label << " = "<<endl;
            getline(cin, raw_input);
        }
        varLink = stoi(raw_input); 
    };
}


//для int
void enter_number(unsigned& varLink, const string& label) {
    // return [&varLink, label]() {
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!user_input(raw_input)) {
            cout << "Некорректный ввод. Пожалуйста, введите положительное вещественное число: " << label << " = ";
            getline(cin, raw_input);
        }
        varLink = stoul (raw_input); 
    //};
}
//для double
void enter_number(double& varLink, const string& label) {
    // return [&varLink, label]() {
        std::string raw_input;
        std::cout << label << " = ";
        std::getline(std::cin, raw_input);

        while (!user_input(raw_input)) {
            std::cout << "Некорректный ввод. Пожалуйста, введите положительное вещественное число: " << label << " = ";
            getline(cin, raw_input);
        }
        varLink = stod(raw_input); 
    //};
}

//для строк
void enter_string(string& varLink, string label) {
    // return [&varLink, label]() {
		cout << label << " = ";
        getline(cin, varLink);
    //};
}
//для введения результатов при переопределении оператора ввода
void enter_results(vector<double>& results) {
    unsigned num_results;//для результата
    string num_str;//кол-во результатов
    cout << "Введите количество результатов: "<<endl;
    getline(cin, num_str);
    while (!user_input(num_str) || stod(num_str) != (int)stod(num_str))
     {
        cout << "Некорретный ввод. Введите целое положительное число: "<<endl;
        getline(cin, num_str);
    }
    num_results = stoul(num_str);
    results.clear(); // чистим вектор перед новым вводом
    results.reserve(num_results);//выделяет память под заданное кол-во результатов

    for (unsigned i = 0; i < num_results; ++i) {
        double result;
        string result_str;
        cout << "Введите результат № " << (i + 1) << ": ";
        getline(cin, result_str);

        while (!user_input(result_str)) {
            cout << "Некорретный ввод. Введите положительное число для результата № " << (i + 1) << ": ";
            getline(cin, result_str);
        }

        result = stod(result_str);//преобразовали результат в double
        results.push_back(result);
    }
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
// описание метода ROI 
double Campaign:: ROI ()const{
    if (cost == 0) return 0; // избегаем деление на ноль
    
    return (budget / cost) * 100;
}

//создает несколько кампаний с дефолтным конструктором 
void create_campaign_default(){
    Campaign c1,c2;
    campaigns.push_back(c1);
    campaigns.push_back(c2);
    cout<<"campaign 1: "<<c1<<endl;
    cout<<"campaign 2: "<<c2<<endl;
}
//создает кампанию с помощью констр копирования
void create_campaign_copy (){
    Campaign c2;
    cout<<"campaign 2: "<<c2<<endl;
    Campaign c3=c2;
    cout<<"campaign 3: "<<c3<<endl;
    campaigns.push_back(c3);
}

//создает кампанию при воде пользователем с клавиатуры каждого поля
void create_campaign_consol(){
    Campaign c5;
    cin>>c5;
    campaigns.push_back(c5);
    cout<<"введеннная компания: "<<c5<<endl;
}


//для инкриментов
void add_campaign(){
    if (campaigns.size() > 0){
        //вывод списка кампаний
      cout << "\n The list of campaigns\n" ;
      for (auto it = campaigns.begin(); it != campaigns.end(); it++)
          cout << (it - campaigns.begin()) << ") " << *it << endl;
      //ввод номера кампании для вычислений
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
//складывает 2 кампании добавляя 2ой вектор в конец первого
void sum_array_campaign(){
    cout<<"вычисление суммы компаний"<<endl;
    //Campaign camp=campaigns[num1]=campaigns[num2];
    if (campaigns.size() > 0){
        //вывод списка кампаний
      cout << "\n The list of campaigns\n" ;
      for (auto it = campaigns.begin(); it != campaigns.end(); it++)
          cout << (it - campaigns.begin()) << ") " << *it << endl;
      //ввод номера кампании для вычислений
      unsigned num1 = 0;
      enter_choice(num1, "Input number of first campaign: ")();
      unsigned num2 = 0;
      enter_choice(num2, "Input number of second campaign: ")();
      try{
        cout<<"сумма кампаний: "<<campaigns[num1]+campaigns[num2]<<endl;
        campaigns.push_back(campaigns[num1]+campaigns[num2]);
        }
      catch(...){
          cerr << "Errror, try enter another number of campaign";
      }
  }
}

void test_comparison_campaign(){
    cout<<"тест присваивания одной кампании другой"<<endl;
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
    //тестирование сетов 
    cout<<"тестирование set-методов: "<<endl;
    cout<<"начальная кампания: "<<c6<<endl;
    cout<<"новые значения для set-ов: name=new name budget=300.0 cost=250.0 results{2.3,3.4,5.6}"<<endl;
    c6.set_name("new name");
    c6.set_budget(300.0);
    c6.set_cost(250.0);
    c6.set_results({2.3,3.4,5.6});
    cout<<"измененная кампания: "<<c6<<endl;
    cout<<"тестирование метода ROI для кампании"<<endl;
    cout<<"ROI of campaign: "<<c6.ROI()<<endl;
}

void test_operators(){
    cout<<"тест операторов сравниения кампаний по бюджету(формат вывода:0 или 1)"<<endl;
    Campaign c7,c8;
    cout<<"компания #1 для теста "<<c7<<endl;
    cout<<"компания #2 для теста "<<c8<<endl;
    cout<<"тест оператора < : "<< (c7<c8) <<endl;
    cout<<"тест оператора > : "<< (c7>c8) <<endl;
    cout<<"тест оператора <= : "<< (c7<=c8) <<endl;
    cout<<"тест оператора >= : "<< (c7>=c8) <<endl;
}


vector<Campaign> sortCampaignsByBudget() {
    vector<Campaign> camps = campaigns;
    sort(camps.begin(), camps.end());
    return camps;
    
}
void sorted_campaigns(){
    vector<Campaign> camp=sortCampaignsByBudget();
    cout<<"отсортированные по возрастанию бюджета кампании: "<<endl;
    for(const auto&c:camp){
        cout<<c<<endl;
    }
}

#endif