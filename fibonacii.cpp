// Write a program to calculate Fibonacci numbers and find its step count. 
#include <iostream>
using namespace std;

int stepCount=0;

int FibIterative(int n){
    stepCount++; // for n<=1 stepcount increased by 1
    if(n<=1){
        stepCount++; // for return statement 
        return n;
    }
    
    int a=0,b=1,c;
    stepCount+=2; // for a and b , c isnt initialised with value so no stepCount
    
    stepCount++; // for int i=2 initialization 
    for(int i=2;i<=n;i++){
        stepCount++; // for every loop i runs for condition check
        c=a+b; 
        a=b;
        b=c;
        stepCount+=3; // for above 3 statement

    }
    stepCount++; //When i becomes n+1, the condition is checked one last time and fails.
    stepCount++; // for return statement
    return b;
    
}
// here n is the index so n=3 will give 1 as ans 
int fibRecursive(int n){
    stepCount++; // for the if statement
    if(n<=1){
        stepCount++; // for return statement 
        return n;
    }
    stepCount++;
    return fibRecursive(n-1)+fibRecursive(n-2);
}

int main(){
    
    int n;
    cout<<"Enter n: ";
    cin>>n;
    stepCount=0;
    int r1=FibIterative(n);
    cout<<"Step Count = "<<stepCount<<endl;
    cout<<"For n="<<n<<" Result is "<<r1<<endl;
    
    
    stepCount=0;
    
    int r2=fibRecursive(n);
    cout<<"Step Count = "<<stepCount<<endl;
    cout<<"For n="<<n<<" Result is "<<r2;
    
    
}