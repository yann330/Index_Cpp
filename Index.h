#include<iostream>
#include"Element.h"
#include"Node.h"
using namespace std;

template<class K> class Index{
    private: 
        int nbElements; 
        Node* nodes;
    public: 
        Index(){
            this->nbElements=0; 
        }
        Node getNode(K key){

        }
        int addNode(K key){

        }
        int deleteNode(K key){

        }
        Element* getElements(K key){
            return (this->getNode(key)).getElements(key); 
        }
        int addElement(Element e){

        }
        int deleteElement(Element e){

        }
};