#include <iostream>
using namespace std;

#include "Heap.h"
int main(){
    Double_Linked_List<int> list = {8,5,17,19,21,28};
    list.print(); 
    Heap<int> heap = list;
    heap.print(); 
    heap.insert(20); 
    heap.print(); 
    
    return 0;
}
