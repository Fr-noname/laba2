#include "odin.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


    MyVector::MyVector(vector<double> p, int n) {
        this->n = n;
        this->p = p;
    }

    MyVector::MyVector(int n) {
        this->n = n;
        this->p = vector<double>(n);
    }

    MyVector::MyVector(const MyVector & V)
    {
        n = V.n;
        for (int i = 0; i < n; i++)
            p[i] = V.p[i];
    }

    MyVector::MyVector(MyVector &&V) {
        swap(p, V.p);
        swap(n, V.n);
    }


    MyVector::MyVector() {
        n = 0;
    }

    double &MyVector::operator [](int index) {
        return p[index];
    }

    MyVector &MyVector::operator =(const MyVector &v2) {
        if (this != &v2) {
            n = v2.n;
            for (int i = 0; i < n; i++) {
                p[i] = v2.p[i];
            }
        }
        return *this;
    }

    MyVector &MyVector::operator =(MyVector &&v2) {
        if (this != &v2) {
            std::swap(p, v2.p);
            std::swap(n, v2.n);
        }
        return *this;
    }

    MyVector::~MyVector() {
        p.clear();
    }

    MyVector operator +(MyVector &v1) {
        MyVector V(v1.p, v1.n);
        for (int i = 0; i < v1.n; i++) {
            V.p[i] += v1.p[i];
        };
        return V;
    }

    istream& operator>>(istream& is, MyVector& vec) {
        // vec.p.clear();
        int x;
        for (int i = 0; i < vec.n; i++) {
            is >> x;
            vec.p.push_back(x);
        }
        return is;
    }

    ostream& operator<<(ostream& os, const MyVector& vec) {

        for (int i = 0; i < vec.n; ++i) {
            os << vec.p[i];
            os << ' ';
        }
        return os;
    }



void odin() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    MyVector v1(3);
    MyVector v3({1, 2.5, 3}, 3);
    infile >> v1;

    outfile << v3 << endl;
    // outfile << v2 << endl;

    infile.close();
    outfile.close();
    // vector<double> m1 = {1, 2, 3, 4.5, 7};
    // MyVector V1(m1, 5);
    // MyVector V2(m1, 5);
    // MyVector V3 = V1 + V2;
    // V3.print();
}
