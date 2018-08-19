#include <iostream>
using namespace std;
 
#define STACK_SIZE 256 /* capacidad máxima */
typedef char arreglo[STACK_SIZE];
 
class Stack {
	 
	int sp; /* puntero de lectura/escritura */
	int items; /* número de elementos en lista */
	int itemsize; /* tamaño del elemento */
	arreglo pila;	 /* el arreglo */
	 
	public:
		// constructor
		Stack() {
			sp = STACK_SIZE-1;
			items = 0;
			itemsize = 1;
		 }
	 
		// destructor
		~Stack() {};
	 
	/* regresa el número de elementos en lista */
	int size() { return items; }
	 
	/* regresa 1 si no hay elementos en la lista, o sea, si la lista está vacia */
	int empty() { return items == 0; }
	 
	/* insertar elemento a la lista */
	int put(char d)
	{
		if ( sp >= 0) {
			pila[sp] = d;
			sp --;
			items ++;
		}
		return d;
	}
	 
	/* retirar elemento de la lista */
	int get()
	{
		if ( ! empty() ) {
			sp ++;
			items --;
		}
		return pila[sp];
	}
	 
}; // fin de clase Stack
 
 
// probando la pila. 
// Nota: obseve cómo los elementos se ingresan en orden desde la A hasta la Z,
// y como los mismos se recuperán en orden inverso.
int main()
{
    int d;
    Stack s;  // s es un objeto (instancia) de la clase Stack
 
    // llenando la pila
    for (d='A'; d<='Z'; d++) s.put(d);
 
    cout << "Items =" << s.size() << endl;
 
    // vaciando la pila
    while ( s.size() ) cout << (char)s.get() << " ";
 
    cout << "\nPara terminar oprima <Enter>...";
    cin.get();
    return 0;
}
