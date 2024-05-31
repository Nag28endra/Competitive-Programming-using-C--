#include<bits/stdc++.h>
using namespace std;
int optimalApproach(vector<int> &arr){
    int i = 0;

    for (int j = 1 ; j<arr.size(); j++){
        if (arr[j]!= arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return (i+1);
}
int bruteForce(vector<int> &arr){
    set<int> uarr;

    for (int i = 0; i<arr.size(); i++){
        uarr.insert(arr[i]);
    }
    return uarr.size();
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=  EOF) arr.push_back(input);
    cout<<"Brute force approach: "<<bruteForce(arr);
    cout<<"\nOptimal approach: "<<optimalApproach(arr);
    return 0;
}