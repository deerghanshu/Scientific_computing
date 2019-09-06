#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#define TOL 1e-6

using namespace std;

float arr[50];

float f1(float x){
return exp(x) - x - 1;
}

float df1(float x){
return exp(x) - 1;
}

float ddf1(float x){
return exp(x);
}

float f3(float x){
return pow(x,3) + 3*x*x -1.0;
}

float df3(float x){
return 3*x*x + 6*x;
}

float alpha(int i){
float e1,e2,e3;
e1 = abs(arr[i]-arr[i+1]);
e2 = abs(arr[i+1]-arr[i+2]);
e3 = abs(arr[i+2]-arr[i+3]);
return log(e2/e3)/log(e1/e2);
}

int main(){

std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
std::cout.precision(6);

int N = 50;
float p = -1.0, p1;

//-----Newton-----//
arr[0] = p=-1.0;
for(int i=1;i<N;i++){
arr[i] = p - f1(p)/df1(p);
p = arr[i];
}
cout<<"1. Newton Method"<<"\n";
for(int i =0;i<50;i++){
cout<<i<<"\t"<<arr[i]<<"\t"<<alpha(i)<<'\n';
if(abs(f1(arr[i]))<TOL) break;
}
cout<<"\n";

//-----Modified Newton-----//
arr[0]=p=-1.0;
for(int i=1;i<N;i++){
arr[i] = p - ((f1(p)*df1(p))/((df1(p)*df1(p))-(f1(p)*ddf1(p))));
p = arr[i];
}
cout<<"Modified Newton Method"<<"\n";
for(int i =0;i<50;i++){
cout<<i<<"\t"<<arr[i]<<"\t"<<alpha(i)<<'\n';
if(abs(f1(arr[i]))<TOL) break;
}
cout<<"\n";

//-----Fixed Point Iteration-----//
arr[0] = p = acos(-1.0)/4.0;
for(int i=1;i<N;i++){
arr[i]= cos(p);
p = arr[i];
}
cout<<"2. Fixed point iteration Method"<<"\n";
for(int i =0;i<50;i++){
cout<<i<<"\t"<<arr[i]<<"\t"<<alpha(i)<<'\n';
if(abs(arr[i] - cos(arr[i]))<TOL) break;
}
cout<<"\n";


//-----Newton-----//
arr[0]= p = -2.5;
for(int i=1;i<N;i++){
arr[i] = p - f3(p)/df3(p);
p = arr[i];
}
cout<<"3. Newton Method"<<"\n";
for(int i =0;i<50;i++){
cout<<i<<"\t"<<arr[i]<<"\t"<<alpha(i)<<"\n";
if(abs(f3(arr[i]))<TOL) break;
}
cout<<"\n";


//-----Secant-----//
arr[1] = p = -3.0;
float p0;
p0 = arr[0] = -2.0;
for(int i=2;i<N;i++){
arr[i] = p - (f3(p)*(p-p0)/(f3(p)-f3(p0)));
p0 = p;
p = arr[i];
}
cout<<"Secant Method"<<"\n";
for(int i =0;i<50;i++){
cout<<i<<"\t"<<arr[i]<<"\t"<<alpha(i)<<endl;
if(abs(f3(arr[i]))<TOL) break;
}
cout<<"\n";

return 0;
}

