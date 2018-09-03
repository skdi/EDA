#include <graphviz/gvc.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct nodo{
  char val;
  nodo *hijo;
  nodo *hermano;
  nodo *padre;
  nodo(char va){
    hijo=NULL;
    hermano=NULL;
    padre=NULL;
    val=va;
  }
};

void insertar_hijo(nodo *raiz,char valor){
  nodo *aux;
  aux=raiz->hijo;
  nodo *hij=new nodo(valor);

  if(aux==NULL){    
    hij->padre=raiz;
    raiz->hijo=hij;    
  }
  else{
    while(aux->hermano!=NULL)
      aux=aux->hermano;
    
    aux->hermano=hij;
    hij->padre=raiz;
  }
}
void insertar_hermano(nodo *hijo,char valor){
  nodo *aux;
  aux=hijo->hermano;
  nodo *hij=new nodo(valor);
  if(aux==NULL){
    aux->hermano=hij;  
    hij->padre=hijo->padre;  
  }
  else{
    while(aux->hermano!=NULL)
      aux=aux->hermano;  

    aux->hermano=hij;
    hij->padre=hijo->padre; 
  }
}
void inorder(nodo *raiz){
  //imprimimos raiz
  if(raiz==NULL)
    return;
  
    cout<<raiz->val<<"  ";
    inorder(raiz->hijo);
    inorder(raiz->hermano);
  
}


int main(){
  nodo *padre=new nodo('a');
  insertar_hijo(padre,'b');
  insertar_hijo(padre,'c');
  insertar_hermano(padre->hijo,'d');
  inorder(padre);



  return 0;
}
