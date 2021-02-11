//
//	IndovinaIlNumero.cpp
//	Claudio Marchesini
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int random() {
	srand(time(NULL));
	return (rand()%10)+1;
}
int main() {
	int x,r,n,i=0;
	n=random();
	cout<<n;
	do {
		cout<<endl<<"Inserisci un numero che va da 0 a 10: ";
		cin>>x;
		while(x<0||x>10) {
			cout<<"Numero non valido, reinseriscilo: ";
			cin>>x;
		}
		if(x==n) {
			cout<<"Hai indovinato!";
			//break;
		} else {
			cout<<"Hai sbagliato! ";
			i++;
			if(i==3) {
				cout<<"Hai finito i tentivi!";
				break;
			}
			r=3-i;
			cout<<"Hai ancora "<<r<<" tentativi";
		}
	} while(x!=n);

	return 0;
}
