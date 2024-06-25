#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low+high)>>1;

        if(arr[mid]==target)return true;
        else if(arr[mid]>target) high = mid - 1;
        else low = mid  + 1;
    }
    return false;
}
bool optimal2(vector<vector<int>> matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();

    int row = 0;
    int col= m - 1;
    while(row<n && col>=0){
        if(matrix[row][col]==target) true;
        else if (matrix[row][col]>target) col--;
        else row++;
    }
    return false;
}
bool optimal(vector<vector<int>> matrix, int target){
    /*
        time complexity: O(log(n*m))
    */
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = (m*n) - 1;
    
    while(low<=high){
        int mid = (low + high)>>1;
        int row = mid/m;
        int col = mid%m;

        if(matrix[row][col]==target) return true;
        else if (matrix[row][col]>target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}
bool better(vector<vector<int>> matrix, int target){
    /*
        Time complexity: O(n) + O(logm)
    */
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i<n; i++){
        if(matrix[i][0]<= target && matrix[i][m-1]) return binarySearch(matrix[i],target);
    }
    return false;
}
bool brute(vector<vector<int>> matrix,int target){
    /*
        Time complexity: O(n*m)
    */
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m ; j++){
            if(matrix[i][j]==target) return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix{
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    cout<<"brute: "<<brute(matrix,3);
    cout<<"\nbetter: "<<better(matrix,3);
    cout<<"\noptimal: "<<optimal(matrix,3);
    // cout<<"\noptimal2: "<<optimal2(matrix,3);

    return 0;
}