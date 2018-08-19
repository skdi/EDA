
#include<iostream>
#include<cstdlib>
using namespace std;
 
struct nodo{
    int nro;
    struct nodo *sgte;
};
 
typedef struct nodo *Puntero;
 
class Cola{
    public:
        Cola(void);
        void Encolar(int );
        int Desencolar(void );
        bool ColaVacia(void);
        void MostrarCola(void);
        void VaciarCola(void);
 
    private:
        Puntero delante;//puntero al primer elemento de la cola
        Puntero atras;//puntero al ultimo elemento de la cola
 
};
 
 
Cola::Cola(void){
    delante=NULL;//inicializamos los punteros
    atras=NULL;
}
 
bool Cola::ColaVacia(){
 
    if(delante==NULL)
        return true;
    else return false;
}
void Cola::Encolar(int x){
 
     Puntero p_aux;
 
     p_aux=new(struct nodo);
     p_aux->nro=x;
     p_aux->sgte=NULL;
 
     if(delante==NULL)
        delante=p_aux;
     else atras->sgte=p_aux;
 
     atras=p_aux;
}
 
int Cola::Desencolar(void){
 
    int n;
    Puntero p_aux;
 
    p_aux=delante;
    n=p_aux->nro;
    delante=(delante)->sgte;
    delete(p_aux);
    return n;
}
 
void Cola::MostrarCola(void){
    Puntero p_aux;
     p_aux=delante;
     while(p_aux!=NULL){
        cout<<"\n\n\t"<<p_aux->nro;
        p_aux=p_aux->sgte;
     }
 
}
 
void Cola::VaciarCola(void){
 
     Puntero p_aux,r_aux;
     p_aux=delante;
     while(p_aux!=NULL){
        r_aux=p_aux;
        p_aux=p_aux->sgte;
        delete(r_aux);
     }
     delante=NULL;
     atras=NULL;
}
 
int menu(void)
{
    cout<<"\n\n\t -------------------------------------------\n";
    cout<<"\t|        IMPLEMENTACION DE UNA COLA         |\n";
    cout<<"\t|-------------------------------------------|\n";
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  1. ENCOLAR                               |"<<endl;
    cout<<" \t|  2. DESENCOLAR                            |"<<endl;
    cout<<" \t|  3. MOSTRAR COLA                          |"<<endl;
    cout<<" \t|  4. VACIAR COLA                           |"<<endl;
    cout<<" \t|  5. SALIR                                 |"<<endl;
    cout<<" \t|                                           |"<<endl;
    cout<<"\t -------------------------------------------\n";
    cout<<"\t Ingrese opcion: ";
}
int main(void ){
 
    
    Cola cola;
    int x;
    int op;
 
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1: cout<< "\n\t INGRESE NUMERO A ENCOLAR: "; cin>> x;
                    cola.Encolar(x);
                    cout<<"\n\n\t\tNumero " << x << " ENCOLADO...\n\n";
                    break;
 
            case 2:
                    if(cola.ColaVacia()==true)
                        cout<<"\n\n\tCola Vacia....";
                    else{
                        x = cola.Desencolar( );
                        cout<<"\n\n\tNumero "<<x<<" Desencolado\n";
                        }
                    break;
 
 
            case 3:
                    cout << "\n\n\t MOSTRANDO COLA\n\n";
                    if(cola.ColaVacia()!=true)
                        cola.MostrarCola(  );
                    else
                        cout<<"\n\n\tCola vacia..!"<<endl;
                    break;
 
 
            case 4:
                    cola.VaciarCola(  );
                    cout<<"\n\n\t\tCola eliminada...\n\n";
                    break;
 
            default: cout<<"\n\tIngrese una Opcion Valida....!!";
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=5);
 
return 0;
}
