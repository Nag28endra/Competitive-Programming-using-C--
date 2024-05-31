#include<bits/stdc++.h>

using namespace std;

int permutationDifference(string s, string t){
    map<int, char> sV;
    map<int, char> tV;

    if (s.length() == t.length()){
        for(int i= 0; i<s.length(); i++){
            sV[i]=s[i]; 
            tV[i]=t[i];
        }
    }
    int sum = 0;
    for (int i = 0; i<sV.size(); i++){
        for (int j =0 ; j<tV.size();j++){
            if (sV[i]==tV[j]){
                sum += abs(i-j);
            }
        }
    }
    return sum;
}

int main()
{
    string s,t;
    getline(cin,s);
    getline(cin,t);
    int res = permutationDifference(s,t);
    cout<<res;
    return 0;
}