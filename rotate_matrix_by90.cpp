#include<bits/stdc++.h>
using namespace std;
void Reverse(int matrix[3][3],int row, int start, int end){
    while(start<=end){
        swap(matrix[row][start],matrix[row][end]);
        start++;
        end--;
    }
}
void optimalApproach(int matrix[3][3]){
    cout<<"Optimal Approach:\n";
    int n = 3;
    for(int i = 0;i<n-1; i++){
        for(int j = i+1; j<n; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    for(int i = 0; i<n; i++){
            Reverse(matrix,i,0,n-1);
    }
    for (int i = 0; i<3; i++){
        for(int j =0; j<3; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void bruteApproach(int matrix[3][3]){
    int n = 3;
    int res[n][n];
    for (int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            res[j][n-1-i]= matrix[i][j];
        }
    }

    for (int i = 0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int matrix[3][3]= {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    // bruteApproach(matrix);
    optimalApproach(matrix);
    return 0;
}