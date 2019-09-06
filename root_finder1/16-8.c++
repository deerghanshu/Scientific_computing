#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>

using namespace std;
float f1(float x){
return exp(x) - x - 1;
}

float df1(float x){
return exp(x) - 1;
}

float f2(float x){
return x - 0.8 - 0.2*sin(x);
}

float df2(float x){
return 1.0 - 0.2*cos(x);
}

int main(){
    float p1 = -1.0, p;
    
    //-----Newton-----//
    cout<<"Q1. \nNewton Method"<<"\n";
    int i=1;
    do{
        p = p1;
        p1 = p - f1(p)/df1(p);
        cout<<i<<setw(20)<<p1<<'\n';
    	i=i+1;
    }while(fabs(p1-p) > 1e-6);
    cout<<"\n";
    
    //-----Secant-----//
    cout<<"\nSecant Method"<<"\n";
    i=1;
    p1 = -1.0;
    float p_2 = 1.0;
    do{
        p = p1;
        p1 = p - (f1(p)*(p-p_2)/(f1(p)-f1(p_2)));
        cout<<i<<setw(20)<<p1<<'\n';
        i=i+1;
        p_2 = p;
    }while(fabs(p1-p) > 1e-6);
    cout<<"\n";
    
    //-----Bisection-----//
    cout<<"\nBisection Method"<<"\n";
    i=1;
    p = -1.0;
    p_2 = 1.0;
    while ((p_2-p) >= 1e-6)
    {
        p1 = (p+p_2)/2;
        if (f1(p1) == 0.0){
        cout <<i<<setw(20)<< p1<<endl;
        break;
        }
        else if (f1(p1)*f1(p) < 0){
        cout <<i<<setw(20)<< p1<<endl;
        p_2 = p1;
        }
        else{
        cout << i<<setw(20)<< p1<<endl;
        p = p1;
        }
        i++;
    }
    cout<<"\n";
    
    p1=0.0;
   //-----Newton-----//
    cout<<"Q2. \nNewton Method"<<"\n";
    i=1;
    do{
        p = p1;
        p1 = p - f2(p)/df2(p);
        cout<<i<<setw(20)<<p1<<'\n';
    	i=i+1;
    }while(fabs(p1-p) > 1e-4);
    cout<<"\n";
    
    //-----Secant-----//
    cout<<"\nSecant Method"<<"\n";
    i=1;
    p1 = 0.0;
    p_2 = acos(-1.0)/2.0;
    do{
        p = p1;
        p1 = p - (f2(p)*(p-p_2)/(f2(p)-f2(p_2)));
        cout<<i<<setw(20)<<p1<<'\n';
        i=i+1;
        p_2 = p;
    }while(fabs(p1-p) > 1e-6);
    cout<<"\n";
    
    //-----Bisection-----//
    cout<<"\nBisection Method"<<"\n";
    i=1;
    p = 0.0;
    p_2 = acos(-1.0)/2.0;
    while ((p_2-p) >= 1e-4)
    {
        p1 = (p+p_2)/2;
        if (f2(p1) == 0.0){
        cout <<i<<setw(20)<< p1<<endl;
        break;
        }
        else if (f2(p1)*f2(p) < 0){
        cout <<i<<setw(20)<< p1<<endl;
        p_2 = p1;
        }
        else{
        cout << i<<setw(20)<< p1<<endl;
        p = p1;
        }
        i++;
    }
    return 0;
}

