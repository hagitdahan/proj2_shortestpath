#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>
#define P 5     
#define C 20
/*return the maximum of two products*/
int max(int x,int y){
    if(x>y) return x;
    else return y;
}
/*this function create the table and enter to selcted_bool the select items and return the max value of all the products*/
int selectItems(int weights[],int values[],int selected_bool[]){
    /*create the table*/
    int mat[P+1][C+1];
    for(int i=0;i<=P;i++){ 
        for(int j=0;j<=C;j++){
            if(i==0||j==0)
            { mat[i][j]=0; }
            else if(weights[i-1]<=j) 
            {mat[i][j]=max(mat[i-1][j],values[i-1]+mat[i-1][j-(weights[i-1])]);}
            else {mat[i][j]=mat[i-1][j];}
        }
    }
    int i=P;
    int j=C;
    while(i>0 && j>0){
        if(mat[i][j]==mat[i-1][j]) {
             i=i-1; 
            selected_bool[i]=0;
           
        }
        else{
            i=i-1;
            selected_bool[i]=1;
            j=j-weights[i];
            
        }
    }
    
 return mat[P][C];
    
}

int main(){
    int selected_bool[P];
    char products[P];
    int values[P]={0};
    int weights[P]={0};
    for(int i=0;i<P;i++){
        scanf(" %c",&products[i]);
        scanf("%d",&values[i]);
        scanf("%d",&weights[i]);
    }
    int n=selectItems(weights,values,selected_bool);
    printf("Maximum profit: %d\n",n);
    printf("Selected items:");
    for(int i=0;i<P;i++){
        if(selected_bool[i]==1) {
            printf(" %c",products[i]);
        }
    }
    
    
    return 0;
}