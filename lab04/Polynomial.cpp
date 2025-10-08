//
// Created by modin on 10/8/2025.
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree + 1;
    this->coefficients = new double[capacity];
    for (int i = 0; i < capacity; i++) {
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::~Polynomial() {
    if (coefficients != nullptr) {
        delete[]coefficients;
    }
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    for (int i = 0; i < what.capacity - 1; i++) {
        out << what.coefficients[i] << "x^" << (what.capacity - 1 - i) << "+";
    }
    out << what.coefficients[what.capacity - 1] << endl;
    return out;
}

double Polynomial::evaluate(double x) const {
    double v = this->coefficients[0];
    for (int i = 1; i < this->capacity; i++) {
        v = v * x + this->coefficients[i];
    }
    return v;
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        this->coefficients[i] = that.coefficients[i];
    }
}


Polynomial Polynomial::derivative() const {
    if (this->capacity == 1) {
        double zeroCoeff[1] = {0.0};
        return Polynomial(0, zeroCoeff);
    }

    int newDegree = this->capacity - 2;
    double *newCoefficients = new double[newDegree + 1];

    for (int i = 0; i < this->capacity - 1; i++) {
        int power = this->capacity - 1 - i;
        newCoefficients[i] = this->coefficients[i] * power;
    }

    Polynomial result(newDegree, newCoefficients);
    delete[] newCoefficients;
    return result;
}

double Polynomial::operator[](int index) const {
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    Polynomial q = a;
    for (int i = 0; i < q.capacity; i++) {
        q.coefficients[i] = -q.coefficients[i];
    }
    return q;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    int maxCapacity;
    if (a.capacity > b.capacity) {
        maxCapacity = a.capacity;
    } else {
        maxCapacity = b.capacity;
    }

    double *newCoefficients = new double[maxCapacity];

    for (int i = 0; i < maxCapacity; i++) {
        double coeffA = 0.0;
        double coeffB = 0.0;

        if (i >= maxCapacity - a.capacity) {
            coeffA = a.coefficients[i - (maxCapacity - a.capacity)];
        }

        if (i >= maxCapacity - b.capacity) {
            coeffB = b.coefficients[i - (maxCapacity - b.capacity)];
        }

        newCoefficients[i] = coeffA + coeffB;
    }

    Polynomial result(maxCapacity - 1, newCoefficients);
    delete[] newCoefficients;
    return result;
}


Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    int maxCapacity;
    if (a.capacity > b.capacity) {
        maxCapacity = a.capacity;
    } else {
        maxCapacity = b.capacity;
    }

    double *newCoefficients = new double[maxCapacity];

    for (int i = 0; i < maxCapacity; i++) {
        double coeffA = 0.0;
        double coeffB = 0.0;

        if (i >= maxCapacity - a.capacity) {
            coeffA = a.coefficients[i - (maxCapacity - a.capacity)];
        }

        if (i >= maxCapacity - b.capacity) {
            coeffB = b.coefficients[i - (maxCapacity - b.capacity)];
        }

        newCoefficients[i] = coeffA - coeffB;
    }

    Polynomial result(maxCapacity - 1, newCoefficients);
    delete[] newCoefficients;
    return result;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int resultDegree = (a.capacity - 1) + (b.capacity - 1);
    int resultCapacity = resultDegree + 1;

    double *newCoefficients = new double[resultCapacity];

    for (int i = 0; i < resultCapacity; i++) {
        newCoefficients[i] = 0.0;
    }

    for (int i = 0; i < a.capacity; i++) {
        for (int j = 0; j < b.capacity; j++) {
            int resultIndex = resultCapacity - 1 - ((a.capacity - 1 - i) + (b.capacity - 1 - j));
            newCoefficients[resultIndex] += a.coefficients[i] * b.coefficients[j];
        }
    }

    Polynomial result(resultDegree, newCoefficients);
    delete[] newCoefficients;
    return result;
}



