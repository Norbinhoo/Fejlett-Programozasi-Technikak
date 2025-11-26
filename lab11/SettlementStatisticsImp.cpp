//
// Created by modin on 11/26/2025.
//

#include "SettlementStatisticsImp.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;


void SettlementStatisticsImp::readFromFile(string filename) {
    ifstream f(filename);
    if(!f){
        cout<<"Hiba a bemenetnel!"<<endl;
        return;
    }
    string line;
    while(getline(f,line)){
        stringstream ss(line);
        string name,county,populationStr;
        getline(ss,name,',');
        getline(ss,county,',');
        getline(ss,populationStr);
        stringstream conv(populationStr);
        int population;
        conv>>population;
        this->settlements.insert({county,Settlement(name,county,population)});
        //this->settlements.insert({county,{name,(name,county,population}});
    }

}

int SettlementStatisticsImp::numCounties() const {
    set<string> keys;
    for(auto& k:settlements){
           keys.insert(k.first);
    }
    return keys.size();

}

int SettlementStatisticsImp::numSettlementsByCounty(const string &county) const {
    int count = 0;
    for (const auto& s : settlements) {
        if (s.second.getCounty() == county) {
            count++;
        }
    }
    return count;
}

vector<Settlement> SettlementStatisticsImp::findSettlementsByCounty(const string &county) const {
    vector<Settlement> result;
    auto range=settlements.equal_range(county);
    for(auto it=range.first;it!=range.second;it++){
        result.push_back(it->second);
    }
    return result;
}





