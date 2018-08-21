#include<iostream>
#include<cstdlib>
using namespace std;
 
int cola[10]; 
int push;
int pop;

void Inicializar()
{
  push = 0;
  pop = -1;
}
void Push(int numero)
{
  if( push != pop ) 
    cola[push] = numero;
  if( pop == -1 )
    pop = push; 

  push = (push+1)%10;
}

int Pop()
{
  int toReturn = -1;
  if( pop != -1 )
  {
    toReturn = cola[pop];

    pop = (pop+1)%10;

    if( pop == push )
      pop = -1;
  }
  return toReturn; 
}

int main()
{
  Inicializar();
  Push(1);
  Push(2);
  Push(5);
  Push(7);
 
  printf("%d\n",Pop());
  printf("%d\n",Pop());
  printf("%d\n",Pop());
}
