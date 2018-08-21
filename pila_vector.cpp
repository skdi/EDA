#include <iostream>
using namespace std;
 
#define STACK_SIZE 256 /* capacidad máxima */
typedef int arreglo[STACK_SIZE];
 
class Stack {
	int sp; 
	int items;
	int itemsize; 
	arreglo pila;	 
	public:
		Stack() {
			sp = STACK_SIZE-1;
			items = 0;
			itemsize = 1;
		 }
		~Stack() {};

	int size() { return items; }
	int empty() { return items == 0; }
	int push(int d)
	{
		if ( sp >= 0) {
			pila[sp] = d;
			sp --;
			items ++;
		}
		return d;
	}
	int pop()
	{
		if ( ! empty() ) {
			sp ++;
			items --;
		}
		return pila[sp];
	}
	 
}; 
int main()
{
    int d;
    Stack s; 
    for (d=1; d<=9; d++) s.push(d); 
    cout << "Items =" << s.size() << endl;
    while ( s.size() ) 
    	cout << (int)s.pop() << " "; 
    cout << "\nPara terminar oprima <Enter>...";
    cin.get();
    return 0;
}
