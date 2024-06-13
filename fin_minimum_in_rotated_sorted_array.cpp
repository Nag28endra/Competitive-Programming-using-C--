#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int n){

    /*
        Time complexity: O(log N)
        Space complexity: O(1)

        Intuition:
        ---------
        - find out the mid.
        - then check in one half of the sorted array and find the minimum value.
        - if you are checking in the left sorted area  
            -- your min value will be at arr[low]
        - if you are checking in the right sorted area
            -- your min value will be at arr[mid]
    */
    int res = INT_MAX;
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (nums[mid]<=nums[high]){
            res = min(res,nums[mid]);
            high = mid - 1;
        }
        else{
            res = min(res,nums[low]);
            low = mid + 1;
        }
    }
    return res;
}
int main()
{
    vector<int> nums;
    int input;

    while(cin>>input)nums.push_back(input);

    cout<<"Minimum value is "<<binarySearch(nums,nums.size());
    return 0;
}