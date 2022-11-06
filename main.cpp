#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

/*
 _____ _     _____ __  __ _____ _   _ _____ 
| ____| |   | ____|  \/  | ____| \ | |_   _|
|  _| | |   |  _| | |\/| |  _| |  \| | | |  
| |___| |___| |___| |  | | |___| |\  | | |  
|_____|_____|_____|_|  |_|_____|_| \_| |_| 

*/                                
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

/*
 _____ _     _____ __  __ _____ _   _ _____ 
| ____| |   | ____|  \/  | ____| \ | |_   _|
|  _| | |   |  _| | |\/| |  _| |  \| | | |  
| |___| |___| |___| |  | | |___| |\  | | |  
|_____|_____|_____|_|  |_|_____|_| \_| |_|  
                                            
 _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
|  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
| |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
|  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
|_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/ 
                                                    
*/
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
    this->key=e.key; 
    this->value=e.value;
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

/* 
 _   _  ___  ____  _____ 
| \ | |/ _ \|  _ \| ____|
|  \| | | | | | | |  _|  
| |\  | |_| | |_| | |___ 
|_| \_|\___/|____/|_____|

*/                      
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
        Element<K, T>* getElements(K key);
        int addElement(Element<K, T> e);
        int deleteElement(Element<K, T> e);
        int getNbElements();
        void printNode();
        K getKey();
        void sortElements(); 
};

/*
 _   _  ___  ____  _____   _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
| \ | |/ _ \|  _ \| ____| |  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
|  \| | | | | | | |  _|   | |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
| |\  | |_| | |_| | |___  |  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
|_| \_|\___/|____/|_____| |_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/ 
                                                                              
*/
template<class K, class T>
Element<K, T>* Node<K,T>::getElements(K key){
    /*int nbElem=0;int tmp=0;
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
    }*/
    return this->elem_tab;
}

template<class K, class T>
int Node<K,T>::addElement(Element<K, T> e){
    Element<K, T>* newElemTab=(Element<K, T>*) malloc(sizeof(Element<K, T>)*(nbElements+1));
    for(int i=0; i<this->nbElements; i++){
        newElemTab[i] = this->elem_tab[i];
    }
    newElemTab[nbElements]=e;            
    this->nbElements++;
    //free(this->elem_tab);
    this->elem_tab=newElemTab;
    // We sort the elements 
    this->sortElements();
    // We return 1 in a success case
    return 1;
} 

template<class K, class T>
int Node<K,T>::deleteElement(Element<K, T> e){
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

template<class K, class T>
int Node<K,T>::getNbElements(){
    return this->nbElements;
}

template<class K, class T>
void Node<K,T>::printNode(){
    for(int i=0; i<this->nbElements; i++){
        this->elem_tab[i].printElem();
    }
}

template<class K, class T>
K Node<K,T>::getKey(){
    return this->key; 
}

template<class K, class T>
void Node<K,T>::sortElements(){
    for (int i = 0; i < nbElements; i++) {     
        for (int j = i+1; j < nbElements; j++) {     
           if(elem_tab[i].getValue() > elem_tab[j].getValue()) {    
               Element<K, T> temp = elem_tab[i];    
               elem_tab[i] = elem_tab[j];    
               elem_tab[j] = temp;    
           }     
        }     
    }   
}
/*
 ___ _   _ ____  _______  __
|_ _| \ | |  _ \| ____\ \/ /
 | ||  \| | | | |  _|  \  / 
 | || |\  | |_| | |___ /  \ 
|___|_| \_|____/|_____/_/\_\
                            
*/
template<class K, class T> 
class Index{
    private: 
        int nbElements; 
        Node<K, T>* nodes;
    public: 
        Index(){
            this->nbElements=0; 
            this->nodes=(Node<K, T>*) malloc(sizeof(Node<K, T>)); 
        }
        /*~Index(){
            free(this->nodes);
            cout << "This Index doesn't have any node, that's why it's destroyed"<<endl;  
        }*/
        Node<K,T> getNodeIndex(int i);
        int getNbCurrElem(K key);
        int getNode(K key);
        int addNode(K key);
        int deleteNode(K key);
        Element<K,T>* getElements(K key);
        int addElement(Element<K,T> e);
        int getNbNodes();
        void printIndex();
        // Function used to delete an element from the Inex 
        int deleteElement(Element<K,T> e);
        void sortNodes();
};

/*
 ___ _   _ ____  _______  __
|_ _| \ | |  _ \| ____\ \/ /
 | ||  \| | | | |  _|  \  / 
 | || |\  | |_| | |___ /  \ 
|___|_| \_|____/|_____/_/\_\
                            
 _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
|  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
| |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
|  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
|_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/ 
                                                    
*/
// Function used to delete an element from the Inex 
template<class K, class T> 
int Index<K, T>::getNbCurrElem(K key){
    return this->getNodeIndex((this->getNode(key))).getNbElements();
}
template<class K, class T> 
int Index<K, T>::deleteElement(Element<K,T> e){
    for(int i=0; i<this->nbElements; i++){
        if(e.getKey() == nodes[i].getKey()){
            this->nodes[i].deleteElement(e);
            // We verify if the node has other nodes or not
            if(nodes[i].getNbElements()==0){
                this->deleteNode(nodes[i].getKey()); 
            } 
            return 1;  
        }
    }
    cout << "The element you want to delete is not in any node"<<endl; 
    return -1; 
}

template<class K, class T> 
void Index<K, T>::printIndex(){
    for(int i=0; i<this->nbElements; i++){
        cout << "Node key: "<< nodes[i].getKey()<< endl; 
        nodes[i].printNode();
    }
}

template<class K, class T> 
int Index<K, T>::getNbNodes(){
    return this->nbElements;
}

template<class K, class T> 
int Index<K, T>::addElement(Element<K,T> e){
    for(int i=0; i<this->nbElements; i++){
        if(e.getKey()==nodes[i].getKey()){
            this->nodes[i].addElement(e);
            return 1;  
        }
    }
    // There is no node with a the element's key, we should create it 
    this->addNode(e.getKey()); 
    this->addElement(e);
    sortNodes();
    return 2;
}

template<class K, class T> 
Element<K,T>* Index<K, T>::getElements(K key){
    if(this->getNode(key)!=-1){
        return this->getNodeIndex((this->getNode(key))).getElements(key);  
    }
    else{
        cout << "There is no node which has a key:"<<key<<endl; 
        return NULL;
    }
    
}

template<class K, class T> 
int Index<K, T>::deleteNode(K key){
    int tmp=0; bool exists=false; int nb_E=0;
    // New tab having all the nodes except the node with 'key'
    Node<K, T>* newNodeTab=(Node<K, T>*) malloc(sizeof(Node<K, T>)*(nbElements-1));
    if(this->nbElements==0){
        cout << "The Index doesn't have any node to delete"<<endl;
        return -1;
    }
    else{
        // We search for the node with'key' in the Index
        for(int i=0; i<this->nbElements; i++){
            if(this->nodes[i].getKey() != key){
                newNodeTab[tmp]=this->nodes[i];
                tmp++;
            }
            else{
                exists =true;
            }
        }
        if(exists){
            this->nbElements--;
            free(this->nodes);
            this->nodes=newNodeTab;
            // We verify if the Index is empty, we delete it 
            if(this->nbElements==0){
                delete this; 
            }
        }
        return 1;
    } 
}

template<class K, class T> 
int Index<K, T>::addNode(K key){
    Node<K,T> n = Node<K,T>(key); 
    Node<K, T>* newNodeTab=(Node<K, T>*) malloc(sizeof(Node<K, T>)*(this->nbElements+1));
    for(int i=0; i<this->nbElements; i++){
        newNodeTab[i] = this->nodes[i];
    }
    newNodeTab[this->nbElements]=n;
    this->nbElements++;
    //free(this->nodes);
    this->nodes=newNodeTab;
    // We return 1 in a success case
    return 1;
}

template<class K, class T>
int Index<K, T>::getNode(K key){
    for(int i=0; i<nbElements; i++){
        if(nodes[i].getKey()==key){
            return i; 
        }
    }
    return -1; 
}

template<class K, class T>
Node<K,T> Index<K, T>::getNodeIndex(int i){
    return this->nodes[i]; 
}

template<class K, class T>
void Index<K,T>::sortNodes(){
    for (int i = 0; i < this->nbElements; i++) {     
        for (int j = i+1; j < this->nbElements; j++) {     
           if(nodes[i].getKey() > nodes[j].getKey()) {    
               Node<K, T> temp = nodes[i];    
               nodes[i] = nodes[j];    
               nodes[j] = temp;    
           }     
        }     
    }   
}

/*
   _   _   ___  _____ _     ___    _    ______   __
   / \ | | | \ \/ /_ _| |   |_ _|  / \  |  _ \ \ / /
  / _ \| | | |\  / | || |    | |  / _ \ | |_) \ V / 
 / ___ \ |_| |/  \ | || |___ | | / ___ \|  _ < | |  
/_/   \_\___//_/\_\___|_____|___/_/   \_\_| \_\|_|  
                                                    
 _____ _   _ _   _  ____ _____ ___ ___  _   _ ____  
|  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___| 
| |_  | | | |  \| | |     | |  | | | | |  \| \___ \ 
|  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
|_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/ 
                                                    
*/
// Functions used to get the keys and valus from the files
int in(char* str){
    for(int i=0; strlen(str); i++){
        if(str[i]=='1'){
            return 1; 
        }
        else if(str[i]=='2'){
            return 2; 
        }
        else if(str[i]=='3'){
            return 3; 
        }
    }
    return -1;
}
int pvIndice(string str){
    int res=0; 
    for(int i=0; i<str.length(); i++){
        if(str[i] != ';')
            res++; 
        else
            return res; 
    }
    // In problem case
    return -1;
}
int* getInt(string str){
    string tmp=""; 
    int* res = (int*) malloc(sizeof(int)*2); 
    bool trouve = false; 
    for(int i=0; i< str.length(); i++){
        if(str.at(i) != ';'){
            tmp= tmp + str[i];
        }
        else if(trouve==false){
            trouve = true; 
            res[0] = stoi(tmp); 
            tmp.clear();
        }
        else{
            tmp= tmp + str[i];
        }
    }
    res[1] = stoi(tmp); 
    return res;
} 
string getCharStr(string str){
    string tmp = ""; 
    // We get the string which is the value
    for(int i=2; i< str.length(); i++){     
       tmp=tmp+str[i];
       
    }
    return tmp;
}
int* getIntStr(string str){
    string tmp=""; 
    int* res = (int*) malloc(sizeof(int)*2); 
    bool trouve = false; 
    for(int i=0; i< str.length(); i++){
        if(str.at(i) != ';'){
            tmp= tmp + str[i];
        }
        else if(trouve==false){
            trouve = true; 
            res[0] = stoi(tmp); 
            tmp.clear();
        }
        else{
            tmp= tmp + str[i];
        }
    }
    res[1] = stoi(tmp); 
    return res;
}
int getIntBis(string str){
    string tmp=""; 
    int res; 
    for(int i=0; i< str.length(); i++){
        if(str.at(i) != ';'){
            tmp= tmp + str[i];
        }
        else{
            res = stoi(tmp); 
        }
    }
    return res; 
}
string getStr(string str){
    string res = ""; 
    for(int i=pvIndice(str)+1; i< str.length(); i++){
        res = res + str[i]; 
    }
    return res;  
}

/*
 __  __    _    ___ _   _ 
|  \/  |  / \  |_ _| \ | |
| |\/| | / _ \  | ||  \| |
| |  | |/ ___ \ | || |\  |
|_|  |_/_/   \_\___|_| \_|
                          
*/
int main(int argc, char* argv[]){
    // keys type
    int key; 
    // valus types
    int value; 
     // Open the file 
     ifstream file; 

    if(in(argv[1])==1){
        string myText; 


        int* res; 
        // The file name is passed with the execution command
        file.open(argv[1]); 
        Index<int, int> i1 = Index<int, int>();
        while(getline(file, myText)){
            res = getInt(myText); 
            Element<int, int> e = Element<int, int>(res[0], res[1]); 
            i1.addElement(e);
            free(res);
        }
        i1.printIndex();
    }
    else if(in(argv[1])==2){
        string myText; 
        // The file name is passed with the execution command
        file.open(argv[1]); 
        Index<char, string> i2 = Index<char, string>();
        // get value and key 
        while(getline(file, myText)){
            Element<char, string> e = Element<char, string>(myText[0], getCharStr(myText));
            i2.addElement(e);
        }
        i2.printIndex();

        // Delete test
        cout << "-------------------------" << endl;
        Element<char, string> test = Element<char, string>('A', "Alex");
        Element<char, string> test2 = Element<char, string>('m', "Maman");
        i2.deleteElement(test);
        i2.deleteElement(test2);

        // Get node test
        Node<char, string> node = i2.getNodeIndex(i2.getNode('y'));
        node.printNode();

        // Get element test
        Element<char, string>* elements = i2.getElements('V');
        for(int i=0; i<i2.getNbCurrElem('V'); i++){
            elements[i].printElem(); 
        }
        
        //i2.printIndex();
    }
    else if(in(argv[1])==3){
        string myText; 
        // The file name is passed with the execution command
        file.open(argv[1]); 
        Index<int, string> i3 = Index<int, string>();
        // get value and key 
        while(getline(file, myText)){
            Element<int, string> e = Element<int, string>(getIntBis(myText), getStr(myText));
            i3.addElement(e);
        }
        i3.printIndex();
    }
    return 0; 

}