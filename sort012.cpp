#include<bits/stdc++.h>
using namespace std;
void optimalApproach(vector<int> &arr, int n){
    cout<<"Optimal Approach:\n";
    int low = 0,mid = 0, high = n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
void betterApproach(vector<int> &arr, int n){
    int cnt_0 = 0, cnt_1= 0, cnt_2 = 0;
    cout<<"better: \n";
    for(int i = 0; i<n; i++){
        if (arr[i]==0)cnt_0++;
        else if(arr[i]==1)cnt_1++;
        else cnt_2++;
    }

    for(int i = 0 ; i<cnt_0; i++)arr[i]=0;
    for(int i = cnt_0; i<cnt_0+cnt_1; i++)arr[i]=1;
    for(int i = cnt_0+cnt_1; i<n; i++)arr[i]=2;

}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.emplace_back(input);

    // betterApproach(arr,arr.size());
    optimalApproach(arr,arr.size());
    for(auto i:arr)cout<<i<<" ";
    return 0;
}