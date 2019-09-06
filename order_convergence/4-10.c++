#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

double y[11],t[11],h;

double dy5(double y,double t){
return y/t - pow(y/t,2);
}
double y5(double t){
return t/(1.0+log(t));
}

double dy2(double y,double t){
return 1.0 + y/t + pow(y/t,2);
}
double y2(double t){
return t*tan(log(t));
}

double dy3(double y,double t){
return -(y+1)*(y+3);
}
double y3(double t){
return -3.0 + 2.0/(1.0 + exp(-2*t));
}

double dy4(double y,double t){
return -5*y + 5*t*t + 2*t;
}
double y4(double t){
return t*t + exp(-5*t)/3.0;
}

double ey(double n){
int a;
a = floor((n-t[0])/h);
return y[a]+ ((n-t[0])/h-a)*(y[a+1] - y[a]);
}

int main(){

cout.precision(6);
cout.setf( std::ios::fixed, std:: ios::floatfield );

ofstream f;
f.open("a");
cout<<"t"<<"\t"<<"y(t)"<<"\t\t"<<"y_exact(t)"<<endl<<endl;

y[0] = 1.0;
t[0] = 1.0;
f<<t[0]<<"\t"<<y[0]<<"\t"<<y5(t[0])<<endl;
h=0.1;
for (int i=1;i<11;i++){
t[i] = t[i-1] + h;
y[i] = y[i-1] + dy5(y[i-1],t[i-1])*h;
f<<t[i]<<"\t"<<y[i]<<"\t"<<y5(t[i])<<endl;
}
f<<endl;
cout<<"1.25"<<"\t"<<ey(1.25)<<"\t"<<y5(1.25)<<endl;
cout<<"1.93"<<"\t"<<ey(1.93)<<"\t"<<y5(1.93)<<endl;
cout<<endl;


y[0] = 0.0;
t[0] = 1.0;
f<<t[0]<<"\t"<<y[0]<<"\t"<<y2(t[0])<<endl;
h=0.2;
for (int i=1;i<11;i++){
t[i] = t[i-1] + h;
y[i] = y[i-1] + dy2(y[i-1],t[i-1])*h;
f<<t[i]<<"\t"<<y[i]<<"\t"<<y2(t[i])<<endl;
}
f<<endl;
cout<<"2.1"<<"\t"<<ey(2.1)<<"\t"<<y2(2.1)<<endl;
cout<<"2.75"<<"\t"<<ey(2.75)<<"\t"<<y2(2.75)<<endl;
cout<<endl;


y[0] = -2.0;
t[0] = 0.0;
f<<t[0]<<"\t"<<y[0]<<"\t"<<y3(t[0])<<endl;
h=0.2;
for (int i=1;i<11;i++){
t[i] = t[i-1] + h;
y[i] = y[i-1] + dy3(y[i-1],t[i-1])*h;
f<<t[i]<<"\t"<<y[i]<<"\t"<<y3(t[i])<<endl;
}
f<<endl;
cout<<"1.3"<<"\t"<<ey(1.3)<<"\t"<<y3(1.3)<<endl;
cout<<"1.93"<<"\t"<<ey(1.93)<<"\t"<<y3(1.93)<<endl;
cout<<endl;


y[0] = 1.0/3;
t[0] = 0.0;
f<<t[0]<<"\t"<<y[0]<<"\t"<<y4(t[0])<<endl;
h=0.1;
for (int i=1;i<11;i++){
t[i] = t[i-1] + h;
y[i] = y[i-1] + dy4(y[i-1],t[i-1])*h;
f<<t[i]<<"\t"<<y[i]<<"\t"<<y4(t[i])<<endl;
}
f<<endl;
cout<<"0.54"<<"\t"<<ey(0.54)<<"\t"<<y4(0.54)<<endl;
cout<<"0.94"<<"\t"<<ey(0.94)<<"\t"<<y4(0.94)<<endl;


return 0;
}

