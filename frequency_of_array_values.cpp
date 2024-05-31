#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    map<int,int> hashArr;

    for(int i = 0; i<n ; i++){
        cin>>arr[i];
        hashArr[arr[i]]++;
    }
    
    for(auto i : hashArr){
        cout<<i.first<<"->"<<i.second<<endl;
    }

    return 0;
}