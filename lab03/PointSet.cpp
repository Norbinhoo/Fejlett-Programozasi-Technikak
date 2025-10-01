//
// Created by modin on 10/1/2025.
//
#include "PointSet.h"
#include <algorithm>
#include <random>

void PointSet::computeDistances() {
    distances.clear();
    distances.reserve(n * (n - 1) / 2);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}


double PointSet::maxDistance() const {
    if (distances.empty()) {
        return 0.0;
    }
    return *std::max_element(distances.begin(), distances.end());

}

double PointSet::minDistance() const {
    if (distances.empty()) {
        return 0.0;
    }
    return *std::min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {

}

PointSet::PointSet(int n) {
    this->n = n;
    while( points.size() < n) {
        random_device rd; // seed the random number generator named rd
        mt19937 mt(rd()); // Mersenne Twister algorithm to generate random numbers
        uniform_int_distribution<int> dist(0, M); // return a number in the give range
        int x = dist(mt);
        int y = dist(mt);
        points.push_back(Point(x,y));
    }
    computeDistances();
}
