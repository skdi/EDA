#include <iostream>
#include <vector>
#include <utility>

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


matrix llenar_matriz(int n){
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
};

matrix submatriz(int a,int b,int n,matrix A){
    matrix sub;
    sub=inicializar(min(n-a,n-b));
    int x=0,y=0;
    for (int i = a; i < n; i++){
        for (int j = b; j < n; j++){
            sub[x][y]=A[i][j];
            y++;
        }
        x++;
    }
    return sub;
}


void quadtree(matrix A,nodo *root){


}


int main(){
    matrix matriz;
    matrix sub;
    matriz=llenar_matriz(2);
    imprimir_matriz(matriz);
    sub=submatriz(0,0,1,matriz);
    imprimir_matriz(sub);
    return 0;
}
