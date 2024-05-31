#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int input;
    cout<<"Insertion sort\n";
    while(cin>>input && input!=EOF)v.emplace_back(input);

    for(int i = 0; i<v.size() ; i++){
        int  j = i;
        while (j>0 && v[j-1]>v[j]){
            int temp = v[j-1];
            v[j-1]=v[j];
            v[j]=temp;

            j--;
        }
    }
    for(auto i:v)cout<<i<<" ";
    return 0;
}