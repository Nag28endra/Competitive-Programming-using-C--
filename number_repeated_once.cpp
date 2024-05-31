#include<bits/stdc++.h>
using namespace std;
int Brute(vector<int> &arr){
    map<long long, int> mpp;
    for (int i = 0; i<arr.size(); i++){
        mpp[arr[i]]++;
    }

    for (auto i: mpp){
        if(i.second==1)return i.first;
    }
}

int Optimal(vector<int> &arr){
    int res = 0;
    for(int i=0 ; i<arr.size(); i++){
        res = res^arr[i];
    }   
    return res;
}
int main()
{
    vector<int> arr;
    int input;
    while(cin>>input && input!=EOF) arr.push_back(input);
    cout<<"Brute :"<<Brute(arr);
    cout<<"\nOptimal: "<<Optimal(arr);
    
    return 0;
}