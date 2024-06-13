/*
    DESCRIPTION:
    There is an integer array nums sorted in ascending order (with distinct values).

    Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

    Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:

    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
    Example 2:

    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int n, int target){

    /*
        Time complexity : O(log N)
        Space Complexity: O(1)
    */
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (arr[mid]==target)return mid;

        //checking in the left sorted array
        if (arr[low]<=arr[mid]){
            if (arr[low]<=target && target<=arr[mid])high = mid - 1;
            else low =  mid + 1;
        }

        //checking inthe right sorted array.
        else{
                if (arr[mid]<=target && target<=arr[high])low = mid + 1;
                else high = mid - 1;
        }
        
    }
    return -1;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);
    cout<<binarySearch(arr,arr.size(),0);
    return 0;
}