#include<bits/stdc++.h>
using namespace std;
int betterApproach(vector<int> &arr,int k){
    map<long long, int> prefixSum;
    int maxLen = 0;
    long long sum = 0;

    for(int i= 0; i<arr.size(); i++){
        sum +=arr[i];

        if(sum == k){
            maxLen = max(maxLen, i+1);
        }

        long long rem = sum - k;
        if(prefixSum.find(rem) != prefixSum.end()){
            int Len = i - prefixSum[rem];
            maxLen = max(Len,maxLen);
        }

        if(prefixSum.find(sum) == prefixSum.end()){
            prefixSum[sum] = i;
        }

    }
    return maxLen;
}
int optimalApproach(vector<int> &arr, int k){
    int i=0,j = 0, sum = arr[0];
    int maxLen = 0;

    while(j<arr.size()){
        while(i<=j && sum>k){
            sum -= arr[i];
            i++;
        }

        if(sum == k) maxLen = max(maxLen, j-i+1);

        j++;
        if(j<arr.size()) sum  += arr[j];
    }
    return maxLen;
}
int bruteApproach(vector<int> &arr,int k){
    int len = 0;
    for(int i = 0; i<arr.size(); i++){
        int sum = 0;
        for (int j = i; j<arr.size(); j++){
            sum += arr[i];

            if(sum==k) len = max(len,j-i+1);
            if(sum>k) break;
        }
    }
    return len;
}
int main()
{
    int input,k;
    vector<int> arr;
    cin>>k;
    while(cin>>input && input!=EOF)arr.push_back(input);

    cout<<"Brute: "<<bruteApproach(arr,k);
    cout<<"\nOptimal: "<<optimalApproach(arr,k);
    cout<<"\nBetter: "<<betterApproach(arr,k);
    
    return 0;
}