#include<bits/stdc++.h>
using namespace std;
int optimal(vector<int> nums, int n){
    /*
        Time complexity: O(logN)
        Space complexity: O(1)

        peak element is that whose neighbours are less.
        i.e arr[i-1]<arr[i]>arr[i+1]
    */
    if(n==1) return 0; //checking if the length of the array is 1.
    if (nums[0]>nums[1])return 0;   // checking for the first element of array.
    if (nums[n-1]>nums[n-2])return n-1; // checking for the last element of the array.

    int low = 1;
    int high = n-2;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])return mid;
        // if the mid is on left side of the peak, peak will be definitly on the right of the mid
        else if (nums[mid]>nums[mid-1]) low = mid + 1;
        // if the mid is on right side of the peak, peak will be definitly on the left side of the mid.
        else high = mid - 1;
    }
    return -1;
}
int brute(vector<int> &nums, int n){
    /*
        Time complexity: O(N)
        Space compleixty: O(1)
    */
   if(n==1)return 0;
    for(int i = 0; i<n ;i++){

        if((i == 0 || nums[i]>nums[i-1]) && (i == n-1 || nums[i]>nums[i+1]))
            return i;
    }
    return -1;
}
int main()
{
    vector<int> nums;
    int input;

    while(cin>>input)nums.push_back(input);
    cout<<"brute: "<<brute(nums,nums.size());   
    cout<<"\noptimal(binary search): "<<optimal(nums,nums.size());   
    return 0;
}