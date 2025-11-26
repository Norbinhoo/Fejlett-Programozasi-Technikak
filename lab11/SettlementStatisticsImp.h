//
// Created by modin on 11/26/2025.
//

#ifndef LAB11_SETTLEMENTSTATISTICSIMP_H
#define LAB11_SETTLEMENTSTATISTICSIMP_H

#include <map>
#include <string>
#include "SettlementStatistics.h"
#include "Settlement.h"

using namespace std;

class SettlementStatisticsImp :public SettlementStatistics{
    multimap<string,Settlement> settlements;
    void readFromFile(string filename);
public:
    int numSettlements() const override{
        return settlements.size();
    }

    int numCounties() const override;

    int numSettlementsByCounty(const string &county) const override;

    virtual vector<Settlement> findSettlementsByCounty(const string &county) const override;

    Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const override;

    Settlement maxPopulationBySettlement() const override;

    Settlement minPopulationBySettlement() const override;

    vector<Settlement> findSettlementsByName(const string &name) override;

    SettlementStatisticsImp(string filename){ readFromFile(filename);}
};


#endif //LAB11_SETTLEMENTSTATISTICSIMP_H
