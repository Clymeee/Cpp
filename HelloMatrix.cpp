//
//  HelloMatrix.cpp
//  Claudio Marchesini
//  18 Dicembre 2020
//  Riempire una tavola pitagorica con una matrice e sommarne i valori
//

#include <iostream>
#include <time.h>
using namespace std;

void fill(int v[11][11]){
    for(int a=0; a<10; a++){
        int random=(rand()%10)+1;
        v[a][0]=random;
    }
}

int calculate(int v[11][11]){
    for(int a=0; a<10; a++){
        int n=0;
        for(int b=10; b>0; b--){
            v[a][b]=v[a][0]*v[n][0];
            n++;
        }
    }
}

void print(int v[11][11]) {
    cout<<"-----------------------------------------------------------------------------------------\n|\t|";
    for(int i=0; i<10; i++){
        cout<<v[i][0]<<"\t|";
    }
    cout<<"\n-----------------------------------------------------------------------------------------\n";
    for(int a=0; a<10; a++){
        cout<<"|"<<v[a][0]<<"\t|";
        for(int b=10; b>0; b--){
            cout<<v[a][b]<<"\t|";
        }
        cout<<"\n-----------------------------------------------------------------------------------------\n";
    }
}

void total(int v[11][11], int X){
    int r=0;
    for(int a=1; a<11; a++){
        r=r+v[X-1][a];
    }
    cout<<endl<<r;
}

int main() {
    srand(time(NULL));
    int X;
    int v[11][11];

    cout<<"TAVOLA PITAGORICA\n- Claudio Marchesini\n";
    fill(v);
    calculate(v);
    print(v);
    cout<<"\nQuale riga vorresti sommare?(1..10): ";
    cin>>X;
    while(X<1||X>10){
        system("CLS");
        cout<<"TAVOLA PITAGORICA\n- Claudio Marchesini\n";
        print(v);
        cout<<"\nNumero non valido! Reinseriscilo\nQuale riga vorresti sommare?(1..10): ";
        cin>>X;
    }
    total(v,X);

    return 0;
}
