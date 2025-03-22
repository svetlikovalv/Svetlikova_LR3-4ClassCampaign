#include <cmath>
#include <iomanip>
#include <C:\Users\Chris Gargoyle\Svetlikova_LR3-4_ClassCampaign\Svetlikova_LR3-4ClassCampaign\Svetlikova_LR3-4_Methods.h>

Campaign ::Campaign(){
    budget=rand()%5+1;
    results.resize(budget,0);
    generate(results.begin(),results.end(),[](){return rand()%100;});

}
Campaign ::Campaign(unsigned r){
    budget = r;
    results.resize(budget,0);
    generate(results.begin(),results.end(),[](){return rand()%100;});
}
Campaign ::Campaign(unsigned r,vector<double>mas):Campaign(r){
    set_campaign(r,mas);
}

Campaign ::Campaign(const Campaign & other)
    :budget(other.budget),results(other.results){}
//void Campaign::ROI(){}
    //реализовать roi метод roi=(доходы - затраты)/затраты *100%)

Campaign Campaign::operator+(const Campaign & other)const{
    Campaign res;
    res.budget=max(budget,other.budget);
    res.results.resize(res.budget);
    return ;
    
}