#include <iostream>
#include <string.h>
using namespace std;
struct electronica{
	char agregar[15];
	char ubicacion[2];
	int stockActual;
	
	int stockMinimo;
	struct electronica *p_sig;
};
void cargar(struct electronica *&p);
void buscar(struct electronica *p);
void menor(struct electronica *p);
void stock(struct electronica *p);
void todosStock(struct electronica *p);
int main(int argc, char *argv[]) {
	char selec;
	struct electronica *p=NULL;

	do{
		cout<<"1-agregar un componente"<<endl;
		cout<<"2-en que sitio se encuentra un componente"<<endl;
		cout<<"3-stock"<<endl;
		cout<<"4-componentes con stock menor al minimo"<<endl;
		cout<<"5-listar todos los componentes con su stock"<<endl;
		cout<<"s-salir"<<endl;
		cin>>selec;
		switch(selec){
		case '1':
			cargar(p);
			
			break;
		case '2':
			buscar(p);
			break;
		case '3':
			stock(p);
			break;
		case '4':
			menor(p);
			
			break;
		case '5':
			todosStock(p);
			break;
		default:
			if(selec!='s')
			cout<<"error, reingrese"<<endl;
		}
	}while(selec!='s');
	
	return 0;
}

void cargar(struct electronica *&p){
	struct electronica *nuevo=new struct electronica();
	
	cout<<"componente:"<<endl;
	cin>>nuevo->agregar;
	cout<<"ubicacion:"<<endl;
	cin>>nuevo->ubicacion;
	cout<<"stock actual:"<<endl;
	cin>>nuevo->stockActual;
	cout<<"stock minimo:"<<endl;
	cin>>nuevo->stockMinimo;
	struct electronica *aux1=p;
	p=nuevo;
	nuevo->p_sig=aux1;
	
}

void buscar(struct electronica *p){
	char buscar[15];
	cout<<"escriba el componente a buscar"<<endl;
	cin>>buscar;
	struct electronica *actual=new struct electronica();
	actual=p;
		while(actual!=NULL){
			if(strcmp(actual->agregar,buscar) == 0)
				cout<<"la ubicacion es "<<actual->ubicacion<<endl;
			actual=actual->p_sig;
		}
}

void stock(struct electronica *p){
	char buscar[15];
	cout<<"escriba el componente para saber el stock"<<endl;
	cin>>buscar;
	struct electronica *actual=new struct electronica();
	actual=p;
	while(actual!=NULL){
		if(strcmp(actual->agregar,buscar) == 0)
			cout<<"la stock es "<<actual->stockActual<<endl;
		actual=actual->p_sig;
		
	}
}

void menor(struct electronica *p){
	struct electronica *actual=new struct electronica();
	actual=p;
	while(actual!=NULL){
		if((actual->stockActual)<(actual->stockMinimo))
			cout<<"el componente "<<actual->agregar<<" tiene menor stock que el minimo"<<endl;
	actual=actual->p_sig;
	}
}

void todosStock(struct electronica *p){
	struct electronica *actual=new struct electronica();
	actual=p;
	while(actual!=NULL){
		cout<<actual->agregar<<"  "<<actual->stockActual<<endl;
		actual=actual->p_sig;
	}
}
