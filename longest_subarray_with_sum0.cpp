#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> &arr, int n){
    int maxi = 0;
    int sum = 0;
    map<int,int> mpp;

    for(int i = 0 ; i<n; i++){
        sum += arr[i];
        if(sum == 0)maxi = i+1;
        else{
            if(mpp.find(sum)!=mpp.end()){
                maxi = max(maxi, i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
    }
    return maxi;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);
    cout<<optimal(arr,arr.size());
    
    return 0;
}