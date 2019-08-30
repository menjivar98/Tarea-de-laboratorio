#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
};

void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&m ,int &);

int main(){
	
	Nodo * par = NULL;
	Nodo * impar =  NULL;
	int dato,aux1, aux2;
	char rpt;
	do{
		
		cout<<"\nDigite un numero: ";
		cin>>dato;
		if(dato % 2 == 0){
			cout<<"\tEl numero es par. "<<endl;
			agregarPila(par,dato);
		}else{
			cout<<"El numero es impar. "<<endl;
			agregarPila(impar,dato);
		}
		
		cout<<"Deseas agregar otro? (s/n): ";
		cin>>rpt;
			
	}while((rpt == 'S') || (rpt == 's'));
	
	cout<<"\nSacando todos los datos de pila par: ";
	while(par != NULL){
		sacarPila(par,dato);
		if(par != NULL){
			cout<<dato<<" , ";
			aux1++;
		}else{
			cout<<dato<<"."<<endl;
			aux1++;
			
		}
	};
	
	cout<<"\nSacando todos los datos de pila impar ";
	while(impar != NULL){
		sacarPila(impar,dato);
		if(impar != NULL){
			cout<<dato<<" , ";
			aux2 ++;
		}else{
			cout<<dato<<"."<<endl;
			aux2++;
		}
	}
	
	if(aux1 > aux2)
	    cout<<"\nLa pila par tenia mas datos";
	 else
	    cout<<"\nLa pila impar tenia mas datos";
	
	
	getch();
	return 0;
	
}

void agregarPila(Nodo *&pila, int n){
	Nodo * nuevo_nodo =  new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->sig= pila;
	pila = nuevo_nodo;
	
	cout<<"El elemento " << n << " Ha sido agregado a pila"<<endl;
}

void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->sig;
	delete(aux);
}