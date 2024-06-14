#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int n){

    /*
        Time complexity: O(LogN)
        Space complexity: O(1)
    */
    int mini = INT_MAX;
    int rotations = -1;
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = low +  (high-low)/2;

        //check the entire array from low to high
        if (nums[low]<=nums[high]){
            // check if the value at low is less than mini
            if(nums[low]<mini){
                mini = nums[low];
                rotations = low;
            }
            break;
        }

        //check if the left portion is sorted or not.
        if (nums[low]<=nums[mid]){
            // check if the value at low is less than mini
            if (nums[low]<mini){
                mini = nums[low];
                rotations = low;
            }
            // eliminate left search portion.
            low = mid + 1;
        }
        //check if right portion is sorted or not
        else{
            // check the value at mid is less than mini or not.
            if (nums[mid]<mini){
                mini = nums[mid];
                rotations = mid;
            }
            //eliminate the right search portion.
            high = mid - 1;
        }
    }
    return rotations;
}
int main()
{
    vector<int> nums;
    int input;

    while(cin>>input)nums.push_back(input);
    cout<<"number of rotations are: "<<binarySearch(nums,nums.size());
    return 0;
}