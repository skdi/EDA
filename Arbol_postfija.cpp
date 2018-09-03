#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct nodo{
	struct nodo *ant;
	struct nodo *sig;	
	char val;

	nodo(char v){
		val= v;
		sig= NULL;
		ant= NULL;
	}
};

void imprimir(nodo* v1)
{
	if(v1==NULL)
		return;
	else{
		imprimir(v1->ant);
		imprimir(v1->sig);
		cout<<v1->val<<" ";
		}
}

bool operador(char letra){
	if(letra=='+'||letra=='-'||letra=='*'||letra=='/')
		return true;
	else return false;
}

void arbolito(string expresion)
{
	stack<nodo *> pila;
	for(unsigned i= 0 ; i <expresion.size(); i++)
	{
		if(!operador(expresion[i]))//si es un operando
		{
			pila.push(new nodo(expresion[i]));

		}
		else{

			nodo aux(expresion[i]);
			aux.ant=pila.top();
			pila.pop();
			aux.sig=pila.top();
			pila.pop();
			pila.push(new nodo(aux.val));
			pila.top()->ant=aux.sig;
			pila.top()->sig=aux.ant;
			imprimir(pila.top());
			cout<<endl;
		}
	
	}
	cout<<endl;
	cout<<"RESULTADO FINAL: "<<endl;
	imprimir(pila.top());
	cout<<endl;
}


int main()
{
	string cadena="ab+cde+**";
	cout<<"cadena original "<<cadena<<endl;
	arbolito(cadena);
	return 0;
}


