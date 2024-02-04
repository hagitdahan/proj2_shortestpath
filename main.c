#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>
#define N 3
int main(){
    int matrix [N][N];
    char ch;
    int i,j;
    scanf("%c",&ch);
    while (ch!=68)
    {
        if(ch == 65) {
            buildMat(matrix);
        }
        calculateMatrix(matrix);
        if(ch == 66){
            scanf("%d %d",i,j);
            if(thereIsPath(i,j,matrix)==1)
                printf("True\n");
            else printf("False\n");
        }
        if(ch == 67){
            scanf("%d %d",i,j);
            int n=shorsetPath(i,j,matrix);
            printf("%d\n",n);
        }
        scanf("%c",&ch);
    }
    
    // printf("The old matrix is:\n");
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //        printf("%d     ",matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    //printf("\n");
    //printf("The new matrix is:\n");
    
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //        printf("%d      ",matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}