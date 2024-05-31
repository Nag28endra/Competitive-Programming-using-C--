#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v;
    int input;

    while(cin>>input and input!=EOF){
        v.emplace_back(input);
    }
    cout<<v.size()<<endl;
    for(auto i:v)cout<<i<<" ";
    return 0;
}