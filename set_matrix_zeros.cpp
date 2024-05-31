#include<bits/stdc++.h>
using namespace std;

void optimalApproach(int matrix[3][4]){
    cout<<"Optimal Approach:\n";
    int col0=1;
    for(int i = 0; i<3; i++){
        for (int j = 0; j<4; j++){
            if (matrix[i][j]==0){
                matrix[i][0]=0; // marking row

                //marking the column
                if(j!=0)
                    matrix[0][j]=0;
                else
                    col0 =0;

            }
        }
    }

    for(int i =1; i<3; i++){
        for (int j = 1; j<4; j++){
            if (matrix[i][j]!=0){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    
    if (matrix[0][0]==0){
        for (int j = 0; j<4;j++){
            matrix[0][j]=0;
        }
    }
    if (col0==0){
        for(int i = 0; i<3; i++){
            matrix[i][0]=0;
        }
    }

    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void betterApproach(int matrix[3][4]){
    int row[3]={0};
    int col[4]={0};

    cout<<"better approach:\n";
    for(int i = 0; i<3; i++){
        for (int j = 0; j<4;j ++){
            if (matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i<3; i++){
        for (int j = 0; j<4; j++){
                if (row[i] || col[j])
                    matrix[i][j]=0;
        }
    }

    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void markRow(int matrix[3][4], int row){
    for(int col =0 ; col<4; col++){
        if (matrix[row][col]!=0)matrix[row][col]=-1;
    }
}
void markCol(int matrix[3][4], int col){
    for (int row = 0; row<3; row++){
        if (matrix[row][col]!=0)matrix[row][col]=-1;
    }
}
void bruteApproach(int matrix[3][4]){
    for (int row = 0; row<3; row++){
        for(int col =0; col<4; col++){
            if(matrix[row][col]==0){
                markRow(matrix,row);
                markCol(matrix,col);
            }
        }
    }
    for (int row = 0; row<3;row++){
        for(int col =0; col<4; col++){
            if(matrix[row][col]==-1){
                matrix[row][col]=0;
            }
        }
    }
    for (int row = 0; row<3;row++){
        for(int col =0; col<4; col++){
            cout<<matrix[row][col]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int matrix[3][4]= { 
          {1,1,0,1},
          {1,1,1,1},
          {1,0,1,0},
    };

    // bruteApproach(matrix);
    // betterApproach(matrix);
    optimalApproach(matrix);
    return 0;
}