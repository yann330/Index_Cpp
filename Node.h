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
                cout << "No element available with the key "<< key<<endl; 
                return NULL; 
            }
        }
        int addElement(Element e){
            this->nbElements++; 
            this->elem_tab=realloc(this->elem_tab, sizeof(Element)*nbElements);
            if(elem_tab==NULL){
                cout << "an error occured while calling realloc"<<endl;
                // We return -1 in a fail case 
                return -1; 
            }
            // Else we add the element 
            else{
                elem_tab[nbElements-1]=e; 
                // We return 1 in a success case
                return 1; 
            }
        } 
        // Function which returns if an element e is in the elem_tab
        int in(Element e){
            for(int i=0; i<this->nbElements; i++){
                if(this->elem_tab[i]==e){
                    return 1; 
                }
            }
            return -1; 
        }

        int deleteElement(Element e){
            int tmp=0; 
            // New tab having all the elements without 'e'
            Element* newElemTab=malloc(sizeof(Element)*(nbElements-1)
            if(this->nbElements==0){
                cout << "The node doesn't have any element to delete"<<endl; 
            }
            else{
                // We search for the element 'e' in the node 
                for(int i=0; i<this->nbElements; i++){
                    if(this->elem_tab[i] != e){
                        newElemTab[tmp++]=this->elem_tab[i]; 
                    }
                }
            }
        }
};