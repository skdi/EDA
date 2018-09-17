#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <stack>
using namespace std;

typedef pair<char,int> par;
typedef vector<par> vpar;
typedef pair<bool,int> bpar;

struct nodo{
	char valor;
	int frecu;
	nodo *izq;
	nodo *der;
	nodo(){
		frecu=0;
		izq=NULL;
		der=NULL;
	}
	nodo(int fre){
		frecu=fre;
		izq=NULL;
		der=NULL;
	}
	nodo(char val,int fre){
		valor=val;
		frecu=fre;
		izq=NULL;
		der=NULL;
	}
};
void sort_nodo(vector<nodo*> &A)
{
	for(int i=0;i<A.size();i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(A[j]->frecu<=A[j+1]->frecu)
				break;
			swap(A[j],A[j+1]);
		}
	}
}
void imprimir_arbol(nodo* A){
	if(A!=NULL){
		cout<<A->valor;
		imprimir_arbol(A->izq);
		imprimir_arbol(A->der);
	}
	else{
		return;
	} 

}
void imprimir2(vector<nodo*> A)
{
	for(int i=0;i<A.size();i++)
	{
		cout<<A[i]->frecu<<"<->";
	}
	cout<<endl;
}



bpar comprobar_vector(vpar vec,par part){
	bpar aux;
	aux.first=false;
	aux.second=-1;
	if(vec.empty())//vec vacio
		return aux;
	else{
		for(unsigned i=0;i<vec.size();i++){//vec ocupado
			if(vec[i].first==part.first){//encontrado
				aux.first=true;
				aux.second=i;
				return aux;
			}
		}
		return aux;
	}
}
vpar obtener_frecu(string cadena){
	par aux;
	bpar baux;
	vpar frecuencia;
	for(unsigned i=0;i<cadena.length();i++){
		aux.first=cadena[i];
		baux=comprobar_vector(frecuencia,aux);
		if(!baux.first){//si no esta el elemento en el vector
			aux.second=1;
			frecuencia.push_back(aux);
		}else{//si ,si esta
			frecuencia[baux.second].second+=1;
		}
	}
	return frecuencia;
}
void imprimir(vpar vec){
	for(unsigned i=0;i<vec.size();i++){
		cout<<vec[i].first<<"-"<<vec[i].second<<endl;
	}
}
void sort_frecu(vpar &vec){
	for(int i=0;i<vec.size();i++){
		for(int j=i-1;j>=0;j--){
			if(vec[j].second<=vec[j+1].second)
				break;
			swap(vec[j],vec[j+1]);
		}
	}
}

nodo* huffman(string cadena){

	vpar frecu=obtener_frecu(cadena);
	vector<nodo*> tree;
	nodo *aux;
	sort_frecu(frecu);
	//inicializamos un arbol de frecuencias de las cadenas
	for(int i=0;i<frecu.size();i++){
		tree.push_back(new nodo(frecu[i].first,frecu[i].second));
	} 
	while(tree.size()>2){
		aux=new nodo(tree[0]->frecu+tree[1]->frecu);
		aux->izq=tree[0];
		aux->der=tree[1];
		tree[0]=aux;
		tree.erase(tree.begin()+1);
		sort_nodo(tree);
		imprimir2(tree);
	} 
	aux=new nodo();
	aux->izq=tree[0];
	aux->der=tree[1];
	tree[0]=aux;
	tree.erase(tree.begin()+1);
	imprimir_arbol(tree[0]);
	return tree[0];

}

string buscar(char a,string &aux,nodo *arbol){
	if(arbol->valor==a )
		return aux;
	else{
		if(arbol->izq->valor!=a && arbol->izq!=NULL &&arbol->der!=NULL){
			aux+='0';
			cout<<aux<<endl;
			buscar(a,aux,arbol->izq);
			buscar(a,aux,arbol->der);
		}
		if(arbol->der->valor!=a && arbol->der!=NULL && arbol->der!=NULL){
			aux+='1';
			cout<<aux<<endl;
			buscar(a,aux,arbol->izq);
			buscar(a,aux,arbol->der);
		}
	}

}
void obtener_codigo(string cadena,nodo *arbol){ 
	string resultado="",aux="";
	for(int i=0;i<cadena.length();i++){
		resultado+=buscar(cadena[i],aux,arbol);
		cout<<resultado<<endl;
		aux="";
	}
	cout<<resultado;

}


int main(){
	string cadena="A caballo regalado no se le mira los dientes";
	/*vpar aux;
	aux=obtener_frecu(cadena);
	sort_frecu(aux);
	imprimir(aux);*/

	obtener_codigo(cadena,huffman(cadena));
	return 0;
}
