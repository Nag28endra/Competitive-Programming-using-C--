#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr,int n, int x){
    int low = 0;
    int high = n-1;
    int res = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (arr[mid]<=x){
            res = mid;
            low = mid+1;
        }
        else high = mid - 1;
    }
    return res;
}
int findCeil(vector<int> &arr,int n , int x){
    int low = 0;
    int high = n-1;
    int res = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if (arr[mid]>=x){
            res = mid;
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    }
    return res;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);

    int ceilIdx = findCeil(arr,arr.size(),8);
    int floorIdx = findFloor(arr,arr.size(),8);

    int ceil = (ceilIdx != -1) ? arr[ceilIdx] : -1;
    int floor = (floorIdx !=-1) ? arr[floorIdx] : -1;

    cout<<"floor: "<<floor<<" ceil: "<<ceil;
    return 0;
}