//
// Created by USER on 15.10.2026.
//
#include <iostream>
#include "vtoroi.h"


class Shkola {
    std::string name;
    protected: int  chislo;

    public:
    Shkola(std::string name, int chislo) {
        this->chislo = chislo; this->name = name;
        std::cout<<'1'<<std::endl;
    };
    void print(){ std::cout << "name - " << this->name << "\nchislo uchenikov - " << this->chislo <<std::endl;};

};

class Spec_shkola: public Shkola {
    std::string specializaciya;
    public:
    Spec_shkola(std::string name, std::string specializaciya, int chislo):
        Shkola(name, chislo){
        this->specializaciya = specializaciya;
        std::cout<<'2'<<std::endl;
    }
    void print() {
        Shkola::print();
        std::cout<<"uklon - "<< specializaciya <<std::endl;
    }
};


void nomer_2() {
    Shkola shkola = Shkola("zhizni", 1024);
    shkola.print();
    Spec_shkola spec_shkola = Spec_shkola("os`", "gumannaya", 1024);
    spec_shkola.print();
}