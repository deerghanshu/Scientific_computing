#include<iostream>

using namespace std;

int main(){
 // a
   double n=1,count=0.0,k,app; 
   while(n<=10000){
      count=count+(1/n);
      n++;
    }
   cout<<"a) sum = "<<count<<endl;
 // b
    n=1;
    count=0.0;
    while(n<=10000){
       k=1.0/n;
       app=(int) (k*100000.0)/100000.0 ;
       count=count+app;
       n++;
   }
    cout<<"b) sum = "<<count<<endl;
  // c
    n=10000;
    count=0.0;
    while(n>=1){
       k=1.0/n;
       app=(int) (k*100000.0)/100000.0 ;
       count=count+app;
       n--;
   }
    cout<<"c) sum = "<<count<<endl;
 

}
       
    
    
      
