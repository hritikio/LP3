#include <iostream>
using namespace std;


int board[8][8]; 
//row 0-7 col 0-7 

bool safe(int row,int col){
    //This function checks whether we can place a Queen at the given position.
    
    //checking same column 
    for(int i=0;i<row;i++){
        if(board[i][col]==1)
        return false;
    }
    
    //checking upper-left diagonal
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]==1)
        return false;
        
    }
    
    //checking upper-right diagonal 
    for(int i=row-1,j=col+1;i>=0 && j<8 ; i--,j++){
        if(board[i][j]==1)
        return false;
        
    }
    // we can place the queen on (row,col) it is safe
    return true;
    
}


bool solve(int row){
    if(row==8)
    return true;
    
    for(int col=0;col<8;col++){
        if(safe(row,col)){
            board[row][col]=1; //place a queen
            
            if(solve(row+1))
            return true;
            
            board[row][col]=0;
            
        }
    }
    return false;//no solution found 
}


int main(){
    board[0][0]=1; //placing the first queen 
    
    if(solve(1)){ //starts backtracking from row 1
         cout << "8 Queens Matrix:\n";
         
         for(int i=0;i<8;i++){
             for(int j=0;j<8;j++){
               cout<<board[i][j]<<" ";
             }
             cout<<endl;
         }
        
    }else{
        cout<<"solution does not exist";
    }
}

