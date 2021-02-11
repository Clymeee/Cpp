//
//  MedieStudenti.cpp
//  Claudio Marchesini
//  29/01/21
//  Calcolare le varie medie richieste di un numero N di studenti di una classe usando le matrici
//

#include <iostream>
#include <time.h>
using namespace std;

//////////////////
//              //
//   FUNZIONI   //
//              //
//////////////////

//Randomizzatore
int random(){
    int r=(rand()%10)+1;
}

//Creazione della matrice
void create(int v[1][5], int N){
    srand(time(NULL));
    for (int a=0; a<N; a++){
        for (int b=0; b<5; b++){
            v[a][b]=random();
            while (v[a][b]<2) v[a][b]=random();
        }
    }
}

//Stampare la matrice
void print(int v[1][5], int N){
    int i=1;
    cout<<"\t\t|M.1\t|M.2\t|M.3\t|M.4\t|M.5\t|"<<endl;
    for(int a=0; a<N; a++){
        cout<<"---------------------------------------------------------"<<endl<<"Studente "<<i<<"\t|";
        for(int b=0; b<5; b++){
            cout<<v[a][b]<<"\t|";
        }
        i++;
        cout<<endl;
    }
    cout<<"---------------------------------------------------------"<<endl;
}

//Media totale degli studenti
float mediaTotale(int v[1][5], float N){
    int S=0;
    float R;
    for(int a=0; a<N; a++){
        for(int b=0; b<5; b++){
            S=S+v[a][b];
        }
    }
    R=S/(N*5);
    cout<<"La media della classe e' "<<R<<endl;
}

//Media a seconda della materia
float mediaMateria(int v[1][5], float N){
    int S=0,M;
    float R;
    cout<<"\n\nInserisci la materia della quale tu vuoi fare la media: ";
    cin>>M;
    while(M<1||M>5){
        cout<<"Materia non esistente! Reinserisci: ";
        cin>>M;
    }
    M--;
    for(int a=0; a<N; a++){
        S=S+v[a][M];
    }
    R=S/N;
    cout<<R<<endl;
}

//Media a seconda dello studente
float mediaStudente(int v[1][5], float N){
    int S=0,A;
    float R;
    cout<<"Inserisci lo studente della quale tu vuoi fare la media: ";
    cin>>A;
    while(A<1||A>N){
        cout<<"Studente non esistente! Reinserisci: ";
        cin>>A;
    }
    A--;
    for(int a=0; a<N; a++){
        S=S+v[A][a];
    }
    R=S/N;
    cout<<R<<endl;
}

//Studenti sopra la media della classe
float mediaSuperiore(int v[1][5], int N){
    const int N1=N;
    int i=0,Up=0;
    float Rt,V[N],S=0,St=0;

    for(int x=0; x<N; x++){
        for(int y=0; y<5; y++){
            St=St+v[x][y];
        }
    }
    Rt=St/(N*5);

    do{
        for(int a=0; a<N; a++){
            S=S+v[i][a];
        }
        V[i]=S/N;
        S=0;
        if(V[i]>Rt) Up++;
        i++;
    }while(i<N);
    cout<<"Gli studenti che hanno una media superiore alla media totale della classe sono "<<Up;
}

//////////////
//          //
//   MAIN   //
//          //
//////////////

int main(){
    int N;
    cout<<"Quanti studenti sono presenti nella classe? ";
    cin>>N;
    int v[N][5];
    system("CLS");

    create(v,N);
    print(v,N);
    mediaTotale(v,N);
    mediaSuperiore(v,N);
    mediaMateria(v,N);
    mediaStudente(v,N);

	return 0;
}
