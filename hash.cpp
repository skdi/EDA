#include "haash.h"

haash::haash(int key, string value){
    this->key=key;
    this->value=value;
    this->next=NULL;

}

void haashmap::put(int key, string value){
    int haash1=key%TABLE_SIZE;
    if(table[haash1]==NULL){
        table[haash1]=new haash(key,value);
        return;
    }else
        table[haash1]->set_next(new haash(key,value));

}


void haashmap::remove(int key){
    int haash1=key%TABLE_SIZE;
    haash *mihaash=table[haash1];
    if(mihaash==NULL){
        cout<<"vacio"<<endl;
        return;
    }else{
        while(mihaash->getnext()!=NULL){
            if(mihaash->getkey()==key){
                haash *temp=mihaash;//guardo la posicion anterior
                mihaash=mihaash->getnext();//poisicion actual
                haash *temp2=mihaash->getnext();//posicion sig
                temp->set_next(temp2);
                delete mihaash;
            }
            mihaash=mihaash->getnext();
        }
    }


}
