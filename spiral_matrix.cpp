#include<bits/stdc++.h>
using namespace std;

void spiralMatrix(vector<vector<int>> &matrix, int row, int col){
    int left = 0;
    int top = 0;
    int right = col-1;
    int bottom = row-1;
    vector<int> res;

    while(left<=right && top<=bottom){
        //right;

        for(int i = left; i<=right; i++){
            res.push_back(matrix[top][i]);
        }
        top++;

        //bottom
        for(int i = top; i<=bottom; i++){
            res.push_back(matrix[i][right]);
        }
        right--;

        //left
        if(top<=bottom){
        for(int i=right;i>=left; i--){
            res.push_back(matrix[bottom][i]);
        }
        bottom--;
        }
        //top
        if(left<=right){
        for(int i = bottom; i>=top; i--){
            res.push_back(matrix[i][left]);
        }
        left++;
        }
    }

    for(auto i: res)cout<<i<<" ";
}
int main()
{
    vector<vector<int>> matrix = {
            {1,2,3},
            {4,5,6},
            {7,8,9},
            {10,11,12}
    };

    int row = matrix.size();
    int col = matrix[0].size();

    spiralMatrix(matrix,row,col);
    return 0;
}