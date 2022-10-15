#include<iostream>
#include"Element.h"
using namespace std;

template<class K>class Node{
    private: 
        K key; 
        int nbElements; 
        Element* elem_tab; 
    public: 
        Node(K key){
            this->key=key; 
            this->nbElements=0;
            this->elem_tab=NULL;  
        }
        Node(K key, int nbElemFile){
            this->key=key; 
            this->nbElements=nbElemFile; 
            this->elem_tab= (Element*) malloc(sizeof(Element)*nbElemFile); 
        }
        Element* getElements(key){
            int nbElem=0;int tmp=0;
            Element* res=NULL;  
            // Firstly we have to know how many elements do we have with the given key 
            for(int i=0; i<nbElements; i++){
                if(elem_tab[i].getKey()==key){
                    nbElem++; 
                }
            }
            // Here we've how many Elements we have with 'key'
            if(nbElem != 0){
                res=(Element*) malloc(sizeof(Element)*nbElem);
                for(int i=0; i<nbElements; i++){
                    if(elem_tab[i].getKey()==key){
                        res[tmp]=elem_tab[i]; 
                        tmp++; 
                    }
                } 
                return res; 
            }
            else{
                cout << "No element available with the key "<< key; 
                return NULL; 
            }
        }
        int addElement(Element e){

        } 
};