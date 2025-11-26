#include <iostream>
#include "Settlement.h"
#include "SettlementStatisticsImp.h"


int main() {
    /*Settlement settlement("Sepsiszentgyorgy","CV",50080);
    cout<<settlement;*/

    SettlementStatistics * ps=new SettlementStatisticsImp("telepulesek.csv");
    cout<<"Telepulesek szama:"<<ps->numSettlements()<<endl;
    cout<<"A megyek szama:"<<ps->numCounties()<<endl;
    string county="CV";
    cout<<"Telepulesek szama egy adott megyeben:"<<ps->numSettlementsByCounty(county)<<endl;

    vector<Settlement> settlements1=ps->findSettlementsByCounty("CV");
    for(Settlement p: settlements1){
        cout<<"\n"<<p<<endl;
    }
    cout<<endl;


    delete ps;
    return 0;
}