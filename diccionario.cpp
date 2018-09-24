#include <iostream>
#include <vector>
#include <math.h>
#include "haash.h"
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
        for(int i=0;i<vec.size();i++){//vec ocupado
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
                suma+=j*i;
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
    string palabra;
    haashmap *diccionario= new haashmap();
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
        palabra=frecuencia.front().first;
        diccionario->put(obtener_key(palabra),palabra);
    }
    return diccionario;
}

void detectar(haashmap *dic){
    string n_palabra,o_palabra;
    int val;
    while(n_palabra!="EOF"){
        cin>>n_palabra;
        val=obtener_key(n_palabra);
        o_palabra=dic->get(val);
        if(o_palabra!=n_palabra){
            cout<<"Error palabra mal escrita";
            break;
        }
    }

}

int main(){

    string texto_plano="texto.txt";
    haashmap *diccionario=crear_diccionario(texto_plano);
    detectar(diccionario);
    return 0;

}
