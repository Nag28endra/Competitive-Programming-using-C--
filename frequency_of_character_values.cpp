#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    map<char,int> mpp;   

    for(int i = 0; i<s.length(); i++){
        if(isalnum(s[i]))
            mpp[s[i]]++;
    }

    for(auto i:mpp)cout<<i.first<<"->"<<i.second<<endl;
    return 0;
}