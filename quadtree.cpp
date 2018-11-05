#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef vector<vector<int>> matrix;

matrix inicializar(int n){
    
    vector<int> aux;
    matrix A;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            aux.push_back(0);
        }
        A.push_back(aux);
        aux.clear();
    }
    return A;
}


matrix ingresar_matriz(int n){

    vector<int> aux;
    matrix matriz;
    int val;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<i<<":";
            cin>>val;
            aux.push_back(val);
        }
        matriz.push_back(aux);
        aux.clear();
    }
    return matriz;
}

void imprimir_matriz(matrix matriz){

    for (int i = 0; i < matriz.size(); i++){
        for (int j = 0; j < matriz.size(); j++){
            cout<<matriz[i][j]<<" ";
        }

        cout<<endl;
    }
}

struct nodo{
    int val;
    nodo* uno;
    nodo* dos;
    nodo* tres;
    nodo* cuatro;
    nodo(int v,nodo* a,nodo* b,nodo* c,nodo* d){
        this->val=v;
        this->uno=a;
        this->dos=b;
        this->tres=c;
        this->cuatro=d;
    }
    nodo(int v){
        this->val=v;
        this->uno=NULL;
        this->dos=NULL;
        this->tres=NULL;
        this->cuatro=NULL;
    }
    nodo(){
        
        this->uno=NULL;
        this->dos=NULL;
        this->tres=NULL;
        this->cuatro=NULL;
    }
};

matrix submatriz(matrix A,int n,int m){

    matrix sub;
    int size=A.size()/2;
    sub=inicializar(size);
    int x=n,y=m;

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){

            sub[i][j]=A[x][y];
            y++;
        }

        x=x+1;
        y=m;
    }
    return sub;
}

int matriz_completa(matrix A){

    int au=A[0][0];
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            if(A[i][j]!=au)
                return -1;
        }
    }
    return au;
}

void imprimir_arbol(nodo* root)
{
    //codigo NO PROPIO de la impresion por niveles de un arbol
    queue<nodo*> cola;
    cola.push(root);
    int n,h=0;
    cout<<"Imprimir por niveles:"<<endl;
    while(!cola.empty())
    {
        n=cola.size();
        cout<<h<<": ";
        h++;
        for(int i=0;i<n;i++)
        {
            if(cola.front()->uno!=NULL)
            {
                cola.push(cola.front()->uno);
            }
            if(cola.front()->dos!=NULL)
            {
                cola.push(cola.front()->dos);   
            }
            if(cola.front()->tres!=NULL)
            {
                cola.push(cola.front()->tres);  
            }
            if(cola.front()->cuatro!=NULL)
            {
                cola.push(cola.front()->cuatro);    
            }
            cout<<" "<<cola.front()->val<<" ";
            cola.pop();
        }
        cout<<endl;
        
    }
}

void quadtree(matrix matri,nodo *root){

    int size=matri.size();
    int n=matriz_completa(matri);
    if(n==-1)
    {
        root->val=-1;
        if(size==2)
        {
            root->uno=new nodo(matri[0][0]);
            root->dos=new nodo(matri[0][1]);
            root->tres=new nodo(matri[1][1]);
            root->cuatro=new nodo(matri[1][0]);
            return;
        }
        else if(size%4==0)
        {
            
            root->uno=new nodo();
            root->dos=new nodo();
            root->tres=new nodo();
            root->cuatro=new nodo();
            quadtree(submatriz(matri,0,0),root->uno);
            quadtree(submatriz(matri,0,size/2),root->dos);
            quadtree(submatriz(matri,size/2,0),root->tres);
            quadtree(submatriz(matri,size/2,size/2),root->cuatro);
        }
    }
    else
    {
        root->val=n;
        return;
    }

}


int main(){
    matrix matriz;
    matrix sub;
    matriz=inicializar(8);
    cout<<"Matriz de Imagenes"<<endl<<endl;
    matriz=
    {
        {0,1,1,0,0,0,0,0},
        {0,1,1,0,0,1,1,0},
        {0,0,1,0,0,1,1,0},
        {0,0,1,1,1,1,1,0},
        {0,0,0,0,0,1,1,0},
        {0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
    };

    imprimir_matriz(matriz);
    cout<<endl<<"Arbol generado"<<endl<<endl;
    nodo *root=new nodo();
    quadtree(matriz,root);
    imprimir_arbol(root);

    return 0;
}
