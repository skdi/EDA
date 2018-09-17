#ifndef haash_H
#define haash_H
#include <iostream>
using namespace std;

const int TABLE_SIZE=104729;//tabla de tamaño de numero primo
class haash{
private:
    int key;
    string value;
    haash *next;
public:
    haash(int key,string value);
    int getkey(){return key;}
    string get_value(){return value;}
    void set_value(string value){this->value=value;}
    haash *getnext(){return next;}
    void set_next(haash* next){this->next=next;}
};

class haashmap{
private:
    haash **table;
public:
    haashmap(){
        table=new haash*[TABLE_SIZE];
        for(int i=0;i<TABLE_SIZE;i++)
            table[i]=NULL;
    }
    string get(int key){
        int haash1=(key%TABLE_SIZE);
        if(table[haash1]==NULL){
            return "-1";
        }
        else{
            haash *entry=table[haash1];
            while(entry!=NULL && entry->getkey()!=key)
                entry=entry->getnext();
            if(entry==NULL)
                return "-1";
            else return entry->get_value();
        }
    }
    void put(int key,string value);
    void remove(int key);
    ~haashmap(){
        for(int i=0;i<TABLE_SIZE;i++)
            if(table[i]!=NULL){
                haash *prev=NULL;
                haash *entry=table[i];
                while(entry!=NULL){
                    prev=entry;
                    entry=entry->getnext();
                    delete prev;
                }
            }
        delete[] table;
    }

};


#endif // haash_H






