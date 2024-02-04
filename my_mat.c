#include <stdio.h>
#define N 3
/*this function create matrix from the input of the user*/
void buildMat(int mat[][N]){
    printf("please enter %d numbers: \n",(N*N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &mat[i][j]);
        }
    }
}
/*this function return the minimum value*/
int min(int x,int y){
    if(x<y) return x;
    else return y;
}
/*this function creat the A^n matrix with the shorset path*/
void calculateMatrix(int mat[][N]){
    int x,y,z;
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                x=mat[i][j];
                y=mat[i][k];
                z=mat[k][j];
                if(i!=j){
                    if(x!=0 && (y==0 || z==0)){
                            mat[i][j]=x;
                        }
                    else if(y==0)
                        mat[i][j]=0;
                    else if(z==0)
                        mat[i][j]=0;
                    else mat[i][j]=min(x,y+z);
                }
            }
        }
    }
}

int thereIsPath(int i,int j,int mat[][N]){
    if(mat[i][j]!=0) return 1;
    else return 0;
}
int shorsetPath(int i,int j, int mat[][N]){
    if(mat[i][j]!=0) return mat[i][j];
    else return -1;
}
