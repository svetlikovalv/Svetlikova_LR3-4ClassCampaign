#include <ctime>
#include <map>
#include "Svetlikova_LR3-4_ClassCampaign.cpp"
using namespace std;



int main(){
    srand(time(NULL));
    create_campaign_default();
    map<int, menu_item > menu = {
        {1,{"Create Campaign constructor default",create_campaign_default}},
        {2,{"Create Campaign constructor of copy",create_campaign_copy}},
        //{3,{"Create Campaign constructor of trans",create_campaign_trans}},
        //{4,{"Create Campaign with consol",create_campaign_consol}},
        //{5,{"Show array of Campaign",show_array_campaign(vector_of_all_campaign)}},
        //{6,{"Calculate Campaign ROI",ROI}},
        //{7,{"Add of Campaign",add_campaign}},
        //{8,{"Sum of array the Campaign",sum_array_campaign}},
        //{9,{"Sort Campaigns by budget",sort_campaigns_by_budget}},
    };
    unsigned choice = 0;

    cout<<"Меню: "<<endl;
    for (const auto& item : menu){
        cout<<"Task "<<item.first<<". "<<item.second.title<<endl;
    }
    cout<<"0. Выход"<<endl;
    while (true){
        enter_number(choice,"Введите номер пункта: ")();
        if (choice==0){
            cout<<"Вы вышли из программы"<<endl;
            break;
        }
        cout<<"==========Action=========="<<endl;
        if (menu.find(choice)!=menu.end()){
            menu[choice].action;
        }
        else{
            cout<<"Некорректный ввод. ";
        }
        cout<<endl;
    }
    return 0;
}



