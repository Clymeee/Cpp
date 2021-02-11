/////////////////////////////////////////////////////////////////
//                                                             //
//  BattleShipOne.cpp                                          //
//  Claudio Marchesini                                         //
//  4 December 2020                                            //
//  - Battleship war game between the user and the computer -  //
//                                                             //
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <time.h>
#include <random>
using namespace std;

//  HELP
//  0 = empty
//  1 = ship
//  2 = bomb
//  3 = strike

void play(){
    char r;
    cout<<"Benvenuto su BATTAGLIA NAVALE\n - Claudio Marchesini\n\nVuoi giocare?(S/N): ";
    cin>>r;
    while(r!='s'&&r!='n'){
        system("CLS");
        cout<<"Benvenuto su BATTAGLIA NAVALE\n - Claudio Marchesini\n\nRisposta non valida! Reinserisci\nVuoi giocare?(S/N): ";
        cin>>r;
    }
    if(r=='s'){
        system("CLS");
    } else {
    exit(0);
    };
}

void create(int v[], int g){
    for(int i=0; i<g; i++) {
        v[i]=0;
        int n=rand()%(g-1);
        srand(time(NULL));
        v[n]=1;
        v[n+1]=1;
    }
}

void print(int v[], int g){
    srand(time(NULL));
    cout<<"Benvenuto su BATTAGLIA NAVALE\n - Claudio Marchesini\n\n -----------------------------------------"<<endl;
    for(int i=0; i<g; i++){
        switch(v[i]){
            case 0:
                cout<<" | "<<"?";
                break;
            case 1:
                cout<<" | "<<"?";
                break;
            case 2:
                cout<<" | "<<" ";
                break;
            case 3:
                cout<<" | "<<"-";
                break;
        }
    }
    cout<<" |"<<endl<<" -----------------------------------------"<<endl;
}

void launch(int v[], int g){
    int p=-1;
    while(p<0||p>=g+1){
        cout<<"Inserisci le coordinate da bombardare (1..10): ";
        cin>>p;
        while(p<1||p>10){
            cout<<"Coordinate non valide! Reinserisci (1..10): ";
            cin>>p;
        }
        p--;
        system("CLS");
    }
    if(v[p]==0){
      v[p]=2;
    } else if(v[p]==1){
        v[p]=3;
    }
}

bool victory(int v[], int g){
    for(int i=0; i<g; i++){
        if(v[i]==1) return false;
    }
    return true;
}

int main() {
    int num_bomb=0;
    play();
    const int size=10; //Map size
    int map[size];
    create(map,size);
    print(map,size);
    while(true){
        num_bomb++;
        launch(map,size);
        print(map,size);
        if(victory(map,size)) {
            if(num_bomb<=2) cout<<"Che fortuna! ";
            if(num_bomb>2&&num_bomb<=5) cout<<"Bravo! ";
            if(num_bomb>5) cout<<"Che sfortunato! ";
            cout<<"Ci hai messo "<<num_bomb<<" tentativi";
            break;
        }
    }
    return 0;
}
