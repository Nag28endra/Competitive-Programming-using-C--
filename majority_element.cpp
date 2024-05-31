#include<bits/stdc++.h>
using namespace std;

int optimalApproach(vector<int> &arr, int n){
    int cnt = 0, element;
    for(int i =0; i<n; i++){
        if(cnt == 0){
            cnt = 1;
            element = arr[i];
        }
        else if (arr[i]==element)cnt++;
        else cnt--;
    }
    int counter = 0;
    for(int i = 0; i<n; i++){
        if( arr[i]==element)counter++;
    }
    if(counter>(n/2))return element;
    else return -1;
}
int betterApproach(vector<int> &arr, int n){
    map<int, int> mpp;
    
    for(int i = 0; i<n ; i++)mpp[arr[i]]++;

    for(auto i: mpp){
        if(i.second>(n/2))return i.first;
    }
    return -1;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.push_back(input);
    cout<<"Better :"<<betterApproach(arr,arr.size());
    cout<<"\nOptimal :"<<optimalApproach(arr,arr.size());
    return 0;
}