#include <ctime>
#include <map>
#include "Svetlikova_LR3-4_ClassCampaign.cpp"
using namespace std;



int main(){
    srand(time(NULL));
    map<int, menu_item > menu = {
        {1,{"Create Campaign constructor default",create_campaign_default}},
        {2,{"Create Campaign constructor of copy",create_campaign_copy}},
        {3,{"Create Campaign with consol",create_campaign_consol}},
        {4,{"Show array of Campaign",show_array_campaign(campaigns)}},
        {5,{"Calculate Campaign ROI",roi}},
        {6,{"Add of Campaign",add_campaign}},//для инкриментов
        {7,{"Sum of the Campaign",sum_array_campaign}},//для плюса и присваивания
        {8,{"Sort Campaigns by budget",sorted_campaigns}},
        {9,{"Demonstration of set methods",methods}},
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
            menu[choice].action();
        }
        else{
            cout<<"Некорректный ввод. ";
        }
        cout<<endl;
    }
    return 0;
}



