#include <iostream>
#include <stdlib.h>

using namespace std;

class nodo {
public:
  int dato;
  string nombre;
  nodo *sig;
};

class pila {
  nodo *inicio;
public:
  pila(){
    inicio=NULL;
  }
  void push();
  void pop();
  void show();
  void top();
  void size();
};

void pila::push() {
  int valor;
  string valor2;
  nodo * aux = new nodo;
  system("cls");
  cout << "Ingresa el id del proceso: ";
  cin >> valor;
  cout << "Ingresa el nombre del proceso: ";
  cin.ignore();
  getline(cin, valor2);
  aux->dato = valor;
  aux->nombre = valor2;
  aux->sig = NULL;
  if (inicio != NULL)
    aux->sig = inicio;
  inicio = aux;
  cout << "Nuevo proceso insertado en la pila!\n";
  system("pause");
}

void pila::pop() {
  nodo * temp = new nodo;
  if (inicio == NULL) {
    system("cls");
    cout << "\nLa pila esta vacia!\n\n";
    system("pause");
  } else {
    temp = inicio;
    inicio = inicio->sig;
    system("cls");
    cout << "\nEl proceso eliminado es: " << temp->dato << " - " << temp->nombre << "\n" << endl;
    delete temp;
    system("pause");
  }
}

void pila::show() {
  nodo * aux1 = inicio;
  if (inicio == NULL) {
    system("cls");
    cout << "\nLa pila esta vacia!\n\n";
    system("pause");
  } else {
    system("cls");
    cout << "Procesos:\n" << endl;
    while (aux1 != NULL) {
      cout << aux1->dato << " - " << aux1->nombre << "\n" << endl;
      aux1 = aux1->sig;
    }
    system("pause");
  }
}

void pila::top() {
  nodo * aux1 = inicio;
  if (inicio == NULL) {
    system("cls");
    cout << "\nLa pila esta vacia!\n\n";
    system("pause");
  } else {
    system("cls");
    cout << "Proceso TOP:\n" << endl;
    cout << aux1->dato << " - " << aux1->nombre << "\n" << endl;
    system("pause");
  }
}

void pila::size() {
  nodo * aux1 = inicio;
  if (inicio == NULL) {
    system("cls");
    cout << "\nLa pila esta vacia!\n\n";
    system("pause");
  } else {
    int contador = 0;
    while (aux1) {
      contador++;
      aux1 = aux1->sig;
    }
    system("cls");
    cout << "El tamano de la pila es: '" << contador << "'\n" << endl;
    system("pause");
  }
}

int main() {
  nodo nuevo;
  pila stack;
  int opcion;
  while (1) {
    cout << "[:]Pila en lista enlazada" << endl;
    cout << "[1]Push" << endl;
    cout << "[2]Pop" << endl;
    cout << "[3]Show" << endl;
    cout << "[4]Top" << endl;
    cout << "[5]Size" << endl;
    cout << "[6]Salir" << endl;
    cout << "\nIngresa tu opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
      stack.push();
      break;
    case 2:
      stack.pop();
      break;
    case 3:
      stack.show();
      break;
    case 4:
      stack.top();
      break;
    case 5:
      stack.size();
      break;
    case 6:
      return 0;
      break;
    default:
      cout << "Por favor ingresa una opcion correcta.\n";
      break;
    }
  }
  return 0;
}
