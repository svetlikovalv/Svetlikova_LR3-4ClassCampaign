#ifndef CAMPAIGN
#define CAMPAIGN

#include <iosteram>
#include <string>
#include <vector>
using namespace std;
class Campaign{
    string name;
    unsigned budget;
    vector<double>results;
public:
    Campaign();
    Campaign(unsigned r);
    Campaign(unsigned r, vector<double>mas);
    Campaign(const Campaign &ob);
   ~Campaign(){}
    void set_campaign(unsigned r,const vector<double>&mas){
        if(r<=mas.size()){
            budget=r;
            results.resize(r);
            results.assign(mas.begin(),mas.begin()+r);
        }
        else{
            cerr<<"error: degree exceeds results count "<<endl;
        }
    }
    void set_degree(unsigned r){budget=r;};

    unsigned get_budget()const{ return budget;};
    const vector<double> get_results() const {return results;}
    void ROI 
};
