#include<bits/stdc++.h>
using namespace std;
int findDays(vector<int> arr, int capacity){
    
    // initially it is day-1
    int days = 1;
    // with load as 0
    int load = 0;

    for(int i = 0; i<arr.size();i++){
        // if the load of the ship and the current item exceeds the capacity, then it will ship the current item to next day and load will set to the weight of the current day.
        if(load+arr[i]>capacity){
            days +=1;
            load = arr[i];
        }
        // adding the load to the ship.
        else{
            load += arr[i];
        }
    }
    return days;
}
int optimal(vector<int> arr, int d){
    /*
        time complexity: O(log(high-low)+1 * N)
    */
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid = low + (high-low)/2;

        int requiredDays = findDays(arr,mid);
        if(requiredDays<=d){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
int brute(vector<int> arr, int d){
    /*
        Time complexity: O( (sum-max)+1 *N)
        Space complexity: O(1)
    */

    // the capacity of the ship ranges from maximum value in the data and the sum of vales.
    int maxi= *max_element(arr.begin(),arr.end());
    int sum = accumulate(arr.begin(),arr.end(),0);

    for(int capacity= maxi;capacity<=sum; capacity++){
        int requiredDays = findDays(arr,capacity);
        if(requiredDays<=d){
            return capacity;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr;
    int input;
    while(cin>>input)arr.push_back(input);
    cout<<"brute: "<<brute(arr,5);
    cout<<"\noptimal: "<<optimal(arr,5);
    return 0;
}