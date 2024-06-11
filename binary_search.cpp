#include<bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &arr, int n, int target){
    /*
        This is used to find the upper bound which is the smallest index where arr[mid]>target.
    */
    int low = 0; 
    int high = n-1;
    int res = n; 

    while(low<=high){
        int mid = low + (high-low)/2;

        if (arr[mid]>target){
            res = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return res;
}
int lowerBound(vector<int> &arr, int n , int target){
    /*
        This is used to find the lower bound which is the smallest index where arr[mid]>=target.

        *** It is also used to find the insertion position of the target element if it is not found inthe data structure.
    */
    int low = 0;
    int high = n-1; 
    int res = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]>=target){
            res = mid;
            high = mid-1;
        }
        else low = mid +1;
    }
    return res;
}
int binarySearch(vector<int> &arr, int n , int target){
    /*
        Time complexity: O(log N)
    */
    int low = 0; 
    int high = n-1;
   

    while(low<=high){
        int mid = low +(high - low)/2;

        if (arr[mid]==target)return mid;
        else if (arr[mid]>target){
            high = mid-1;
        }
        else{
            low = mid +1;
        }
    }
    return -1;       
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);

    cout<<"binary search: "<<binarySearch(arr,arr.size(),3);
    cout<<"\nLower bound: "<<lowerBound(arr,arr.size(),3);
    cout<<"\nUpper bound: "<<upperBound(arr,arr.size(),3);
    return 0;
}