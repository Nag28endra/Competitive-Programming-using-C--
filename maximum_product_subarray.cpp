#include<bits/stdc++.h>
using namespace std;
int optimal(vector<int> &arr, int n ){
    /*
        Time complexity: O(N)
        Space complexity: O(1)

        __int128_t is a special data type provided by the compiler to handle large integer values which exceed the size of int long and even long long.
    */
    __int128_t prefix = 1, suffix = 1, maxi = INT_MIN;

    for(int i = 0; i<n; i++){
        if(prefix == 0) prefix=1;
        if (suffix == 0)suffix = 1;

        prefix *=arr[i];
        suffix *=arr[n-i-1];

        maxi = max(maxi, max(prefix,suffix));
    }
    return maxi;
}
int better(vector<int> &arr, int n){

    /*
        Time complexity: O(N^2)
        Space Complexity: O(1)
    */
    int maxi = INT_MIN;

    for(int i = 0; i<n; i++){
        int product = 1;
        for(int j = i; j<n; j++){
            product *= arr[j];
            maxi = max(maxi,product);
        }
    }
    return maxi;
}
int brute(vector<int> &arr, int n){
    /*
        Time complexity: O(N^3)
        Space complexity: O(1)
    */
    int maxi = INT_MIN;

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int product = 1;
            for(int k = i; k<=j; k++){
                product *=arr[k];
            }
            maxi = max(maxi,product);
        }
    }
    return maxi;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);
    cout<<"brute: "<<brute(arr,arr.size());
    cout<<"\nbetter: "<<better(arr,arr.size());
    cout<<"\noptimal: "<<optimal(arr,arr.size());
    return 0;
}