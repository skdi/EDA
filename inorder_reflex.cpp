#include <iostream>
#include <stack>
using namespace std;

struct nodo{
	nodo* izq;
	nodo* der;
	int val;
	nodo (){
		izq=NULL;
		der=NULL;
	}
	nodo(int valor){
		val=valor;
		izq=NULL;
		der=NULL;
	}
};

void inorden(nodo *raiz){
	stack<nodo *> pila;
	nodo *aux;
	pila.push(raiz);
	aux=pila.top();
	while(!pila.empty()){		
		while(aux->izq!=NULL){
			pila.push(aux->izq);
			aux=aux->izq;
		}
		cout<<aux->val;
		pila.pop();
		if(!pila.empty()){
			aux=pila.top();
			cout<<aux->val;
			pila.pop();
		}		
			
		if(aux->der!=NULL){
			pila.push(aux->der);
			aux=aux->der;
		}
	}
}

void reflexion(nodo *raiz,nodo *temp){
	if(raiz->der!=NULL && raiz->izq!=NULL){
		temp->der=new nodo(raiz->izq->val);
		temp->izq=new nodo(raiz->der->val);
		temp->val=raiz->val;
		reflexion(raiz->der,temp->izq);
		reflexion(raiz->izq,temp->der);

	}else return;
}

int main(){
	nodo *reflex=new nodo();
	nodo *raiz=new nodo(5);
	raiz->izq=new nodo(3);
	raiz->der=new nodo(7);
	raiz->izq->izq=new nodo(1);
	raiz->izq->der=new nodo(4);
	inorden(raiz);
	cout<<endl;
	reflexion(raiz,reflex);
	inorden(reflex);
	return 0;
}
