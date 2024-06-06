#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
     int left = low; 
     int right = mid + 1;

     vector<int> temp;

     while(left<=mid && right<=high){
        if (arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
     }
     while(left<=mid){
        temp.push_back(arr[left++]);
     }
     while(right<=high){
        temp.push_back(arr[right++]);
     }

     for(int i = low; i<=high; i++){
        arr[i] = temp[i-low];
     }
}
int countPairs(vector<int> &arr, int low, int mid, int high){
    int cnt = 0 ;
    int right = mid + 1;

    for(int i = low; i<=mid; i++){
        while(right<=high && arr[i]>2*arr[right])right++;

        cnt += (right - (mid+1));
    }

    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if (low>=high) return cnt;
    int mid = (low+high)/2;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return cnt;
}
int optimal(vector<int> &arr, int n){
    /*
        Time complexity: O(nlogn)-merge sort+O(N)-countPairs but not N^2 since we are not iterating every element in the right sorted array.
        Space complexity: O(N)
    */
    return mergeSort(arr,0,n-1);
}
int brute(vector<int> &arr, int n ){
    /* 
        Time complexity: O(N^2)
        Space complexity: O(1)
     */

    int cnt = 0;

    for(int i = 0; i<n; i++){
        for(int j =i+1; j<n; j++){
            if(arr[i]>2*arr[j])cnt++;
        }
    }
    return cnt;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);
    // cout<<"brute:"<<brute(arr,arr.size());
    cout<<"optimal:"<<optimal(arr,arr.size());
    return 0;
}