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
    int maxValue=0;
    int mat[P+1][C+1];
    for(int i=0;i<=P;i++){ 
        for(int j=0;j<=C;j++){
            if(i==0||j==0)
            { mat[i][j]=0; }
            else if(weights[i]<=j) 
            {mat[i][j]=max(mat[i-1][j],values[i]+mat[i-1][j-(weights[i])]);}
            else {mat[i][j]=mat[i-1][j];}
        }
    }
    int i=P;
    int j=C;
    while(i>0 && j>0){
        if(mat[i][j]==mat[i-1][j]) {
            selected_bool[i-1]=0;
            i=i-1; 
        }
        else{
            selected_bool[i-1]=1;
            j=j-weights[i];
            i=i-1;
        }
    }
    for(int i=0;i<P;i++){
        if(selected_bool[i]==1){
        maxValue=maxValue+values[i+1];
    }
}
    
 return maxValue;
    
}

int main(){
    int selected_bool[P];
    char products[P+1];
    int values[P+1];
    int weights[P+1];
    values[0]=0;
    weights[0]=0;
    for(int i=0;i<P+1;i++){
        scanf(" %c",products[i]);
        scanf("%d",values[i+1]);
        scanf("%d",weights[i+1]);
    }
    int n=selectItems(weights,values,selected_bool);
    printf("Maximum profit: %d\n",n);
    char maxProd[6];
    int indexP=0;
    for(int i=0;i<P;i++){
        if(selected_bool[i]==1) {
            maxProd[i]=products[i];
            indexP++;
        }
    }
    printf("%d",indexP);
    maxProd[indexP+1]='\0';
    if(indexP>0) printf("Selected items:");
    while(indexP>0){
        printf(" %c",maxProd[indexP]);
        indexP--;
    }
    printf("\n");
    
    return 0;
}