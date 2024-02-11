#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10
int main(){
    int matrix [N][N];
    char ch;
    int i=0;
    int j=0;
    int run = scanf("%c",&ch);
    while (ch!=68 && run!=EOF)
    {
        if(ch == 65) {
            buildMat(matrix);
        }
        calculateMatrix(matrix);
        if(ch == 66){
            scanf("%d %d",&i,&j);
            if(thereIsPath(i,j,matrix)==1)
                printf("True\n");
            else printf("False\n");
        }
        if(ch == 67 ){
            scanf("%d %d",&i,&j);
            int n=shorsetPath(i,j,matrix);
            printf("%d\n",n);
        }
        scanf("%c",&ch);
    }
    return 0;
}