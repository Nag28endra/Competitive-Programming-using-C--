#include<bits/stdc++.h>
using namespace std;

int optimalApproach(vector<int> &arr, int n, int k){
    int prefixSum = 0;
    int cnt = 0;
    map<int,int> mpp;
    mpp[0] = 1;
    for(int i=0;i<n;i++){
        prefixSum += arr[i];
        int rem = prefixSum - k;
        cnt += mpp[rem];
        mpp[prefixSum] += 1;
    }
    return cnt;
}
int betterApproach(vector<int> &arr,int n,int k){
    int cnt = 0;

    for(int i = 0;i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum +=arr[j];

            if(sum ==k)cnt++;
        }
    }
    return cnt;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.push_back(input);
    cout<<"Better:"<<betterApproach(arr,arr.size(),3);
    cout<<"\nOptimal:"<<optimalApproach(arr,arr.size(),3);
    return 0;
}