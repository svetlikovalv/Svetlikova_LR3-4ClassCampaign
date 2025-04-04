#include <cmath>
#include <random>
#include "Svetlikova_LR3-4_Methods.h"
using namespace std;
// bool Campaign::operator<(const Campaign& other)const{
//     return budget < other.budget;
// }



//для генерации рандомных имен компаний из 5 заглавных букв
string generate_company_name() {
    string name;
    random_device rd;
    mt19937 generator(rd());//генератор псевдослучайных рандомных чисел
    uniform_int_distribution<> dist('A', 'Z');

    for (int i = 0; i < 5; ++i) {
        name += static_cast<char>(dist(generator));
    }
    return name;
}

//по умолчанию
Campaign:: Campaign()
{
    name=generate_company_name();
    budget=(rand()%1000+1)/10.0;
    cost=(rand()%1000+1)/10.0;
    results.resize(5.0,0.0);
    generate(results.begin(),results.end(),[](){return (rand()%100)/10.0;});
}


//конструктор копирования
Campaign::Campaign(const Campaign& other)
    :name(other.name), budget(other.budget), cost(other.cost), results(other.results) {}

Campaign& Campaign::operator=(const Campaign& other) {
    if (this != &other) {
        name = other.name;
        budget = other.budget;
        cost = other.cost;
        results = other.results;
    }
    return *this;
}

Campaign& Campaign::operator++(){
    cost+=1.0;
    return *this;
}

 Campaign Campaign::operator++(int){
    Campaign temp = *this;
    ++(*this);
    return temp;
 }

 Campaign operator+(const Campaign& c1, const Campaign& c2) {
    Campaign result = c1;
    result.budget+=c2.budget;
    result.cost += c2.cost;
    result.results.insert(result.results.end(), c2.results.begin(), c2.results.end());
    return result;
}


ostream& operator<<(ostream& mystream, const Campaign& obj) {
    mystream << "Name: " << obj.name << "\n";
    mystream << "Budget: " << obj.budget << "\n";
    mystream << "Cost: " << obj.cost << "\n";
    mystream << "Results: ";
    for (double result : obj.results) {
        mystream << result << " ";
    }
    mystream << "\n";
    return mystream;
} 

istream& operator>>(istream& mystream, Campaign &obj) {
    cout << "Enter campaign name: ";
    getline(mystream, obj.name);
    //string name;
    //obj.set_name(getline(mystream, name));
    cout << "Enter budget: ";
    mystream>>obj.budget;
    mystream.ignore();
    cout << "Enter cost: ";
    mystream>>obj.cost;
    mystream.ignore(); 
    double result;
    obj.results.clear();
    while (mystream.peek() != '\n') {
        mystream >> result;
        obj.results.push_back(result);
    }
    mystream.ignore();
    return mystream;
}

