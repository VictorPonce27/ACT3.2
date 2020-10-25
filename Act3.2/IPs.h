#ifndef IPs_h
#define IPs_h

#include<iostream>
#include<string>

using namespace std;

struct IPs{
    string ip;
    int reps;
    IPs();
    IPs(string ip); 
    IPs(string ip, int reps); 
    bool operator<(IPs data);
    bool operator>(IPs data);
    bool operator==(IPs data);
    void print();  
};

IPs::IPs(){

}
IPs::IPs(string IPS){
    this->ip = ip;
    reps = 0; 
}

IPs::IPs(string ip, int reps){
    this->ip = ip; 
    this->reps =  reps; 
}

bool IPs::operator<(IPs data){
    return (this->reps < data.reps); 
}

bool IPs::operator>(IPs data){
    return (this->reps > data.reps); 
}

bool IPs::operator==(IPs data){
    return (this->ip == data.ip); 
}

void IPs::print(){
    cout<<"Ip: "<<ip<<" repeats: "<<reps<<" times"<<endl;
}



#endif //IPs_h