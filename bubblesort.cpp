#include<bits/stdc++.h>
using namespace std;

int main()
{
     vector<int> v;
     int input;
     cout<<"Bubble Sort\n";
     while(cin>>input && input != EOF){
        v.emplace_back(input);
     }

     for(int i = v.size()-1; i>=1; i--){
        for(int j= 0; j<=i-1; j++){
            if(v[j]>v[j+1]){
               int temp = v[j];
               v[j] = v[j+1];
               v[j+1] = temp;
            }
        }
     }

     for(int i = 0; i<v.size(); i++)cout<<v[i]<<" ";

    return 0;
}