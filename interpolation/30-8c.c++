#include <iostream>
#include<cmath> 
using namespace std; 

float u_cal(float u, int n){ 
float temp = u; 
for (int i = 1; i < n; i++){ 
temp = temp * (u - i); 
}
return temp; 
} 

int fact(int n){ 
int f = 1; 
for (int i = 2; i <= n; i++){
f *= i; 
}
return f; 
} 

int main() 
{ 
int n = 6; 
float x[] = { 1.0,1.3,1.6,1.9,2.2,2.5 }; 
 
float y[n][n]; 
y[0][0] = 0.7651977; 
y[1][0] = 0.6200860; 
y[2][0] = 0.4554022; 
y[3][0] = 0.2818186;
y[4][0] = 0.1103623;
y[5][0] = -0.0483838; 

//-----Forward Difference-----//
for (int i = 1; i < n; i++) { 
for (int j = 0; j < n - i; j++) 
y[j][i] = y[j + 1][i - 1] - y[j][i - 1]; 
} 

float sum = y[0][0]; 
float u = (1.5 - x[0]) / (x[1] - x[0]); 
for (int i = 1; i < n; i++){ 
sum = sum + (u_cal(u, i) * y[0][i]) / fact(i); 
} 
cout << "Forward difference " << sum << endl;

//-----Backward difference-----//
for (int i = 1; i < n; i++) { 
for (int j = n - 1; j >= i; j--){ 
y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
} 
}  
  
sum = y[n - 1][0]; 
u = (1.5 - x[n - 1]) / (x[1] - x[0]); 
for (int i = 1; i < n; i++) { 
sum = sum + (u_cal(u, i) * y[n - 1][i]) / fact(i); 
} 
cout << "Backward difference " << sum << endl;
 
return 0; 
} 
