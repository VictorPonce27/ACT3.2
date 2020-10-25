#ifndef Double_Linked_List_h
#define Double_Linked_list_h

#include "Node.h"

template<class T>
class Double_Linked_List{
private:
    int size;
    Node<T> *head;
    Node<T> *tail;
public:
    Double_Linked_List();
    Double_Linked_List(initializer_list<T> e);
    void add_first(T newData);
    void add_last(T newData);
    bool delete_at(int idex);
    bool is_empty();
    void insert_at(int index, T newData);
    T& operator[](int index);
    T get_data(int index);
    void update_at(int index, T newData);
    void print();
    // void Print(); 
    void print_backwards();
    void clear();
    int get_size();
    // void m_sort(int low,int mid, int high, Node<T> *nLeft, Node<T> *nMid, Node<T> *nRight);
    void sorti(int low, int high, Node<T> *nleft, Node<T> *nright);
    void sort();
    void operator=(Double_Linked_List<T> *e);
    void operator=(T *e);
    Node<T>* search(Node<T> *temp, int index);
};
template<class T>
Double_Linked_List<T>::Double_Linked_List(){
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<class T>
Double_Linked_List<T>::Double_Linked_List(initializer_list<T> e){
    size = 0;
    for(auto i:e){
        if(is_empty()){
            head = new Node<T>(i);
            tail = head;
            size++;
        }
        else{
            Node<T> *aux = head;
            while(aux->right !=nullptr){
                aux = aux->right;
            }
            aux->right = new Node<T>(i,nullptr,aux);
            tail = aux->right;
            size++;
        }
    }
}

template<class T>
void Double_Linked_List<T>::add_first(T newData){
    if(is_empty()){
         head = new Node<T>(newData);
         tail = head;
         size++;
    }
    else{
        head = new Node<T>(newData,head,nullptr);
        head->right->left = head;
        size++;
    }
}
template<class T>
void Double_Linked_List<T>::add_last(T newData){
    if(is_empty()){
        head = new Node<T>(newData);
        tail = head;
        size++;
    }
    else{
        tail = new Node<T>(newData,nullptr,tail);
        tail->left->right = tail;
        size++;
    }
}


template<class T>
bool Double_Linked_List<T>::is_empty(){
    return size == 0;
}

// template<class T>
// void Double_Linked_List<T>::Print(){
//     Node<T> *aux = head;
//     ofstream outfile; 
//     outfile.open("OutPutFile.txt");
//     while(aux != nullptr){
//         outfile << aux->data.Print();
//         outfile <<"\n";
//         aux = aux->right;
//     }
//     cout << endl;
//     outfile.close();
// }

template<class T>
void Double_Linked_List<T>::print(){
    Node<T> *aux = head;;
    while(aux != nullptr){
        cout << aux->data<<" ";
        aux = aux->right;
    }
    cout << endl;
}

template<class T>
void Double_Linked_List<T>::print_backwards(){
    Node<T> *aux = tail;
    while(aux != nullptr){
        cout<< aux->data<<" ";
        aux = aux->left;
    }
    cout<<endl;
}

template<class T>
bool Double_Linked_List<T>::delete_at(int index){
    if(!is_empty()){
        if(size/2 >= index){
            int pos = 0;
            Node<T> *temp = head->right;
            if(pos == index && temp != nullptr){
                delete head;
                head = temp;
                temp->left = nullptr;
                size--;
                return true;
            }
            else if(pos == index){
                head = nullptr;
                tail = nullptr;
                size--;
                return true;
            }
            else{
                Node<T> *aux = head;
                while(aux->right != nullptr){
                    if(pos+1 == index){
                        if(aux->right->right != nullptr){
                            Node<T> *temp = aux->right->right;
                            delete aux->right;
                            aux->right = temp;
                            temp->left = aux;
                            size--;
                            return true;
                        }
                        else{
                            delete aux->right;
                            aux->right = nullptr;
                            tail = aux;
                            size--;
                            return true;
                        }
                    }
                    aux = aux->right;
                    pos++;
                }
            }
        }
        else{
            int pos = size-1;
            Node<T> *temp = tail->left;
            if(pos == index && temp != nullptr){
                delete tail;
                tail = temp;
                temp->right = nullptr;
                size--;
                return true;
            }
            else{
                Node<T> *aux = tail;
                while(aux->left != nullptr){
                    if(pos-1 == index){
                        if(aux->left->left != nullptr){
                            Node<T> *temp = aux->left->left;
                            delete aux->left;
                            aux->left = temp;
                            temp->right = aux;
                            size--;
                            return true;
                        }
                        else{
                            delete aux->left;
                            aux->left = nullptr;
                            head = aux;
                            size--;
                            return true;
                        }
                    }
                    aux = aux->left;
                    pos--;
                }
            }
        }
    }
    return false;
}

template<class T>
void Double_Linked_List<T>::insert_at(int index, T newData){
    if ((index >= 0 || index < size) && size/2 >= index){
        int pos = 0;
        if (pos == index && pos == size){
            head = new Node<T>(newData, head, nullptr);
            tail = head;
            size++;
            return;
        }
        else if(pos == index){
            head = new Node<T>(newData, head, nullptr);
            head->right->left = head;
            if(size < 1){
                tail = head->right;
            }
            size++;
            return;
        }
        else{
            Node<T> *aux = head;
            while (aux->right != nullptr){
                if(pos + 1 == index && pos + 1 == size){
                    aux->right = new Node<T>(newData, aux->right, aux->left);
                    tail = aux->right;
                    size++;
                    return;
                }
                else if (pos + 1 == index){
                    aux->right = new Node<T>(newData, aux->right, aux);
                    aux->right->right->left = aux->right;
                    size++;
                    return;
                }
                aux = aux->right;
                pos++;
            }
        }
    }
    else if(index >= 0 || index < size){
        int pos = size;
        if (pos == index){
            tail = new Node<T>(newData,nullptr,tail);
            tail->left->left->right = tail;
            size++;
            return;
        }
        else{
            Node<T> *aux = tail;
            while (aux->left != nullptr){
                if(pos - 1 == index){
                    aux->left = new Node<T>(newData, aux, aux->left);
                    aux->left->left->right = aux->left;
                    size++;
                    return;
                }
                aux = aux->left;
                pos--;
            }
        }
    }
    throw runtime_error("index is out of range");
}

template<class T>
T& Double_Linked_List<T>::operator[](int index){
    if(index>=1 || index <= size){
        if(size/2 > index){
            Node<T> *aux = head;
            int pos = 1 ;
            while(aux != nullptr){
                if(pos == index){
                    return aux->data;
                }
            pos++;
            aux = aux->right;
            }
        }
        else{
            Node<T> *aux = tail;
            int pos = size;
            while(aux != nullptr){
            if(pos == index){
                return aux->data;
            }
            pos--;
            aux = aux->left;
            }
        }
    }
    throw out_of_range("index out of range");
}

template<class T>
void Double_Linked_List<T>::clear(){
     if(!is_empty()){
        Node<T> *aux = head->right;
        while(head->right!= nullptr){
            head->right = aux->right;
            delete aux;
            aux = head->right;
        }
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }
    throw runtime_error("list is empty");
}

template<class T>
int Double_Linked_List<T>::get_size(){
    return size;
}


template<class T>
void Double_Linked_List<T>::operator=(Double_Linked_List<T> *e){
    clear();
    for(int i=0; i<e->size();i++){
        add_last(e[i]);
    }
}

template<class T>
void Double_Linked_List<T>::operator=(T *e){
    head->data = e;
}

template<class T>
void Double_Linked_List<T>::update_at(int index, T newData){
    Node<T> *aux = head;
    int pos = 0;
    bool found = false;
    while (aux!= nullptr){
        if(pos == index){
            aux->data = newData;
            return;
        }
        pos++;
        aux = aux->right;
    }
        throw runtime_error("value not found");
}

template<class T>
T Double_Linked_List<T>::get_data(int index){
    Node<T> *aux = head;
    int pos = 0;
    while(aux != nullptr){
        if(pos == index){
            return aux->data;
        }
        aux = aux->right;
        pos++;
    }
    throw out_of_range("value not found");
}


// template <class T>
// void Double_Linked_List<T>::m_sort(int low,int mid, int high, Node<T> *nLeft, Node<T> *nMid, Node<T> *nRight){
//     Queue<T> L;
//     Queue<T> R;
//     int i = 0;
//     int j = 0;
//     int n = mid-low +1;
//     int m = high- mid;

//     Node<T> *tempPos = nLeft;

//     for(int i=0;i<n;i++){
//         L.enqueue(nLeft->data);
//         nLeft = nLeft->right;
//     }

//     for(int j=0;j<m;j++){
//         R.enqueue(nMid->right->data);
//         nMid = nMid->right;
//     }

//     while (i < n && j < m) {
//         if (L.front()->data <= R.front()->data) {
//             tempPos->data = L.dequeue();
//             i++;
//         }
//         else {
//             tempPos->data = R.dequeue();
//             j++;
//         }
//         tempPos = tempPos->right;
//     }

//     while (i < n) {
//         tempPos->data = L.dequeue();
//         tempPos = tempPos->right;
//         i++;
//     }

//     while (j < m) {
//         tempPos->data = R.dequeue();
//         tempPos = tempPos->right;
//         j++;
//     }

// }

template <class T>
void Double_Linked_List<T>::sorti(int low, int high, Node<T> *nLeft, Node<T> *nRight){
    if(low<high){
        int mid = (low+high)/2;
        Node<T> *nMid = search(nLeft, mid-low);
        sorti(low,mid,nLeft, nMid);
        sorti(mid+1,high, nMid->right, nRight);
        m_sort(low,mid,high, nLeft, nMid, nRight);
    }
}
template<class T>
void Double_Linked_List<T>::sort(){
  sorti(0,size-1,head,tail);
}

template <class T>
Node<T>* Double_Linked_List<T>::search(Node<T> *temp, int index){
    Node<T> *aux = temp;
    for(int i=0; i<index; i++){
        aux = aux->right;
    }
    return aux;
}

#endif //Double_Linked_list_h
