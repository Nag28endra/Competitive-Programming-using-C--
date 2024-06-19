#include<bits/stdc++.h>
using namespace std;
int optimal(vector<int> arr, int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        int missing = arr[mid]-(mid+1);

        if(missing<k)low = mid + 1;
        else high = mid - 1;
    }
    return high+k+1;
}
int brute(vector<int> arr, int k){

    for(int i=0; i<arr.size(); i++){
        // we are checking the element in the data structure is less than k or not. if it is then we'll increase k value. The moment the element exceeds the k value, then the k is our missing value.
        if(arr[i]<=k)k++;
        else break;
    }
    return k;
}
int main()
{
    vector<int> arr;
    int input;
    while(cin>>input)arr.push_back(input);
    cout<<"brute: "<<brute(arr,4);
    cout<<"\noptimal: "<<optimal(arr,4);
    return 0;
}