#ifndef SINALEIRO_H_INCLUDED
#define SINALEIRO_H_INCLUDED
#include<iostream>
#include<stdlib.h>

using namespace std;

class sinaleiro{
public:
    void estado_sinaleiro(int tp);

};

void sinaleiro::estado_sinaleiro(int tp){
    switch(tp){
        case 1:
            cout<<"VERDE"<<endl;
            break;
        case 2:
            cout<<"AMARELO"<<endl;
            break;
        case 3:
            cout<<"VERMELHO"<<endl;
            break;
        default:
            cout<<"valor errado"<<endl;
    }
}

#endif // SINALEIRO_H_INCLUDED
