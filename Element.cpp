#include"Element.h"
#include<iostream>


using namespace std;
using namespace N; 

template<class K, class V>
void Element<K, V>::afficher(){
    cout << "Element: key:"<< this->key <<" value:"<<this->value<<endl; 
}

template<class K, class V>
bool Element<K, V>::operator==(Element<K,V> e){
    return (this->getKey()==e.getKey()) && (this->getValue()==e.getValue());
}

template<class K, class V>
void Element<K, V>::operator=(Element<K,V> e){
    this->key=e.getKey(); 
    this->value=e.getValue();
} 
template<class K, class V>
V Element<K, V>::getValue(){
    return this->value; 
}

template<typename K, typename V>
K Element<K, V>::getKey(){
    return this->key; 
}


