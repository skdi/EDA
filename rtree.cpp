#include <iostream>
#include <vector>
#include <utility>

using namespace std;
#define INF 99999

typedef pair<int,int> pari;
struct Area{
  vector<int> r;
  Area (int a,int b,int c,int d){
    r.push_back(a);//esquina inf izq
    r.push_back(b);//esquina sup izq
    r.push_back(c);//esquina inf der
    r.push_back(d);//esquina sup der
  }
};


struct nodo{
  vector<nodo*> puntero;
  string nombre;
  Area area;
  bool flag;
  //nodo no-hoja
  nodo(string n,vector<nodo*> p,Area a){
    this->nombre=n;
    this->puntero=p;
    this->flag=true;
    this->area=a;
  }
  //nodo hoja
  nodo(string n,Area a){
    this->nombre=n;
    this->area=a;
    this->flag=false;
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
    raiz=new nodo(string n,vector<nodo*> p,a);
  }
  bool es_nodo(){return this->flag;}
  bool se_solapan(Area a,Area b){
    if((a.r[0]<b.r[0] && b.r[0]<a.r[2]) )
      return true;
    if((b.r[0]<a.r[0] && a.r[0]<b.r[2]))
      return true;
    if((a.r[1]<b.r[1] && b.r[1]<a.r[3]) )
      return true;
    if((b.r[1]<a.r[1] && a.r[1]<b.r[3]))
      return true;
    else return false;

  }
  bool hay_espacio(nodo *root){
    if(root->puntero.size()>=M)
      return false;
    else return true;
  }
  void insertar(nodo *root,Area a){
    nodo nuevo=ChooseLeaf(root,a);
    if(hay_espacio(nuevo)){
      nuevo->puntero.push_back(new nodo("",a));
    }else{
      split_node(root);
    }

  }
  int calcular_area(Area a){
    int base,altura;
    base=abs(a[0]-a[2]);
    altura=abs(a[0]-a[1]);
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
  pari PickSeed(nodo *root,int medio){
    int d,aux=0;
    pari resultado;
    resultado.first=0;
    resultado.second=0;
    Area a1,Area a2
    Area contenedor;
    for(int i=0;i<medio;i++){
      for(int j=root->puntero.size();j>medio;j--){
        contenedor=Area_suma(root->puntero[i]->Area,root->puntero[j]->Area)
        d=calcular_area(contenedor)-calcular_area(root->puntero[i])-calcular_area(root->puntero[i]);
        if(aux<d){
          aux=d;
          resultado.first=i;
          resultado.second=j;
        }
    }
    
    return resultado;
  }
  void PickNext(){

  }
  void split_node(nodo *root){
    int medio=(this->M/2);
    PickSeed(root,medio);


  }

  pari MBR(Area a,Area p){

  }

  nodo* ChooseLeaf(nodo *root,Area a){
    if(!root->es_nodo()){//si es hoja
      return root;
    }else{
      int min=INF,x=0;
      pari aux;
      //buscamos el sub arbol que se expanda menos
      for(int i=0;i<root->puntero.size();i++){
        aux=MBR(root->puntero[i]->Area,a);
        if(min>aux.first){
          min=aux.first;//valor minimo de mbr
          x=aux.second;//direccion de ese valor minimo
        }
      }
      ChooseLeaf(root->puntero[x]);
    }

  }
  vector<nodo*> buscar(nodo *root,Area S){
    vector<nodo*> resultado;
    if(root->es_nodo()){
      //sub arbol
      for(unsigned int i=0;i<root->puntero.size();i++){
        if(se_solapan(S , root->puntero[i]->Area)){
          buscar(root->puntero[i],S);
        } 
      }
    }else{//nodo hoja
      if(se_solapan(root->Area,S))
        resultado.push_back(root);
    }
    return resultado;

  }
  void eliminar(){

  }
  ~rtree();


};


int main(){
  return 0;
}
