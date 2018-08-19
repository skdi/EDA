
#include<iostream>
#include<cstdlib>
using namespace std;
 
int cola[10]; // arreglo de 10 elementos
int push;
int pop;

void Inicializar()
{
  push = 0;
  pop = -1;
}

void Push(int numero)
{
  if( push != pop ) // Cola llena
    cola[push] = numero;

  if( pop == -1 )
    pop = push; // Ya hay elementos a extraer de la cola

  push = (push+1)%10;
}

int Pop()
{
  int toReturn = -1; // Valor a devolver si la cola está vacía

  if( pop != -1 )
  {
    toReturn = cola[pop];

    pop = (pop+1)%10;

    if( pop == push )
      pop = -1; // Si hemos extraido el último indicamos que está vacía
  }

  return toReturn; 
}

int main()
{
  Inicializar();
  Push(2);
  Push(4);

  printf("%d\n",Pop()); // 2
  printf("%d\n",Pop()); // 4
  printf("%d\n",Pop()); // -1
}
