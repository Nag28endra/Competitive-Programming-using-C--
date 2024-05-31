#include "bits/stdc++.h"

using namespace std;

int main(){
    vector<int> v;
    int input;
    while(cin>>input and input!=EOF) v.push_back(input);
    int count = 0;
    for (int i = 0 ; i<v.size() ; i++){
        for (int j = i+1; j<=v.size()-1; j++){
            if (v[i]==v[j])count++;
        }
    }
    cout<<count;
    return 0;
}