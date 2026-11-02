// Write a program to solve a fractional Knapsack problem using a greedy
//method.

#include <iostream>
#include <algorithm>
using namespace std;

struct Item{
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a , Item b){
    return a.ratio>b.ratio;
}

double FractionalKnapsnack(Item items[],int n, int capacity){
    // n is number of items 
    // return maximum profit 
    sort(items,items+n,compare); //Sorts all n items using our compare rule.
    double totalProfit=0.0;
    int remaining=capacity;
    
    
    for(int i=0;i<n;i++){
        if(items[i].weight<=remaining){ //Checks: does the whole item fit in the remaining space?
            remaining-=items[i].weight; //Yes, it fits, so we take the full item. The remaining space reduces by the item’s weight.
            totalProfit+=items[i].profit;
            
        }else{//The item does not fit completely, so we take only a part of it.
           totalProfit+=items[i].profit * ((double)remaining/items[i].weight);
           break;
           
        }
    }
    return totalProfit;
    
    
}

int main(){
    int n ,capacity;
    cout<<"Enter the number of Items: ";
    cin>>n;
    
    Item items[n];
    
    for(int i=0;i<n;i++){
        cout<<"Enter weigth and profits of Item"<<i+1<<" :";
        cin>>items[i].weight>>items[i].profit;
        items[i].ratio=(double)items[i].profit/items[i].weight;
    }
    
    cout<<"Enter Capacity of Knapsnack ";
    cin>>capacity;
    
    
    double maxProfit=FractionalKnapsnack(items,n,capacity);
    cout<<"Maximum profit = "<<maxProfit<<endl;
}
