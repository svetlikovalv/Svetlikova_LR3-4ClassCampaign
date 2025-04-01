#include <cmath>
#include <iomanip>
#include <random>
#include "Svetlikova_LR3-4_Methods.h"
using namespace std;
// bool Campaign::operator<(const Campaign& other)const{
//     return budget < other.budget;
// }



string generate_company_name() {
    string name;
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> dist('A', 'Z');

    for (int i = 0; i < 5; ++i) {
        name += static_cast<char>(dist(generator));
    }
    return name;
}


Campaign:: Campaign()
{
    name=generate_company_name();
    budget=rand()%100+1;
    cost=rand()%100+1;
    results.resize(0,5);
    generate(results.begin(),results.end(),[](){return rand()%10;});
}


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

 /*Campaign& Campaign::operator++(int){
    Campaign temp = *this;
    ++(*this);
    return temp;
 }*/

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

