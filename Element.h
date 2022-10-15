#include<iostream>
using namespace std;


template<class K, class V> class Element{
    // K -> type de key
    // V -> type de value 
    private:
        K key; 
        V value; 
    public: 
        Element(K key, V value){
            this->key=key; 
            this->value=value; 
        }
        K getKey(){
            return this->key; 
        }
        V getValue(){
            return this->value; 
        }
}; 
