#include<bits/stdc++.h>
using namespace std;
bool optimalApproach(vector<int> &arr, int k){
    cout<<"\nOptimal: ";
    sort(arr.begin(),arr.end());
    int left = 0, right = arr.size()-1;

    while(left<right){
        if(arr[left]+arr[right]>k)right--;
        else if(arr[left]+arr[right]<k)left++;
        else{
            return true;
        }
    }
    return false;
}
void betterApproach(vector<int> &arr, int k){
    map<int,int> mpp;
    cout<<"\nBetter: ";
    for(int i = 0; i<arr.size(); i++){
        int rem = k-arr[i];
        if(mpp.find(rem)!=mpp.end()){
            cout<<mpp[rem]<<" "<<i;
        }
        mpp[arr[i]] = i;
    }
}
void bruteApproach(vector<int> &arr, int k){
    cout<<"Brute: ";
    for(int i = 0; i<arr.size(); i++){
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i]+arr[j] == k){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.push_back(input);

    bruteApproach(arr,11);
    betterApproach(arr,11);
    cout<<optimalApproach(arr,28);
    return 0;
}