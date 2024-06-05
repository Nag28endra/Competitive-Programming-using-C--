#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> &arr, int n, int k){
    /*
        We'll be using the formula x = xr^k; {check for the derivation in notes}
        We make sure that x is in our hashmap.

        The hashmap stores values in (front xor->count) format.
    */
   int xr = 0;
   int cnt = 0;
   map<int,int> mpp;
   mpp[xr]++;
   for(int i = 0; i<n;i++){
        xr = xr^arr[i];
        int x = xr^k;
        cnt += mpp[x];
        mpp[xr]++;
   }
   return cnt;
}
int better(vector<int> &a, int n, int k){
    int cnt = 0;

    for(int i = 0; i<n; i++){
        int xr = 0;
        for(int j = i ;j<n; j++){
            xr = xr^a[j];
            if(xr == k)cnt++;
        }
    }
    return cnt++;
}
int brute(vector<int> &a, int n, int k ){
    int cnt = 0;

    for(int i = 0; i<n; i++){
        for(int  j = i; j<n; j++){
            int xr = 0;
            for(int k = i; k<=j; k++){
                xr = xr^a[k];
            }
            if(xr == k )cnt++;
        }
    }
    return cnt;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);

    cout<<"brute: "<<brute(arr,arr.size(),6);
    cout<<"\nbetter: "<<better(arr,arr.size(),6);
    cout<<"\noptimal: "<<optimal(arr,arr.size(),6);
    return 0;
}