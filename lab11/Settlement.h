//
// Created by modin on 11/26/2025.
//

#ifndef LAB10_SETTLEMENT_H
#define LAB10_SETTLEMENT_H

#include <iostream>

using namespace std;

class Settlement {
    string name = "";
    string county = "";
    int population = 0;
// constructor, getters, setters, inserter operator

public:
    Settlement(const string &name, const string &county, int population) : name(name), county(county),
                                                                           population(population) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Settlement::name = name;
    }

    const string &getCounty() const {
        return county;
    }

    void setCounty(const string &county) {
        Settlement::county = county;
    }

    int getPopulation() const {
        return population;
    }

    void setPopulation(int population) {
        Settlement::population = population;
    }

    friend ostream &operator<<(ostream &os, const Settlement &settlement) {
        os << "name: " << settlement.name << " county: " << settlement.county << " population: "
           << settlement.population;
        return os;
    }
};

#endif //LAB10_SETTLEMENT_H
