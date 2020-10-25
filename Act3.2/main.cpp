//
//  By victor Ponce A00827302
//
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "datos.h"
#include "DoublyLinkedList.h"
#include "Heap.h"
#include "IPs.h"

int stringMonthToNum(string month){
    DoublyLinkedList<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int i = 1; i<months.getSize();i++){
        if(months[i] == month){
            return i;
        }
    }
    return 0;
}

// DoublyLinkedList<IPs> dups(DoublyLinkedList<datos> &list){
//     DoublyLinkedList<IPs> temp; 
//     IPs tempData; 
//     for(int i = 1; i<list.getSize(); i++){
//         int count = 0; 
//         for(int j = 1; j<list.getSize(); j++){
//             if(list[i].get_ip() == list[j].get_ip()){
//                 count++; 
//             }
//         }
//         tempData = IPs(list[i].get_ip(),count); 
//         if(!temp.inList(tempData)){
//             temp.addFirst(tempData);
//         }
//     }
//     return temp; 
// }

DoublyLinkedList<IPs> dups(DoublyLinkedList<datos> &list){
    DoublyLinkedList<IPs> temp; 
    IPs tempData; 
    int index = 1; 
    int count = 0; 
    int i = 1; 
    int j = 1; 
       while( j < list.getSize()){
            if(list[i].get_ip() == list[j].get_ip()){
                j++; 
            }        
            else{
                count = j - i; 
                tempData = IPs(list[i].get_ip(),count); 
                if(!temp.inList(tempData)){
                    temp.addFirst(tempData);
                }
                i = j; 
            }    
        }
    return temp; 
}

//TODO::Make algorithm that counts the number of repeated ips and it's done

int main(){
    DoublyLinkedList<datos> infoList;
    DoublyLinkedList<IPs> list2; 
    Heap<datos> heap;
    Heap<IPs> heap2; 
    string month;
    int day,hour,min,second,numMonth,start,end,date1,date2;
    string ip;
    string fail;
    string line;
    string type;
    char delim = ' ';
    bool done = false;
    bool next = false;

    //search variables
    int searchMonth1;
    int searchMonth2;
    int searchDay1;
    int searchDay2;
    int searchHour1;
    int searchHour2;

    ifstream inFile("bitacora2.txt");
    //adding the info to the doubly linked list
    if(inFile.is_open()){
        while(getline(inFile,line)){
            stringstream ss(line);
            getline(ss,type,' ');
            month = type;
            getline(ss,type,' ');
            day = stoi(type);
            getline(ss,type,':');
            hour = stoi(type);
            getline(ss,type,':');
            min = stoi(type);
            getline(ss,type,' ');
            second = stoi(type);
            getline(ss,type,' ');
            ip = type;
            getline(ss,type);
            fail = type;
            numMonth = stringMonthToNum(month);
            datos var(month, numMonth, day, hour, min, second, ip, fail);
            infoList.addLast(var);
        }
    }
    heap = infoList; 
    infoList = heap.sort(); 
    cout<<"checking duplicates"<<endl;
    heap2 = dups(infoList); 
    cout<<"Sorting heap 2"<<endl;
    list2 = heap2.sort(); 
    list2.print();
    return 0;
}
