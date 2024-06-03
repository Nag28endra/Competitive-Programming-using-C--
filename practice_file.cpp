#include <bits/stdc++.h>
using namespace std;

int optimal(vector<int> &arr, int n){
    int Sum = 0;
    int maxSum = INT_MIN;
    for(const auto &i:arr){
        Sum +=i;
        maxSum = max(Sum,maxSum);
        if(Sum<0){
            Sum = 0;
        }
    }
    return maxSum;
}

void brute(vector<int> &arr, int n, int k){
    
}
int main() {
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.push_back(input);
    // brute(arr,arr.size(),15);
    
    cout<<"\noptimal:"<<optimal(arr,arr.size());
    return 0;
    
}
