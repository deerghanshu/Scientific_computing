#include<iostream>
#include<cmath>
#include<fstream>
#define pi acos(-1.0)

using namespace std;
int main()
{
ofstream f;
f.open("exact");
ofstream f1;
f1.open("9x13");


int i,j,k,m,n;
float a[20][20];
m=9,n=13;
float dx=10.0/(m-1), dy=15.0/(n-1);


for(i=1;i<=m;i++)   //assigning boundary values begins
{
a[i][1]=0.0;
a[i][n]=100.0*sin(pi*(i-1)*dx/10.0);
}
for(i=1;i<=n;i++)
{
a[1][i]=0.0;
a[m][i]=0.0;
}                         //assigning boundary values ends


for(i=2;i<m;i++)
for(j=2;j<n;j++)
a[i][j]=0.0; //initialization of interior grid points 

float beta2 = pow((dx/dy),2);
for(int k=0;k<100;k++){
for(int i=2;i<m;i++){
for(int j=2;j<n;j++){
a[i][j]=(a[i-1][j]+a[i+1][j]+(a[i][j-1]+a[i][j+1])*beta2)/(2.0*(1.0 + beta2));
}
}
}                     
        
for(j=1;j<=n;j++){
for(i=1;i<=m;i++){
float ex = 100*(sinh(pi*(j-1)*dy/10.0)*sin(pi*(i-1)*dx/10.0))/(sinh(pi*15.0/10.0));
if(ex<1e-8) ex=0.0;
float er = abs(a[i][j] - ex);
f1<<(i-1)*dx<<"\t"<<(j-1)*dy<<"\t"<<a[i][j]<<"\t"<<ex<<"\t"<<er<<"\n";
}
}

return 0;
}


