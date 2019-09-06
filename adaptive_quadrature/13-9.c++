#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#define TOL 1e-5

using namespace std;

float f(float x){
return exp(2*x)*sin(3*x);
}

float simpsons(float a, float b, int n){
float s1 = 0,s2 = 0;
int i;
float h = (b-a)/n; 

for(i=1; i <= n-1; i++){
if(i%2 == 0)
s1 = s1 + f(a+(i*h)); 
else
s2 = s2 + f(a+(i*h));
}

float s = (h/3)*(f(a)+ f(b) + (2*s1) + (4*s2));
return s;
}

float adapt_quad(float a, float b){
//ofstream f1;
//f1.open("ad", std::ios_base::app);
float s1 = simpsons(a,b,2);
float s2 = simpsons(a,b,4);
if(abs(s1-s2)/15.0<TOL)
return s2;
else{
//f1<<"1 "<<(a+b)/2.0<<"\n";
return adapt_quad(a,(a+b)/2.0) + adapt_quad((a+b)/2.0,b);
}
}

int main(){
float a=1.0,b=3.0;

std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
std::cout.precision(6);

/*
ofstream f2;
f2.open("f");
for(float i=1.0 ;i<=3.0; i+=0.001){
f2<<i<<"\t"<<f(i)<<"\n";
}*/
float c = adapt_quad(a,b);
cout<<"Adaptive Quadrature\n"<<c<<"\n\nComposite Simpsons Method with accuracy:\n";
for(int i=2;abs(adapt_quad(a,b)-simpsons(a,b,i))>TOL;i+=2){
cout<<simpsons(a,b,i)<<" "<<i<<" "<<abs(adapt_quad(a,b)-simpsons(a,b,i))<<"\n";
}

return 0;
}
