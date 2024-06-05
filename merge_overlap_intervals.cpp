#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> optimal(vector<vector<int>> &intervals, int n ){
    /*
        Time complexity: O(nlogn) + O(N)
        Space complexity: O(N)
    */
    cout<<"Optimal:\n";
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;

    for(int i= 0; i<n; i++){
            if (res.empty() || intervals[i][0]>res.back()[1]){
                res.push_back(intervals[i]);
            }
            else{
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
    }
    return res;
}
vector<vector<int>> brute(vector<vector<int>> &arr, int n){

    /*
        Time complexity : O(NlogN) + O(2N) but not O(N^2) why because we are using contiune and break statements that won't iterate completely.

        Space complexity: O(N)
    */
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i = 0; i<n; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end<=ans.back()[1])continue;

        for(int j = i+1; j<n; j++){
            if(arr[j][0]<=end){
                end = max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};

    // vector<vector<int>> res = brute(arr,arr.size());
    vector<vector<int>> res = optimal(arr,arr.size());

    for(const auto &i: res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}