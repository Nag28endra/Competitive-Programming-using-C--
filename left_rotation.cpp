#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.emplace_back(input);

    int temp = arr[0];
    for (int i = 1; i<arr.size(); i++){
        arr[i-1]= arr[i];
    }
    arr[arr.size()-1]=temp;

    for (auto i:arr)cout<<i<<" ";
    return 0;
}