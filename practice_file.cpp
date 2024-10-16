#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high, int &cnt){
    int left = low;
    int right = mid+1;
    vector<int> temp;

    while(left<=mid && right<=high){
        if (arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
            cnt +=  mid - left + 1;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i<=high; i++){
        arr[i]=temp[i-low];
    }
}
void mergeSort(vector<int> &arr, int low, int high, int &cnt){
    if(low>=high)return;

    int mid = (low+high)/2;
    mergeSort(arr,low,mid,cnt);
    mergeSort(arr,mid+1,high,cnt);
    merge(arr,low,mid,high,cnt);
}
int numberOfInversions(vector<int> &arr, int n){
    int cnt = 0;
    mergeSort(arr,0,n-1,cnt);
    return cnt;
}
int optimal(vector<int> &arr, int n){
    cout<<"Optimal: ";
    int res = numberOfInversions(arr,n);
    return res;
    
}
vector<int> better(vector<int> &arr, int n){
    cout<<"Better: ";
    
}
int brute(vector<int> &arr, int n){
    cout<<"Brute: ";
    int cnt = 0;
    for(int i = 0; i<n; i++){ 
        for(int j = i+1; j<n; j++){
            if(arr[i]>arr[j])cnt++;
        }
    }
    return cnt;
}
int main() {
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);
    // cout<<brute(arr,arr.size());
    cout<<optimal(arr,arr.size());
    return 0;
    
}
