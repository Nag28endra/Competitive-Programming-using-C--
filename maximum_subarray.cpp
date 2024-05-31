
#include <bits/stdc++.h>
using namespace std;

void optimalApproach(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0,ansStart=-1, ansEnd=-1;
    for(int i = 0; i<n ;i++){
        if(sum == 0) start = i;
        sum += arr[i];
        if(sum>maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum<0) sum = 0;
    }
    
    cout<<"Sub-array: [";
    for(int i = ansStart; i<=ansEnd; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]\n";
    cout<<maxi;
}
int main()
{
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    
     optimalApproach(arr,arr.size());

    return 0;
}
