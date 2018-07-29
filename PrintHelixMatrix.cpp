#include<iostream>
#include<vector>
#include "common.h"

using namespace std;
// 打印螺旋矩阵，从外向内，递归实现
void HelixMatrix(vector<vector<int> >& mat, int num, int size, int start){
    
    if(size == 0){
        return;
    }
    if(size == 1){
        mat[start][start]  = num;
        return;
    }
    int i, j;
    i = j = start;
    for(int k = 0; k<size-1; k++){
        mat[i][j++] = num++;
    }
    for(int k=0;k<size-1;k++){
        mat[i++][j] = num++;
    }
    for(int k=0;k<size-1;k++){
        mat[i][j--] = num++;
    }
    for(int k=0;k<size-1;k++){
        mat[i--][j] = num++;
    }
    start++;
    size -= 2;
    HelixMatrix(mat, num, size, start);
}

// size从1开始增加， 从外向内
void ArrowMatrix(vector<vector<int> >& mat, int num, int size, int start){
    if(size == 0){
        return;
    }
    if(size == 1){
        mat[start][start] = num;
    }
    int i, j;
    // start from col-dim
    if(size % 2 == 0){
        i = 0;j = start;
        for(int k=0;k<size-1;k++){
            mat[i++][j] = num--;
        }
        for(int k=0;k<size;k++){
            mat[i][j--] = num--;
        }
    }
    // start from row-dim
    else{
        i = start;j=0;
        for(int k=0;k<size-1;k++){
            mat[i][j++] = num--;
        }
        for(int k=0;k<size;k++){
            mat[i--][j] = num--;
        }
    }
    size--;
    start--;
    ArrowMatrix(mat, num, size, start);
}

int main(void){
    int n, m;
    cin>>n>>m;
    if(m != n){
        cout<<"Invalid matrix input ..."<<endl;
        return -1;
    }
    vector<vector<int> > mat(n, vector<int>(m, 0));
    cout<<"*** Helix Matrix *****"<<endl;
    HelixMatrix(mat, 1, m, 0);
    common::printVector2D(mat);
    cout<<"*** Arrow Matrix ***"<<endl;
    ArrowMatrix(mat, n*n, n, n-1);
    common::printVector2D(mat);
    return 0;
}