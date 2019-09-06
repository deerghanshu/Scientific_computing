#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

float f(float y){return exp(y);}

float w[21],h=0.01,r[21];

float y(float t){return 1.0 - log(1.0 - exp(1.0) * t);}

float g(float x, int i){
return w[i] + h*(9*exp(x) + 19*exp(w[i]) - 5*exp(w[i-1]) + exp(w[i-2]))/24;
}

float predictor(int i){
return r[i] + h*(55*f(r[i]) - 59*f(r[i-1]) + 37*f(r[i-2]) - 9*f(r[i-3]))/24;
}

float fn(float x, int i){return 9*exp(x) + 19*exp(w[i]) - 5*exp(w[i-1]) + exp(w[i-2]);}
float dfn(float x){return 9*exp(x) ;}

int main(){

std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
std::cout.precision(6);

float er1[21],er2[21];

w[0] = 1.0;
for(int i=0;i<3;i++){
float k1 = f(w[i]);
float k2 = f(w[i]+k1*h/2.0);
float k3 = f(w[i]+k2*h/2.0);
float k4 = f(w[i]+k3*h);
w[i+1] = w[i] + (h/6.0)*(k1+2*k2+2*k3+k4);
er1[i] = abs(w[i] - y((i)*h));
}

/*w[0]=y(0);
w[1]=y(h);
w[2]=y(2*h);*/

for(int i=2;i<=21;i++){
float s=w[i];
int j=0;
do{
s = g(s,i);
j =j + 1;
}while(abs(s-g(s,i))>=1e-2);
w[i+1] = s; 
}
for(int i=0;i<=20;i++){
er1[i] = abs(w[i] - y(i*h));
}

/*for(int i=0;i<21;i++){
float x0,x1=w[i];
cout<<x1<<"\t";
do{
x0 = x1;
x1 = x0 - fn(x0,i)/dfn(x0);
}while(abs(x1-x0)>=1e-15);
cout<<x1<<"\t"<<y(i*h)<<"\n";
}*/

cout<<"\n";
//predictor-corrector
r[0] = 1.0;
for(int i=0;i<4;i++){
float k1 = f(r[i]);
float k2 = f(r[i]+k1*h/2.0);
float k3 = f(r[i]+k2*h/2.0);
float k4 = f(r[i]+k3*h);
r[i+1] = r[i] + (h/6.0)*(k1+2*k2+2*k3+k4);
er2[i] = abs(r[i] - y(i*h));
}

/*r[0]=y(0);
r[1]=y(h);
r[2]=y(2*h);
r[3]=y(3*h);
*/

for(int i=3;i<20;i++){
r[i+1] = g(predictor(i),i);
er2[i+1] = abs(r[i+1] - y((i+1)*h));
}

cout<<"\t\t"<<"Exact"<<"\t\t"<<"Implicit"<<"\t"<<"Error"<<"\t\t"<<"Pred-corrector"<<"   "<<"Error"<<"\n";
for(int i=0;i<=20;i++){
cout<<i*h<<"\t"<<y(i*h)<<"\t"<<w[i]<<"\t"<<er1[i]<<"\t"<<r[i]<<"\t"<<er2[i]<<"\n";
}

return 0;
}

