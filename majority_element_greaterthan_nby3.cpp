#include<bits/stdc++.h>
using namespace std;

void optimal(vector<int> &arr, int n){
    int cnt1 =0, cnt2= 0;
    int el1,el2;
    cout<<"\nOptimal:"<<" ";
    for(int i = 0; i<n; i++){
        if(cnt1==0 && arr[i]!=el2){
            cnt1 = 1;
            el1 = arr[i];
        }
        else if (cnt2 ==0 && arr[i]!=el1){
            cnt2 = 1;
            el2 = arr[i];
        }

        else if(arr[i]==el1)cnt1++;
        else if (arr[i]==el2)cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]==el1)cnt1++;
        else if (arr[i]==el2)cnt2++;
    }
    int mini =(int)(n/3)+1;
    vector<int> res;
    if (cnt1>=mini)res.push_back(el1);
    if (cnt2>= mini)res.push_back(el2);
    sort(res.begin(),res.end());
    for(auto i: res)cout<<i<<" ";
}
void better(vector<int> &arr, int n){
    map<int, int> mpp;
    vector<int> res;
    int mini = (int)(n/3)+1;

    cout<<"\nBetter:"<<" ";
    for(int i = 0; i<n; i++){
        mpp[arr[i]]++;

        if(mpp[arr[i]]>=mini)res.push_back(arr[i]);
        if(res.size()==2)break;
    }
    sort(res.begin(),res.end());
    for(auto i: res)cout<<i<<" ";

    //Time complexity: O(N)*O(logN) Space complecity: O(1)
}
void brute(vector<int> arr,int n){
    vector<int> res;
    cout<<"Brute:"<<" ";
    int mini = (int)(n/3)+1;
    for(int i = 0; i<n ;i++){
        int cnt = 0;
        for(int j = i; j<n; j++){
            if(arr[i]==arr[j])cnt++;  
        }
        if (cnt>=mini)res.push_back(arr[i]);
        if(res.size()==2)break;
    }
    for(auto i: res)cout<<i<<" ";
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.push_back(input);
    brute(arr,arr.size());
    better(arr,arr.size());
    optimal(arr,arr.size());
    return 0;
}