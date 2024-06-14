#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &nums, int n){

    /*
        Time complexity: O(logN)
        Space complexity: O(1)
    */
   // check if the length of the array is 1 or not.
    if (n == 1)return nums[0]; 
    if (nums[n-1]!=nums[n-2])return nums[n-1];

    int low = 1;
    int high = n-2;

    while(low<=high){
        int mid = low + (high-low)/2;

        //checking the before and after element of mid is not equal.
        if (nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])return nums[mid];

        // check in the left space of sorted array.
        if ((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            low = mid + 1;
        }
        // check in the right space of sorted array.
        else{
            high = mid - 1; 
        }
    }
    return -1;
}
int brute(vector<int> &nums, int n){

    /*
        Time complexity: O(N)
        Space complexity: O(1)
    */
    if (n == 1)return nums[0];

    for(int i = 0; i<n ; i++){
        if (i == 0){
            if (nums[i]!=nums[i+1])return nums[i];
        }
        if (i == n-1){
            if (nums[i]!=nums[i-1])return nums[i];
        }
        if (nums[i]!=nums[i-1] && nums[i]!=nums[i+1])return nums[i];
    }
    return -1;
}
int main()
{
    vector<int> nums;
    int input;

    while(cin>>input)nums.push_back(input);

    cout<<"brute: "<<brute(nums,nums.size());
    cout<<"\nOptimal(binary search): "<<binarySearch(nums,nums.size());
    return 0;
}