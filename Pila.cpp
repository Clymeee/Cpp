//
//  Pila.cpp
//  Claudio Marchesini
//  16 Dicembre 2021
//  FIFO (First In First Out)
//
#include <iostream>
#include <string>
using namespace std;

class Pila{
    public:
    string dati[100];
    int p=0;
    bool isEmpty(){
        return p==0;
    }
    void push(string parola){
        dati[p]=parola;
        p++;
    }
    string pop(){
        p--;
        return dati[p];
    }
};
int main(){
    Pila p;
    string parola;
    while(true){
        cout<<"Inserisci una parola: "<<endl;
        cin>>parola;
        if (parola=="Basta") break;
        p.push(parola);
    }
    while(!p.isEmpty()){
        cout<<p.pop()<<endl;
    }
    return 0;
}
