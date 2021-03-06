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
void preorder(nodo *raiz){
  //imprimimos raiz
  if(raiz==NULL)
    return;
  
    cout<<raiz->val<<"  ";
    preorder(raiz->hijo);
    preorder(raiz->hermano);
  
}
void inorder(nodo *raiz){
  //imprimimos raiz
  if(raiz==NULL)
    return;
  
    
    inorder(raiz->hijo);
    cout<<raiz->val<<"  ";
    inorder(raiz->hermano);
  
}
void postorder(nodo *raiz){
  //imprimimos raiz
  if(raiz==NULL)
    return;
  
    postorder(raiz->hijo);
    postorder(raiz->hermano);
    cout<<raiz->val<<"  ";
  
}



int main(){
  nodo *padre=new nodo('a');
  insertar_hijo(padre,'b');
  insertar_hermano(padre->hijo,'c');
  insertar_hermano(padre->hijo,'d');
  insertar_hijo(padre->hijo->hermano,'e');
  insertar_hijo(padre->hijo->hermano,'f');
  insertar_hijo(padre->hijo->hermano->hermano,'g');
  insertar_hijo(padre->hijo->hermano->hermano->hijo,'h');
  insertar_hermano(padre->hijo->hermano->hermano->hijo,'i');
  insertar_hermano(padre->hijo->hermano->hermano->hijo,'j');
  insertar_hermano(padre->hijo->hermano->hermano->hijo,'k');
  cout<<"inorder:"<<endl;
  preorder(padre);
  cout<<"postorder:"<<endl;
  postorder(padre);
  cout<<"preorder:"<<endl;
  preorder(padre);



  return 0;
}
