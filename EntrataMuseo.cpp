//Creatore del File: Claudio Marchesini, 3CIN

#include <iostream>
using namespace std;

int main()
{
	int P;
	float C,R;
	
	cout<<"Costo del biglietto: ";
	do {
		cin>>C;
		if(C<0) {
			cout<<"Prezzo non valido, reinserisci: ";
		}
	} while(C<0);
	
	cout<<"\nChi sei?\n\n\t1) Studente\n\t2) Pensionato\n\t3) Residente\n\t4) Portatore di Handicap\n\t5) Visitatore\n\n";
	do {
		cin>>P;
		if(P<1||P>5) {
			cout<<"Non e' un'opzione valida, reinserisci: ";
		}
	} while(P<1||P>5);
	
	switch(P) {
		case 1:
			R=(C*50)/100;
			cout<<"\nCome STUDENTE, hai uno sconto del 50%"<<endl<<"Il tuo prezzo e' di "<<R<<" euro";
			break;
		case 2:
			R=(C*70)/100;
			cout<<"\nCome PENSIONATO, hai uno sconto del 30%"<<endl<<"Il tuo prezzo e' di "<<R<<" euro";
			break;
		case 3:
			R=(C*75)/100;
			cout<<"\nCome RESIDENTE, hai uno sconto del 25%"<<endl<<"Il tuo prezzo e' di "<<R<<" euro";
			break;
		case 4:
			cout<<"\nCome PORTATORE DI HANDICAP, hai l'entrata LIBERA";
			break;
		case 5:
			cout<<"\nCome VISITATORE, paghi prezzo PIENO"<<endl<<"Il tuo prezzo e' di "<<R<<" euro";
			break;
	}

	return 0;
}

