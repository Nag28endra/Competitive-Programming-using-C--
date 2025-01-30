#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void printS(vector<int>& arr, int n, int sum, int s,int idx,vector<int>& res){
    if (idx == n){
        if(s == sum){
            for(auto i: res)cout<<i<<" ";
        cout<<endl;
        }
        
        return;
    }
    // pick the element
    res.push_back(arr[idx]);
    s += arr[idx];
    printS(arr,n,sum,s,idx+1,res);

    // do not pick the element
    res.pop_back();
    s -= arr[idx];
    printS(arr,n,sum,s,idx+1,res);
    
}

int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    int sum;
    cin>>sum;
    for(int i=0; i<size;i++) cin>>arr[i];
    vector<int> res;
    printS(arr,arr.size(),sum,0,0,res);
    return 0;
}