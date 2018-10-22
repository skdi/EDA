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

int BoyerMoore(string T,string P,string Alpha){

}

int main(){
    string T,P;
    vpar index;
    T="abacaab";
    P="cab";
    cout<<FuerzaBruta(T,P)<<endl;
    index=Last_occurrence("abacab","abcd");
    imprimir(index);

    return 0;
}
