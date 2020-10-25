#ifndef PRQ_h 
#define PRQ_h 

#include "Node.h"

template<class T> 
class PRQ{
private:
    Node<T> *root; 
    int size;
public:
    PRQ();
    PRQ(initializer_list<T> e); 
    void insert(T data); 
    void order_down(); 
    Node<T>* find_node(int pos); 
    void swap(Node<T> *A, Node<T> *B); 
    void operator = (Double_Linked_List<T> e);
    T remove();
    Double_Linked_List<T> heap_sort(); 

};

template<class T> 
PRQ<T>::PRQ(){
    root = nullptr; 
    size = 0; 
}

template<class T> 
PRQ<T>::PRQ(initializer_list<T> e){
    size = 0; 
    root = nullptr;
    for(auto i:e){
        insert(i); 
    }
    order_down();
}

template<class T> 
void PRQ<T>::insert(T data){
    if(root == nullptr){
        root = new Node<T>(data); 
        size++;
        return; 
    }
    else{
        Node<T> *temp = root; 
        while(temp->right != nullptr){
            temp = temp->right;      
        }
        temp->right = new Node<T>(data);
        size++;
    }
    order_down(); 
}
template <class T>
Node<T> *PRQ<T>::find_node(int pos){
    Node<T> *temp = root;
    int index = pos;
    while (temp != nullptr){
        if(index == 1){
            return temp; 
        }
        temp = temp->right;
        index--;
    }
    return temp;
}

template<class T> 
void PRQ<T>::order_down(){
    int index = size; 
    Node<T> *parent = find_node(size/2); 
    Node<T> * kid = find_node(size); 
    
    while (index > 1){
        Node<T> *parent = find_node(index / 2);
        Node<T> *kid = find_node(index);
        if (parent->data < kid->data){
            swap(parent, kid);
            order_down(); 
        }
        index--; 
    }
}

template<class T> 
void PRQ<T>::swap(Node<T> *A, Node<T> *B){
   T temp = A->data;
    A->data = B->data; 
    B->data = temp;  
}

template<class T> 
void PRQ<T>::operator = (Double_Linked_List<T> e){
    for(int i = 0; i<e.get_size(); i++){
        insert(e[i]); 
    }
    order_down(); 
}

template<class T> 
T PRQ<T>::remove(){
    if(size == 0 ){
        throw invalid_argument("heap is empty"); 
    }
    else{
        if(root->right == nullptr){
            T data = root->data; 
            root = nullptr;
            size--; 
            return data; 
        }
        else{
        Node<T> *prevLast = find_node(size-1);  
        T data = root->data; 
        swap(root,prevLast->right); 
        delete prevLast->right; 
        prevLast->right = nullptr;
        size--; 
        order_down(); 
        return data; 
        }
    }
}

template<class T> 
Double_Linked_List<T> PRQ<T>::heap_sort(){
    Double_Linked_List<T> list; 
    
    while(size > 0){
        list.add_first(remove());   
    }
    return list; 
}


#endif //PRQ_h