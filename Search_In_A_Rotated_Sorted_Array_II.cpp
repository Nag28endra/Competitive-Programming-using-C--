#include<bits/stdc++.h>
using namespace std;

/*
    Description:
    -----------

    here is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

    Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

    Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

    You must decrease the overall operation steps as much as possible.

    Example 1:

    Input: nums = [2,5,6,0,0,1,2], target = 0
    Output: true
    Example 2:

    Input: nums = [2,5,6,0,0,1,2], target = 3
    Output: false    
*/

bool binarySearch(vector<int> &arr,int n, int x){

    /*
        Time complexity: O(log N) -- average case O(N)--worst case
        Space complexity: O(1)
    */
    int low = 0;
    int high = n-1;

    while(low<=high){

        int mid = low + (high-low)/2;

        if (arr[mid]==x)return true;

        // the only edge case
        if (arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }

        //if left sorted array
        if (arr[low]<=arr[mid]){
            // check whether target is in left sorted space or not
            if(arr[low]<=x && x<=arr[mid])high = mid - 1;
            else low = mid + 1;
        }

        //if right sorted array.
        else{
            // check whether target is in right sorted space or not.
            if (arr[mid]<=x && x<=arr[high])low = mid + 1;
            else high = mid - 1;
        }
    }
    return false;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);

    string res = binarySearch(arr,arr.size(),3)?"True":"False";
    cout<<res;
    return 0;
}