#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findSum(vector<int> arr,int window_size){
    int sum = 0;
    int maxSum = INT_MIN;
    int l = 0;
    int r = window_size - 1;

    for(int i=l ;i<=r; i++){
        sum += arr[i];
    }
    maxSum = max(maxSum,sum);
    while(r < arr.size()-1){
        sum -= arr[l];
        l++;
        r++;
        sum += arr[r];

        maxSum = max(sum,maxSum);
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {-1,2,3,4,5,-1};
    cout<< findSum(arr,4);
    return 0;
}