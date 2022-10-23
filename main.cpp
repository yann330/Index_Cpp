#include <iostream>

using namespace std;
/************************* Element ********************/
template<class K, class V> 
    class Element{
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
            K getKey();
            V getValue();
            // We should redefine '==' between two elements
            bool operator==(Element<K,V> e);
            // We should redefine '=' between two elements 
            void operator=(Element<K,V> e);
            bool operator!=(Element<K,V> e);
            void printElem();
}; 
/************************* Element Functions ********************/
template<class K, class V>
void Element<K, V>::printElem(){
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
bool Element<K, V>::operator!=(Element<K,V> e){
    return (this->key!=e.key) || (this->value!=e.value);
}

template<class K, class V>
V Element<K, V>::getValue(){
    return this->value; 
}

template<typename K, typename V>
K Element<K, V>::getKey(){
    return this->key; 
}
/**************************************************************************/
/************************* Node ********************/
template<class K, class T>
class Node{
    private: 
        K key; 
        int nbElements; 
        Element<K, T>* elem_tab; 
    public: 
        Node(K key){
            this->key=key; 
            this->nbElements=0;
            this->elem_tab=NULL;  
        }
        Element<K, T>* getElements(K key){
            int nbElem=0;int tmp=0;
            Element<K, T>* res=(Element<K, T>*) malloc(sizeof(Element<K, T>));
            // Firstly we have to know how many elements do we have with the given key 
            for(int i=0; i<nbElements; i++){
                if(elem_tab[i].getKey()==key){
                    nbElem++; 
                }
            }
            // Here we've how many Elements we have with 'key'
            if(nbElem != 0){
                res=(Element<K, T>*) malloc(sizeof(Element<K, T>)*nbElem);
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
        int addElement(Element<K, T> e){
            Element<K, T>* newElemTab=(Element<K, T>*) malloc(sizeof(Element<K, T>)*(nbElements+1));
            for(int i=0; i<this->nbElements; i++){
                newElemTab[i] = this->elem_tab[i];
            }
            newElemTab[nbElements]=e;
            this->nbElements++;
            free(this->elem_tab);
            this->elem_tab=newElemTab;
            // We return 1 in a success case
            return 1;

        } 
        int deleteElement(Element<K, T> e){
            int tmp=0; bool exists=false; int nb_E=0;
            // New tab having all the elements without 'e'
            Element<K, T>* newElemTab=(Element<K, T>*) malloc(sizeof(Element<K, T>)*(nbElements-1));
            if(this->nbElements==0){
                cout << "The node doesn't have any element to delete"<<endl;
                return -1;
            }
            else{
                // We search for the element 'e' in the node 
                for(int i=0; i<this->nbElements; i++){
                    if(this->elem_tab[i] != e){
                        newElemTab[tmp]=this->elem_tab[i];
                        tmp++;
                    }
                    else{
                        exists =true;
                        nb_E++;
                    }
                }
                if(exists){
                    this->nbElements-=nb_E;
                    free(this->elem_tab);
                    this->elem_tab=newElemTab;
                }
                return 1;
            }
        }
        int getNbElements(){
            return this->nbElements;
        }
        void printNode(){
            for(int i=0; i<this->nbElements; i++){
                this->elem_tab[i].printElem();
            }
        }
        K getKey(){
            return this->key; 
        }
};
/**************************************************************************/
/************************* Index ********************/
template<class K, class T> class Index{
    private: 
        int nbElements; 
        Node<K, T>* nodes;
    public: 
        Index(){
            this->nbElements=0; 
            this->nodes=malloc(sizeof(Node<K, T>)); 
        }
        ~Index(){
            free(this->nodes);
            cout << "This Index doesn't have any node, that's why it's destroyed"<<endl;  
        }
        Node<K,T> getNodeIndex(int i){
            return this->nodes[i]; 
        }
        int getNode(K key){
            for(int i=0; i<nbElements; i++){
                if(nodes[i].getKey()==key){
                    return i; 
                }
            }
            return -1; 
        }
        int addNode(K key){
            // This part will be done at the end of the project 
        }
        int deleteNode(K key){
            int tmp=0; bool exists=false; int nb_E=0;
            // New tab having all the nodes except the node with 'key'
            Node<K, T>* newNodeTab=(Element<K, T>*) malloc(sizeof(Node<K, T>)*(nbElements-1));
            if(this->nbElements==0){
                cout << "The Index doesn't have any node to delete"<<endl;
                return -1;
            }
            else{
                // We search for the node with'key' in the Index
                for(int i=0; i<this->nbElements; i++){
                    if(this->elem_tab[i] != e){
                        newElemTab[tmp]=this->nodes[i];
                        tmp++;
                    }
                    else{
                        exists =true;
                    }
                }
                if(exists){
                    this->nbElements--;
                    free(this->nodes);
                    this->nodes=newElemTab;
                    // We verify if the Index is empty, we delete it 
                    if(this->nbElements==0){
                        delete this; 
                    }
                }
                return 1;
            } 
        }
        Element* getElements(K key){
            if(this->getNode(key)!=-1){
                return this->getNodeIndex((this->getNode(key))).getElements(key);  
            }
            else{
                cout << "There is no node which has a key:"<<key<<endl; 
                return NULL;
            }
            
        }
        int addElement(Element e){
            
        }
        int deleteElement(Element e){

        }
};

int main(){
    Node<int, int> n = Node<int, int>(3);
    Node<int, string> n2 = Node<int, string>(4);
    Element<int, int> e = Element<int, int>(2,2);
    Element<int, int> e2 = Element<int, int>(33,10);
    Element<int, int> e3 = Element<int, int>(5,6);
    n.addElement(e);
    n.addElement(e2);
    n.addElement(e3);
    n.addElement(e3);
    n.addElement(e3);

    
}