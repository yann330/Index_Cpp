#include<iostream>

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
            void afficher(); 
}; 
/************************* Element Functions ********************/
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
/**************************************************************************/
/************************* Node ********************/
template<class K, class T>class Node{
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
        Element<K, T>* getElements(key){
            int nbElem=0;int tmp=0;
            Element<K, T>* res=NULL;  
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
            this->nbElements++; 
            this->elem_tab=realloc(this->elem_tab, sizeof(Element<K, T>)*nbElements);
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
        int in(Element<K, T> e){
            for(int i=0; i<this->nbElements; i++){
                if(this->elem_tab[i]==e){
                    return 1; 
                }
            }
            return -1; 
        }

        int deleteElement(Element<K, T> e){
            int tmp=0; 
            // New tab having all the elements without 'e'
            Element<K, T>* newElemTab=malloc(sizeof(Element<K, T>)*(nbElements-1)
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


int main(){
    Node<int, int> n = Node<int, int>(3); 

    return 1; 
}