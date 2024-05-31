#include<bits/stdc++.h>
using namespace std;
void Reverse(vector<int> &res, int start, int end){
    while(start<=end){
        swap(res[start],res[end]);
        start++;
        end--;
    }
}
void optimalApproach(vector<int> &arr, int n){
    vector<int> res;
    int maxi = INT_MIN;
    cout<<"\nOptimal :";
    for(int i =n-1;i>=0; i--){
            if(arr[i]>maxi){
                res.push_back(arr[i]);
            }
            maxi = max(maxi,arr[i]);
    }
    Reverse(res,0,res.size()-1);
    for(auto i:res)cout<<i<<" ";
}
void bruteApproach(vector<int> &arr, int n){
    vector<int> res;

    cout<<"Brute: ";
    for(int i = 0;i<n;i++){
        bool flag = true;
        for(int j=i+1;j<n; j++){
            if (arr[j]>arr[i]){
                flag = false;
                break;
            }
        }
        if (flag==true)res.push_back(arr[i]);
    }
    for(auto i:res)cout<<i<<" ";
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.push_back(input);
    bruteApproach(arr,arr.size());
    optimalApproach(arr,arr.size());
    return 0;
}