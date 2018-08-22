#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
 
int cola[10]; 
int push;
int pop;
class lista{
public:
  int size;
  vector<int> A;
  lista(int n){
    for(int i=0;i<n;i++){
        this->A.push_back(0);
        }
        this->size=n;
  }
  void insert(int val,int pos){
    if(pos>this->size || pos<0){
      return;
    }else this->A[pos]=val;
  }
  void eliminar(int pos){
    if(this->A[pos]!=0)
      this->A[pos]=0;
    else return;
  }
  void imprimir(){
      if(this->size>0){
        for(int i=0;i<this->size;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
      }else return;
  }

};

int main()
{
  lista *A=new lista(4);
  A->insert(1,0);
  A->insert(2,1);
  A->insert(5,2);
  A->insert(7,3);
  A->imprimir();
  A->eliminar(2);
  A->imprimir();
}
