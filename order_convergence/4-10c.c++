#include<iostream>
#include<cmath>
using namespace std;


float dy5(float y,float t){
return y/t - pow(y/t,2);
}
float y5(float t){
return t/(1+log(t));
}

float dy2(float y,float t){
return 1.0 + y/t + pow(y/t,2);
}
float y2(float t){
return t*tan(log(t));
}

float dy3(float y,float t){
return -(y+1)*(y+3);
}
float y3(float t){
return -3.0 + 2.0/(1.0 + exp(-2*t));
}

float dy4(float y,float t){
return -5*y + 5*t*t + 2*t;
}
float y4(float t){
return t*t + exp(-5*t)/3.0;
}

int main(){

float t,y,h;
float e;

h=0.1;
do{
y = 1.0;
t = 1.0;
e=0.0;
do{
y = y + dy5(y,t)*h;
t = t + h;
e =e + abs(y - y5(t));
}while(t<=2.0);
cout<<h<<"\t"<<e*h<<endl;
h=h/10;
}while(h>1e-7);
cout<<endl;


h=0.2;
do{
y = 0.0;
t = 1.0;
e=0.0;
do{
y = y + dy2(y,t)*h;
t= t + h;
e =e + abs(y - y2(t));
}while(t<=3.0);
cout<<h<<"\t"<<e*h/2.0<<endl;
h=h/10;
}while(h>1e-7);
cout<<endl;

h=0.2;
do{
y= -2.0;
t = 0.0;
e=0.0;
do{
y = y + dy3(y,t)*h;
t = t + h;
e =e + abs(y - y3(t));
}while(t<=2.0);
cout<<h<<"\t"<<e*h/2.0<<endl;
h=h/10;
}while(h>1e-7);
cout<<endl;

h=0.1;
do{
y = 1.0/3;
t = 0.0;
e=0.0;
do{
y = y + dy4(y,t)*h;
t = t + h;
e =e + abs(y - y4(t));
}while(t<=1.0);
cout<<h<<"\t"<<e*h<<endl;
h=h/10;
}while(h>1e-8);
cout<<endl;


return 0;
}

