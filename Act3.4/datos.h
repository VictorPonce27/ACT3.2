#pragma once

#include<iostream> 
#include<string>

using namespace std; 

struct datos{
private:
    string month; 
    int day; 
    int hour; 
    int min;
    int second; 
    int monthNum;
    int time; 
    string ip;
    string fail;

public:
    datos(); 
    datos(string month,int monthNum ,int day, int hour,int min,int second,string ip,string fail);
    void print();
    string Print();
    string get_month(); 
    string get_ip(); 
    int get_numMonth(); 
    int get_day();
    int get_hour(); 
    int get_min(); 
    int get_second();
    int get_time(); 
    void operator + (datos datos); 
    bool operator <= (datos datos);
    bool operator >= (datos datos);
    bool operator > (datos datos);     
    bool operator < (datos datos); 
    bool operator == (int time);    
    bool operator == (datos time); 
    bool operator <= (int time);
    bool operator>(int time);
    bool operator<(int time);
    // bool operator<=(datos datos);
};

datos::datos(){

}

datos::datos(string month,int monthNum ,int day, int hour,int min,int second,string ip,string fail){
    this-> month = month; 
    this-> day = day; 
    this-> hour = hour; 
    this-> min = min; 
    this-> second = second; 
    int index; 
    index = ip.find(":");
    this->ip  = ip.substr(0, index);
    this-> fail = fail;
    time = (monthNum*100000000)+(day*1000000)+(hour*10000)+(min*100)+second; 
}



void datos::print(){
     cout<<month<<" "<<day<<" "<<hour<<":"<<min<<":"<<second<<" "<<ip<<" "<<fail<<endl;
}

string datos::Print(){
    string temp; 
    //  temp = month + " " + to_string(day) + " " + to_string(hour) + ":" + to_string(min) + ":" + to_string(second )+ " " + ip + " " + fail;
    temp = "IP: " + ip; 
     return temp; 
}


int datos::get_day(){
    return day;
}

int datos::get_hour(){
    return hour; 
}

int datos::get_min(){
    return min;
}

int datos::get_second(){
    return second; 
}
string datos::get_month(){
    return month;
}

string datos::get_ip(){
    return ip; 
}

int datos::get_time(){
    return time; 
}


bool datos::operator<=(datos datos){
   return (time <= datos.get_time()); 
}

bool datos::operator>=(datos datos){
   return (time >= datos.get_time()); 
}

bool datos::operator>(datos datos){
    return (ip > datos.get_ip()); 
}

bool datos::operator<(datos datos)
{
    return (time < datos.get_time());
}

bool datos::operator<=(int time){
    return (this->time <= time); 
}

bool datos::operator==(int time){
    return(this->time == time); 
}

bool datos::operator ==(datos time){
    return(this->time == time.get_time()); 
}

bool datos::operator>(int time){
    return(this->time > time); 
}

bool datos::operator<(int time){
    return(this->time < time); 
}


// #endif //datosure object