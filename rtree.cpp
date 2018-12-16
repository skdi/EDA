#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
using namespace std;
#define INF 99999

typedef pair<int,int> pari;
struct Area{
  vector<int> r;
  Area()
  {
    this->r=vector<int>(4,0);
  }
  Area (int a,int b,int c,int d){
    this->r=vector<int>(4);
    r[0]=a;//esquina inf izq
    r[1]=b;//esquina sup izq
    r[2]=c;//esquina inf der
    r[3]=d;//esquina sup der
  }
};


struct nodo{
  vector<nodo*> puntero;
  string nombre;
  Area area;
  bool flag;
  //nodo no-hoja
  nodo(string n,vector<nodo*> p,Area a)
  {
    this->nombre=n;
    this->puntero=p;
    this->flag=true;
    this->area=a;
  }
  nodo(){
    this->nombre="";
    this->flag=false;
  }
  //nodo hoja
  nodo(string n,Area a){
    this->nombre=n;
    this->area=a;
    this->flag=false;
  }
  bool es_nodo()
  {
    return this->flag;
  }
};

class rtree{
private:
  nodo *raiz;
  int m;
  int M;
public:
  rtree(nodo *r){
    this->raiz=r;
  }
  rtree(string n,vector<nodo*> p,Area a){
    raiz=new nodo(n,p,a);
  }
  bool es_nodo(){return this->raiz->flag;}
  bool se_solapan(Area a,Area b){
    //A solapa B
    if((a.r[0]>=b.r[0] && b.r[2]<=a.r[0]) && (a.r[1]>=b.r[1] && b.r[1]<=a.r[3]) )
      return true;
    else if((a.r[3]>=b.r[1] && b.r[3]>=a.r[3]) && (a.r[2]>=b.r[0] && b.r[2]>=a.r[2]))
      return true;
    else if((a.r[1]>=b.r[0] && b.r[1]>=a.r[1]) && (a.r[3]>=b.r[2] && b.r[3]>=a.r[3]) )
      return true;
    else if((a.r[0]>=b.r[0] && b.r[3]>=a.r[1]) && (a.r[2]>=b.r[2] && b.r[3]>=a.r[2]))
      return true;
    //B solapa A
    else if((a.r[0]<=b.r[0] && b.r[2]>=a.r[0]) && (a.r[1]<=b.r[1] && b.r[1]>=a.r[3]) )
      return true;
    else if((a.r[3]<=b.r[1] && b.r[3]<=a.r[3]) && (a.r[2]<=b.r[0] && b.r[2]<=a.r[2]))
      return true;
    else if((a.r[1]<=b.r[0] && b.r[1]<=a.r[1]) && (a.r[3]<=b.r[2] && b.r[3]<=a.r[3]) )
      return true;
    else if((a.r[0]<=b.r[0] && b.r[3]<=a.r[1]) && (a.r[2]<=b.r[2] && b.r[3]<=a.r[2]))
      return true;
    else return false;

  }
  bool hay_espacio(nodo *root){
    if(root->puntero.size()>=M)
      return false;
    else return true;
  }
  void insertar(nodo *root,Area a){
    nodo* nuevo=ChooseLeaf(root,a);
    if(hay_espacio(nuevo)){
      nuevo->puntero.push_back(new nodo("",a));
    }else{
      split_node(root);
    }

  }
  int calcular_area(Area a){
    int base,altura;
    base=abs(a.r[0]-a.r[2]);
    altura=abs(a.r[0]-a.r[1]);
    return base*altura;
  }
  Area Area_suma(Area a,Area b){
    int largoa1,largob1;
    int altoa1,altob1;
    Area suma;
    largoa1=abs(a.r[0]-a.r[1]);
    largob1=abs(b.r[0]-b.r[1]);
    altoa1=abs(a.r[0]-a.r[2]);
    altob1=abs(b.r[0]-b.r[2]);
    if(largoa1>largob1)
      suma.r[0]=a.r[0];
    else
      suma.r[0]=b.r[0];

    if(altoa1>altob1)
      suma.r[0]=a.r[1];
    else
      suma.r[0]=a.r[0];

  }
  pari PickSeed(nodo *root,int medio)
  {
    int d,aux=0;
    pari resultado;
    resultado.first=0;
    resultado.second=0;
    Area a1, a2;
    Area contenedor;
    for(int i=0;i<medio;i++)
    {
      for(int j=root->puntero.size();j>medio;j--)
      {
        contenedor=Area_suma(root->puntero[i]->area,root->puntero[j]->area);
        d=calcular_area(contenedor)-calcular_area(root->puntero[i]->area)-calcular_area(root->puntero[i]->area);
        if(aux<d)
        {
          aux=d;
          resultado.first=i;
          resultado.second=j;
        }
      }
    }
    
    return resultado;
  }



  AdjustTree(nodo *primero,nodo* segundo){
    nodo *N=primero;
    nodo *NN=segundo;
    while(N!=this->raiz){

    }
  }



  void PickNext(){

  }
  bool asignados(vector<nodo*> done){
    for(int i=0;i<done.size();i++){
      for(int j=0;j<done[i]->puntero.size();j++)
        if(done[i]->puntero[j]==NULL)
          return false;
    }
    return true;
  }
  void split_node(nodo *root)
  {
    int medio=(this->M+1/2);
    nodo* grupo1=new nodo();
    nodo* grupo2=new nodo();
    pari cabeza_grupo=PickSeed(root,medio);//first n second
    grupo1->puntero.push_back(root->puntero[pari.first]);
    grupo2->puntero.push_back(root->puntero[pari.second]);

    if(){
      root->puntero.clear();
      root->puntero.push_back(grupo1);
      root->puntero.push_back(grupo2);
      return root;
    }else{
      
    }




  }

  int MBR(Area a,Area b)
  {
    Area c;
    if(a.r[0]<b.r[0])
      c.r[0]=a.r[0];
    else
      c.r[0]=b.r[0];

    if(a.r[1]>b.r[1])
      c.r[1]=a.r[1];
    else
      c.r[1]=b.r[1];
    
    if(a.r[2]<b.r[2])
      c.r[2]=a.r[2];
    else
      c.r[2]=b.r[2];

    if(a.r[3]>b.r[3])
      c.r[3]=a.r[3];
    else
      c.r[3]=b.r[3];
    int a;
    a=(c.r[1]-c.r[2])*(c.r[3]-c.r[0])
    return a;
  }

  nodo* ChooseLeaf(nodo *root,Area a)
  {
    if(!root->es_nodo()){//si es hoja
      return root;
    }else{
      int min=INF,x=0;
      int aux;
      //buscamos el sub arbol que se expanda menos
      for(int i=0;i<root->puntero.size();i++){
        aux=MBR(root->puntero[i]->area,a);
        if(min>aux.first){
          min=aux.first;//valor minimo de mbr
          x=i;//direccion de ese valor minimo
        }
      }
      ChooseLeaf(root->puntero[x],a);
    }
  }
  vector<nodo*> buscar(nodo *root,Area S){
    vector<nodo*> resultado;
    if(root->es_nodo())
    {
      //sub arbol
      for(unsigned int i=0;i<root->puntero.size();i++)
      {
        if(se_solapan(S , root->puntero[i]->area))
        {
          buscar(root->puntero[i],S);
        } 
      }
    }
    else
    {//nodo hoja
      if(se_solapan(root->area,S))
        resultado.push_back(root);
    }
    return resultado;

  }
  void eliminar()
  {

  }
  ~rtree();


};


int main()
{
  return 0;
}



