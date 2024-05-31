#include<bits/stdc++.h>
using namespace std;

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
    return 0;
}