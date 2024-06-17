#include<bits/stdc++.h>
using namespace std;
int findMax(vector<int> v){
    int maxi = INT_MIN;
    int n = v.size();
    for(int i = 0; i<n;  i++){
        maxi = max(v[i],maxi);
    }
    return maxi;
}
long long calculateTotalHours(vector<int> v, int hour){
        int n = v.size();
        long long totalHours = 0;
        for(int i = 0; i<n; i++){
            totalHours += ceil( (double)v[i] / (double)hour);
        }
        return totalHours;
}
int optimal(vector<int> v, int h){

    /*
        Time complexity: O(log(maxElement) x N)
        Space complexity: O(1)
    */
    int low = 1;
    int high = findMax(v);

    while(low<=high){
        int mid = low + (high-low)/2;
        long long totalHours = calculateTotalHours(v,mid);
        if(totalHours<=h) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
int brute(vector<int> v, int h){

    /*
        Time complexity: O(maxElement * N)
    */
    int maxi = findMax(v);
    for(int i = 1; i<=maxi; i++){
        long long totalHours = calculateTotalHours(v,i);
        if(totalHours<=h){
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> v;
    int input, hours;
    cin>>hours;
    while(cin>>input)v.push_back(input);
    cout<<"optimal: "<<optimal(v,hours);
    cout<<"\nbrute:"<<brute(v,hours);
    return 0;
}