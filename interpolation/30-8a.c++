#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int n=11;
float x[11];
float z[22];

float l(float y, int k);
float f(float y);
float fh(int t,int r);
float fd(float y);

int main(){
ofstream f2;
ofstream f1;
f2.open("lagrange");
f1.open("hermite");
float a = -5.0 , b = 5.0;
for (int i=0;i<n;i++){
x[i] = a + i*(b-a)/(n-1);
}
for(int i=0;i<2*n;i++){
z[i] = x[i/2];
}

//-----Lagrange Interpolation-----//
float c=a,fx;
do{
fx = 0.0;
for (int i=0;i<n;i++){
fx = fx + l(c,i)*f(x[i]);
}
f2<<c<<"  "<<fx<<" "<<f(c)<<endl;
c = c + 0.001;
}while(c<=b);

//-----Hermite Interpolation-----//
float d = a;
do{
float fx1 = f(z[0]);
for (int i=2;i<=2*n;i++){
float q = (d-z[0]);
for(int j=1;j<i-1;j++){
q=q*(d-z[j]);
}
fx1 = fx1 + fh(i,0)*q;
}
f1<<d<<"  "<<fx1<<" "<<f(d)<<endl;
d = d + 0.01;
}while(d<=b);
return 0;
}

float l(float y, int k){
float m1=1.0, m2=1.0;
for(int j=0;j<n;j++){
if(j != k){
m1 = m1*(y-x[j]);
m2 = m2*(x[k]-x[j]);
}
}
return m1/m2;
}

float f(float y){
float f1;
f1 = 1/(1+pow(y,2));
return f1;
}

float fd(float y){
float f2;
f2 = -2*y/pow((1+pow(y,2)),2);
return f2;
}

float fh(int t,int r){
if(t==1){
	return f(z[r]);
}
else if(t==2 && r%2==0){
	return fd(z[r/2]);
}
else{
return (fh(t-1,r+1)-fh(t-1,r))/(z[r+t-1] - z[r]);
}
}
