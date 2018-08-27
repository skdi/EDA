#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
#define n 10
struct node{
	node* sig;
	node* ant;
	int va;
	node(int a)
	{
		sig=NULL;
		ant=NULL;
		va=a;
	}
};
class list{
public:
	list();
	int tam=0;
	node* inicio;
	node* fin;
	void insertar(int va);
	void eliminar(node *valor);
};

list::list(){
	inicio=NULL;
	fin=NULL;
}
void list::insertar(int va){
	node* nuevo=new node(va);
	if(this->inicio==NULL){
		this->inicio=nuevo;
		this->fin=nuevo;
	}
	else{
		node* aux=this->inicio;
		while(aux->sig!=NULL)
		{
			aux=aux->sig;
		}
		aux->sig=nuevo;
		nuevo->ant=aux;
		nuevo->sig=NULL;
		this->fin=nuevo;
	}
	tam++;
}

void list::eliminar(node *valor){
	node *aux=this->inicio;
	while(aux!=valor){
		aux=aux->sig;
	}
	if(aux==inicio){

        if(inicio->sig==NULL){
            inicio=NULL;
            fin=NULL;
            delete aux;
        }
        else{
            inicio=inicio->sig;
            delete aux;
        }
    }
    else if(aux==fin){
        fin=fin->ant;
        fin->sig=NULL;
        delete aux;
    }
    else{
        aux->ant->sig=aux->sig;
        aux->sig->ant=aux->ant;
        delete aux;
    }
    tam--;
}
int max_element(int A[n]){
	int max=A[0];
	for(int i=1;i<n;i++){
		if(max<A[i])
			max=A[i];
	}
	return max;
}

void imprimir(list A[n])
{
    node * aux;
	for(int i=0;i<n;i++){
		aux=A[i].inicio;
		while(aux!=NULL){
			cout<<aux->va<<" ";
			aux=aux->sig;
		}
		
	}
	cout<<endl;

}
int elevar(int base,int poten){
    int res=base;
    for(int i=0;i<poten-1;i++){
        res=res*base;
    }
    return res;
}
int* cubeta(int A[n]){
	list cubeta[n];
	int max,tam,pos,tamCubeta;
	node * aux;
	node* aux2;
	max=max_element(A);
	string b=to_string(max);
	tam=b.length();
	for(int i=0;i<n;i++){
        pos=A[i]%10;
        cubeta[pos].insertar(A[i]);
    }
	for(int i=1;i<tam;i++){

        for(int j=0;j<n;j++){

            aux=cubeta[j].inicio;
            tamCubeta=cubeta[j].tam;
            int cont=0;
            while(aux!=NULL && cont<tamCubeta){
            	
                cont++;
                int va=aux->va;
                pos=(va%(elevar(10,i+1)))/elevar(10,i);
                aux2=aux;
                aux=aux->sig;
                cubeta[j].eliminar(aux2);
                cubeta[pos].insertar(va);
            }
        }
    }
    imprimir(cubeta);
}

int main(){
	int A[n]={64,8,216,512,27,729,0,1,343,125};
	cubeta(A);
	return 0;
}
