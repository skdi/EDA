#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
#define n 10
struct node
{
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
class list
{
public:
	list();
	node* inicio;
	node* fin;
	void insertar(int va);
	void eliminar(node *valor);
};
list::list()
{
	inicio=NULL;
	fin=NULL;
}
void list::insertar(int va){
	node* nuevo=new node(va);
	if(this->inicio==NULL)
	{
		this->inicio=nuevo;
		this->fin=nuevo;
	}
	else
	{
		node* aux=this->inicio;
		while(aux->sig!=NULL)
		{
			aux=aux->sig;
		}
		aux->sig=nuevo;
		nuevo->ant=aux;
		this->fin=nuevo;
	}
}

void list::eliminar(node *valor){
	node *aux=this->inicio;
	while(aux!=valor){
		aux=aux->sig;
	}
	aux->ant->sig=aux->sig;
	aux->sig->ant=aux->ant;
	delete aux;
}
int max_element(int A[n]){
	int max=A[0];
	for(int i=1;i<n;i++){
		if(max<A[i])
			max=A[i];
	}
	return max;
}

void imprimir(list A[n]){
	for(int i=0;i<n;i++){
		node *aux=A[i].inicio;
		while(aux!=NULL){
			cout<<aux->va<<"<->";
			aux=aux->sig;
		}
		cout<<endl;
	}

}

int* cubeta(int A[n]){
	list cubeta[n];
	int mod,aux,max;
	max=max_element(A);
	string b=to_string(max);
	mod=10;
	for(int j=0;j<n;j++){
			aux=A[j]%mod;
			cubeta[aux].insertar(A[j]);
	}
	imprimir(cubeta);
	for(int i=0;i<n;i++){
		mod=pow(10,i);
		node* aux=cubeta[i].inicio;
		while(aux!=NULL)
		{
			
		}
	}
}



int main(){
	int A[n]={64,8,216,512,27,729,0,1,343,125};
	cubeta(A);
	return 0;
}
