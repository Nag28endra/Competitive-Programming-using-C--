#include<bits/stdc++.h>
using namespace std;

int sumofD(vector<int> arr, int divisor){
    int n = arr.size();
    int sum = 0;

    for(int i = 0; i<n; i++){
        sum += ceil( (double)arr[i] / (double)divisor);
    }
    return sum;
}
int optimal(vector<int> arr,int threshold){
    /*
        Time complexity: O(log(max)*N)
        space complexity: O(1)
    */
    int low = 1;
    int high = *max_element(arr.begin(),arr.end());
    int ans =-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        if(sumofD(arr,mid)<=threshold){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int brute(vector<int> &arr, int threshold){
    /*
        Time complexity: O(maxi * N)
        Space complexity: O(1);
    */
    int maxi = *max_element(arr.begin(),arr.end());

    for(int divisor = 1; divisor<=maxi; divisor++){
        int sum = 0;
        for(int i=0; i<arr.size();i++)
        {
            sum += ceil(arr[i]/divisor);
        }
        if (sum<=threshold) return divisor;

    }
    return -1;
}
int main()
{
    vector<int> arr;
    int input;
    while(cin>>input)arr.push_back(input);
    cout<<"brute:"<<brute(arr,6);
    cout<<"\noptimal:"<<optimal(arr,6);
    return 0;
}