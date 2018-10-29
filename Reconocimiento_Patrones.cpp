#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair <char,int> par;
typedef vector<par> vpar;

int FuerzaBruta(string T,string P){
    int n,m,j;
    n=T.length();
    m=P.length();

    for(int i=0;i<(n-m);i++){
        j=0;
        while(j<m && T[i+j]==P[j])
            j++;

        if(j==m)
            return i;
    }
    return -1;

}
string abc="abcdefghijklmnopqrstuvwxyz";

vpar Last_occurrence(string P,string Alpha){
    vpar index;par aux;
    for(unsigned int i=0;i<Alpha.length();i++){
        aux.second=-1;
        for(unsigned int j=0;j<P.length();j++){
            aux.first=Alpha[i];
            if(P[j]==Alpha[i]){
                aux.second=j;
            }
        }
        index.push_back(aux);
    }
    return index;
}
void imprimir(vpar ix){
    for(int i=0;i<ix.size();i++){
        cout<<ix[i].first<<" "<<ix[i].second<<endl;
    }
}

int posi(vpar L,char a){
    for(int i=0;i<L.size();i++){
        if(L[i].first==a)
            return L[i].second;
    }
    return -1;
}

int BoyerMoore(string T,string P,string Alpha){
    vpar L=Last_occurrence(P,Alpha);
    int n=T.length();
    int m=P.length();
    int i,j,l;
    i=m-1;
    j=m-1;
    do{
        if(T[i]==P[j]){
            if(j==0)
                return i;
            else{
                i-=1;
                j-=1;
            }
        }else{
            l=posi(L,T[i]);
            i=i+m-min(j,i+l);
            j=m-1;
        }

    }while(i<=n-1);
    return -1;
}

int main(){
    string T,P;
    vpar index;
    T="abacaab";
    P="ac";
    //cout<<FuerzaBruta(T,P)<<endl;
    index=Last_occurrence("abacab","abcd");
    imprimir(index);
    cout<<BoyerMoore(T,P,abc)<<endl;

    return 0;
}
