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
	void eliminar(int valor);
	void imprimir();
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

void list::eliminar(int valor){
	node *aux=this->inicio;
	while(aux->va!=valor){
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
void list::imprimir(){
	node *aux=this->inicio;
		while(aux!=NULL){
			cout<<aux->va<<"<->";
			aux=aux->sig;
		}
		cout<<endl;
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
int main(){
	list *A=new list();
	A->insertar(1);
	A->insertar(2);
	A->insertar(5);
	A->insertar(7);
	A->imprimir();
	A->eliminar(5);
	A->imprimir();
	
	return 0;
}
