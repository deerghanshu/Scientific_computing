#include<iostream>
#include<cmath>
#include<fstream>
#define pi acos(-1.0)

using namespace std;

float ue(float x, float t){
return exp(-t)*sin(pi*x/2.0) + exp(-t/4)*sin(pi*x/4.0);
}

float ux(float x){
return sin(pi*x/4.0)*(1.0+2.0*cos(pi*x/4.0));
}

int main(){

int Nt=10,Nx=20;
float dt,dx;
dt = 0.4/Nt;
dx = 4.0/Nx;
float l = (4.0/(pi*pi))*(dt/pow(dx,2));

float u[Nx+1][Nt+1]={0};

ofstream f1;
f1.open("forward");
ofstream f2;
f2.open("backward");
ofstream f3;
f3.open("crank-nicolson");

for(int i=0;i<=Nx;i++)
u[i][0] = ux(i*dx);

for(int j=0;j<=Nt;j++){
u[0][j] = 0.0;
u[Nx][j] = 0.0;
}

//-----forward difference-----//
for(int j=1;j<=Nt;j++){
for(int i=1;i<=Nx-1;i++)
u[i][j] = u[i][j-1] + l*(u[i+1][j-1] - 2*u[i][j-1] + u[i-1][j-1]);
}

for(int i=0;i<=Nx;i++)
f1<<i*dx<<"\t"<<u[i][Nt]<<"\t"<<ue(i*dx,0.4)<<"\n";


//-----backward difference-----//
float w[Nx-1],b[Nx-1];

for(int j=0;j<Nt;j++){

for(int i=0;i<Nx-1;i++)
b[i] = u[i+1][j];

float e[Nx-2],f[Nx-1],g[Nx-2];

for(int i=0;i<Nx-1;i++){
e[i] = -l;
f[i] = 1.0+2.0*l;
g[i] = -l;
}

for(int i=0;i<Nx-1;i++){
e[i] = e[i]/f[i];
f[i+1] = f[i+1] - e[i]*g[i];
b[i+1] = b[i+1] - e[i]*b[i];
}

w[Nx-2] = b[Nx-2]/f[Nx-2];
for(int k=Nx-3;k>=0;k--)
w[k] = (b[k] - g[k]*w[k+1])/f[k];
for(int i=0;i<Nx-1;i++)
u[i+1][j+1] = w[i];

}

for(int i=0;i<=Nx;i++)
f2<<i*dx<<"\t"<<u[i][Nt]<<"\t"<<ue(i*dx,0.4)<<"\n";

//-----crank-nicoloson-----//
l=l/2.0;
for(int j=0;j<Nt;j++){

for(int i=0;i<Nx-1;i++)
b[i] = l*u[i][j] + (1-2.0*l)*u[i+1][j] + l*u[i+2][j];

float e[Nx-2],f[Nx-1],g[Nx-2];

for(int i=0;i<Nx-1;i++){
e[i] = -l;
f[i] = 1.0+2.0*l;
g[i] = -l;
}

for(int i=0;i<Nx-1;i++){
e[i] = e[i]/f[i];
f[i+1] = f[i+1] - e[i]*g[i];
b[i+1] = b[i+1] - e[i]*b[i];
}

w[Nx-2] = b[Nx-2]/f[Nx-2];
for(int k=Nx-3;k>=0;k--)
w[k] = (b[k] - g[k]*w[k+1])/f[k];
for(int i=0;i<Nx-1;i++)
u[i+1][j+1] = w[i];

}

for(int i=0;i<=Nx;i++)
f3<<i*dx<<"\t"<<u[i][Nt]<<"\t"<<ue(i*dx,0.4)<<"\n";

return 0;
}

