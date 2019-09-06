#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

double dy(float t, float y){
return t*exp(3*t) - 2*y;
}

double ye(float t){
return 0.2*t*exp(3*t) - 0.04*exp(3*t) + 0.04*exp(-2*t);
}

int main(){

cout.precision(6);
cout.setf( std::ios::fixed, std:: ios::floatfield );

double k1,k2,k3,k4;
ofstream f;
f.open("rk");

ofstream f1;
f1.open("rk2");

ofstream f2;
f2.open("rk4");
int n=7;

double e2[n],e4[n];
double dt[n],h=0.2;


for(int i=0;i<n;i++){
dt[i] = h;
//RK2
double t=0.0;
double y = 0.0;
while(t<2.0){
k1 = dy(t,y);
k2 = dy(t+h,y+k1*h);
t=t+h;
y = y + 0.5*h*(k1+k2);
f1<<t<<"\t"<<y<<"\t"<<ye(t)<<"\n";
}
e2[i] = abs(y - ye(t));

//RK4
t=0.0;
y = 0.0;
while(t<2.0){
k1 = dy(t,y);
k2 = dy(t+h/2.0,y+k1*h/2.0);
k3 = dy(t+h/2.0,y+k2*h/2.0);
k4 = dy(t+h,y+k3*h);
t=t+h;
y = y + (h/6.0)*(k1+2*k2+2*k3+k4);
f2<<t<<"\t"<<y<<"\t"<<ye(t)<<"\n";
}
e4[i] = abs(y - ye(t));
f<<h<<"\t"<<e2[i]<<"\t"<<e4[i]<<"\n";
h=h/2.0;
}

double a1,a2;

cout<<"RK2"<<"\n"<<"h"<<"\t\t"<<"error"<<"\t\t"<<"alpha"<<endl;
cout<<dt[0]<<"\t"<<e2[0]<<"\n";
for(int i=1;i<n;i++){
a1 = log10(e2[i-1]/e2[i]) / log10(2.0);
cout<<dt[i]<<"\t"<<e2[i]<<"\t"<<a1<<"\n";
}
cout<<endl;

cout<<"RK4"<<"\n"<<"h"<<"\t\t"<<"error"<<"\t\t"<<"alpha"<<endl;
cout<<dt[0]<<"\t"<<e4[0]<<"\n";
for(int i=1;i<n;i++){
a2 = (log10(e4[i-1]/e4[i])) / log10(2.0);
cout<<dt[i]<<"\t"<<e4[i]<<"\t"<<a2<<"\n";
}

return 0;
}

















