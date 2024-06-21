#include<bits/stdc++.h>
using namespace std;
int findArea(vector<int> arr, int area){
    int n = arr.size();
    int cntBoards = 1;
    long long partition = 0;

    for(int i = 0; i<n; i++){
        if (partition+arr[i]<=area){
            partition +=arr[i];
        }
        else{
            partition = arr[i];
            cntBoards++;
        }
    }
    return cntBoards;
}
int brute(vector<int> arr, int k){
    /*
        Time complexity: O(sum-max)xO(N)
    */
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    if(k>arr.size()) return -1;
    for(int i = low; i<=high; i++){
        int areas = findArea(arr,i);
        if(areas==k) return(i);
    }
    return -1;
}
int optimal(vector<int> arr, int k){
    /*
        Time complexity: O(log(sum-max))xO(N)
    */
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid = low + (high-low)/2;

        int splits = findArea(arr,mid);
        if(splits>k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
int main()
{
    vector<int> arr;
    int input;
    while(cin>>input)arr.push_back(input);
    cout<<"brute: "<<brute(arr,2);
    cout<<"\noptimal: "<<optimal(arr,2);
    return 0;
}