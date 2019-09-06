#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

float x(float y);
float l(float y, int k);
float f[4];

int main(){
f[0] = 0.740818;
f[1] = 0.670320;
f[2] = 0.606531;
f[3] = 0.548812;
float x0 = 0.0;
for (int i=0;i<4;i++){
x0 = x0 + l(0,i)*x(f[i]);
}
cout<<x0<<"\n";
return 0;
}

float g(float y){
return -log(y)-1/y;
}

float x(float y){
float x1;
x1 = -log(y);
return x1;
}

float l(float y, int k){
float m1=1.0, m2=1.0;
for(int j=0;j<4;j++){
if(j != k){
m1 = m1*(y-g(f[j]));
m2 = m2*(g(f[k])-g(f[j]));
}
}
return m1/m2;
}

