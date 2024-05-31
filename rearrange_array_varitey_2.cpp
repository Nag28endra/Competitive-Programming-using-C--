#include<bits/stdc++.h>
using namespace std;

void betterApproach(vector<int> &arr, int n){
    vector<int> pos;
    vector<int> neg;

    for (int i =0 ;i <n; i++){
        if(arr[i]>0)pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    if(pos.size()>neg.size())
    {
        for(int i = 0; i<neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int idx = neg.size()*2;
        for(int i = neg.size();i<pos.size(); i++){
            arr[idx]=pos[i];
            idx++;
        }
    }
    else{
        for(int i = 0; i<pos.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int idx = pos.size()*2;
        for(int i = pos.size();i<neg.size(); i++){
            arr[idx]=neg[i];
            idx++;
        }
    }
    for (auto i: arr)cout<<i<<" ";
}
int main()
{
    vector<int> arr={3,2,-1,4,-3,4};

    betterApproach(arr, arr.size());
    return 0;
}