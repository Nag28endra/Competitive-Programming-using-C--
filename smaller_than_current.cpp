#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {7,7,7,7};
    vector<int> res;

    for(int i = 0; i<v.size() ;i++){
        int count = 0;
        for(int j = 0; j<v.size() ; j++){
            if(v[i]>v[j])count++;
        }
        res.emplace_back(count);
    }
    for(auto i:res)cout<<i<<" ";
    return 0;
}