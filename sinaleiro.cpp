//Daniel Massataka Hara
//Projeto: Esquina com dois sinaleiros

#include<iostream>
#include<stdlib.h>
#include<thread>
#include<mutex>
#include<windows.h>
#include"sinaleiro.h"

//tempo dos sinais de trânsito variam de acordo com o fluxo de carros
//no meu programa irei fazer o sinal verde ficar ligado 7 segundos, o amarelo 3 segundos e o vermelho 10 segundos

using namespace std;

mutex m;//para a utilização de mutex
sinaleiro *s1=new sinaleiro();//criação da variável que representa a classe
sinaleiro *s2=new sinaleiro();//criação da segunda variável que representa a classe

void processo_sinaleiro(){//o ciclo completo dos sinais de trânsito dos dois sinaleiros
    m.lock();//regulando quantos processos serão realizados
        //primeria parte do sinal de trânsito
            cout<<"sinaleiro 1 esta:"<<endl;
            s1->estado_sinaleiro(1);//chamando o estado no qual esta o sinal de trânsito
            cout<<"sinaleiro 2 esta:"<<endl;
            s2->estado_sinaleiro(3);
            cout<<"----------------\n"<<endl;
            Sleep(7000);//tempo da primeira parte do ciclo do sinal de trânsito

            //segunda parte do sinal de trânsito
            cout<<"sinaleiro 1 esta:"<<endl;
            s1->estado_sinaleiro(2);
            cout<<"sinaleiro 2 esta:"<<endl;
            s2->estado_sinaleiro(3);
            cout<<"----------------\n"<<endl;
            Sleep(3000);

            //terceira parte do sinal de trânsito
            cout<<"sinaleiro 1 esta:"<<endl;
            s1->estado_sinaleiro(3);
            cout<<"sinaleiro 2 esta:"<<endl;
            s2->estado_sinaleiro(1);
            cout<<"----------------\n"<<endl;
            Sleep(7000);

            //quarta parte do sinal de trânsito
            cout<<"sinaleiro 1 esta:"<<endl;
            s1->estado_sinaleiro(3);
            cout<<"sinaleiro 2 esta:"<<endl;
            s2->estado_sinaleiro(2);
            cout<<"----------------\n"<<endl;
            Sleep(3000);
    m.unlock();//liberando o processo que estava sendo realizado
}

main(){

    int ini,cont;//ini pega a resposta do usario e cont conta a quantidade de ciclos

    cout<<"quer iniciar os sinaleiros?\n"<<"--------------------\n"<<endl;
    cout<<"digite 1 para SIM e digite 2 para NAO\n"<<"----------------\n"<<endl;
    cin>>ini;

    if(ini==1){
        cout<<"quantos ciclos irao ser\n"<<endl;
        cin>>cont;

        cout<<"----------------\n"<<endl;
        for(int x=0;x<cont;x++){

            thread sinal(processo_sinaleiro);//processo de passar a thread pela area protegida do mutex
            //o mutex pode regular outras threads
            sinal.join();// o thread sinal esta finalizando seu processo
        }
    }
    else{
       cout<<"o programa ira encerrar\n"<<endl;
    }
    system("pause");
    return 0;
}
