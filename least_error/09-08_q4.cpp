#include<iostream>

#define _USE_MATH_DEFINES 
using namespace std;
int main(){
  double e=1,count=0;
  while(e>0){
     e=e/2;
     count++;
  }
   cout<<count<<endl;
}
