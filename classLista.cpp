//
//  classLista.cpp
//  Claudio Marchesini
//  5/2/21
//  Leggere e scrivere stringhe di una classe Lista
//

#include <iostream>
#include <time.h>
using namespace std;

class Lista{
private:
    int DIM,TOP;
    string* data;
public:
    Lista(int DIME){
        TOP=0;
        DIM=DIME;
        data = new string[DIME];
    }

    int random(){
        return rand()%10+1;
    }

    void add(string s){
        data[TOP]=s;
        TOP++;
    }

    void write(int N, string P){
        data[N-1]=P;
    }

    string read(int N){
        cout<<"La scritta nella cella "<<N-1<<" e' "<<data[N-1];
    }

    int size(){
        cout<<"La dimensione del vettore e' "<<DIM<<endl;
    }

    int print(){
        for(int i=0; i<DIM; i++){
            cout<<i+1<<") "<<data[i]<<endl;
        }
    }
};

int main() {
    srand(time(NULL));
    Lista v(100);
    for(int i=0; i<99; i++){
        v.add(string(rand()%10+1,'*'));
    }
    v.add("poggers");
    v.print();
    v.size();
    v.read(100);
    return 0;
}
