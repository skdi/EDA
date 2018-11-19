#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template <class TIPO>
struct nodo(){

	int x_low;
	int y_low;
	int x_high;
	int y_high;
	int nivel;
	int cont;
	punto *ref;
	nodo (int a,int b,int c,int d){
		this->x_low=a;
		this->y_low=b;
		this->x_high=c;
		this->y_high=d;

	}
	bool es_hoja(){
		return (nivel==0);
	}
	TIPO id;

}




class rtree{
public:
	rtree(){

	}

}


int main(){
	return 0;
}
