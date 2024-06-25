#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int col, int x){
    int low = 0;
    int high = col - 1;
    int res =  col;
    while(low<=high){
        int mid = (low+high)>>1;
        if(arr[mid]>=x){
            res = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return res;
}
int optimal(vector<vector<int>> arr, int row, int col){
    /*
        time complexity: O(rowlog(col))
    */
    int cntMax = 0;
    int index = -1;

    for(int i = 0; i<row; i++){
        int cntOnes = col - lowerBound(arr[i],col,1);
        if(cntOnes>cntMax){
            cntMax = cntOnes;
            index = i;
        }
    }
    return index;
}
int brute(vector<vector<int>> arr, int row, int col){
    /*
        time complexity: O(row*col)
    */
    int cntMax = 0;
    int index = -1;

    for(int i = 0; i<row; i++){
        int cntOnes = 0;
        for(int j = 0; j<col; j++){
            cntOnes += arr[i][j];
        }
        if(cntOnes>cntMax){
            cntMax = cntOnes;
            index = i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> arr = {
        {1,1,1},
        {0,0,1},
        {0,0,0}
    };
    cout<<"brute: "<<brute(arr,3,3);
    cout<<"\noptimal: "<<optimal(arr,3,3);
    return 0;
}