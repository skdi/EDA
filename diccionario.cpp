#include <iostream>
#include <vector>
#include <math.h>
#include "hash.h"
#include <string>
#include <fstream>
using namespace std;
#define n 10

typedef pair<string,int> par;
typedef vector<par> vpar;
typedef pair<bool,int> bpar;
ifstream texto_plano;
string abc="abcdefghijklmnñopqrstuvwxyz";

bpar comprobar_vector(vpar vec,string part){
	bpar aux;
	aux.first=false;
	aux.second=-1;
	if(vec.empty())//vec vacio
		return aux;
	else{
		for(unsigned i=0;i<vec.size();i++){//vec ocupado
			if(vec[i].first==part){//encontrado
				aux.first=true;
				aux.second=i;
				return aux;
			}
		}
		return aux;
	}
}
/*
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
*/

int obtener_key(string cadena){
	int suma=0;
	for(int i=0;i<cadena.length();i++){
		for(int j=0;j<abc.length();j++){
			if(cadena[i]==abc[j])
				suma+=j;
		}
		
	}
	return suma;

}

haashmap *crear_diccionario(string nombre){
	texto_plano.open(nombre);
	char* linea=new char[10000];
	string lineaS;
	vpar frecuencia;
	bpar baux;
	par paraux;
	while(!texto_plano.eof()){
		texto_plano.getline(linea,10000,' ');
		lineaS=string(linea);
		baux=comprobar_vector(frecuencia,lineaS);
		if(!baux.first){//si no esta en el vector
			paraux.first=lineaS;
			paraux.second=0;
			frecuencia.push_back(paraux);
		}
	}
	for(int i=0;i<frecuencia.size();i++){
		

	}

}


int main(){
	

	return 0;
}
