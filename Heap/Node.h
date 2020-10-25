#ifndef Node_h 
#define Node_h

template<class T> 
struct Node{
    T data; 
    Node<T> *right; 
    Node<T> *left; 
    Node<T>(T data); 
    Node<T>(T data, Node<T> *right, Node<T> *left); 
};

template<class T>
Node<T>::Node(T data){
    this-> data = data; 
    right = nullptr; 
    left = nullptr; 
}

template<class T> 
Node<T>::Node(T data, Node<T> *right, Node<T> *left){
    this->data  = data; 
    this->right = right; 
    this->left = left; 
}






#endif // Node_h
