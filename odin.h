//
// Created by USER on 18.10.2026.
//

#ifndef LABA2_ODIN_H
#define LABA2_ODIN_H
#include <iosfwd>
#include <vector>

using namespace std;

void odin();
class MyVector {
    public:
    int n;
    std::vector<double> p;
    MyVector(vector<double> p, int n);
    MyVector(int n);
    MyVector(const MyVector & V);
    ~MyVector();
    MyVector(MyVector &&V);
    MyVector();
    double &operator [](int index);
    MyVector &operator =(const MyVector &v2);
    MyVector &operator =(MyVector &&v2);
    MyVector operator +(MyVector &&v1);
    friend istream& operator>>(istream& is, MyVector &vec);
    friend ostream& operator<<(ostream& os, const MyVector &vec);
};

#endif //LABA2_ODIN_H
