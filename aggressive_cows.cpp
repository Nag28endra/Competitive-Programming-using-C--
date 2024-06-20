#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows){
    
        int n = stalls.size();
        int last = stalls[0];
        int cntCows = 1;

        for(int i = 1; i<n; i++){
            if (stalls[i]-last >=dist){
                cntCows++;
                last = stalls[i];
            }
           if(cntCows>=cows)return true; 
        }
        return false;
}
int brute(vector<int> &stalls, int cows){
    /*
        Time complexity: O(nlogN x (maxi-mini) x N)
        Space complexity: O(1)
    */
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int mini = stalls[0];
    int maxi = stalls[n-1];

    for(int i = 1; i<=(maxi-mini); i++){
        if(canWePlace(stalls,i,cows)==true) continue;
        else return (i-1);
    }
    return -1;
}
int optimal(vector<int> &stalls, int cows){
    /*
        Time complexity: O(NlogN) * O(log(max-mini)) * O(N)
        space complexity: O(1)
    */
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int low = 1;
    int high = stalls[n-1]-stalls[0];

    while(low<=high){
        int mid = low + (high-low)/2;

        if (canWePlace(stalls,mid,cows)==true)low = mid + 1;
        else high = mid - 1;
    }
    return high;
}
int main()
{
    vector<int> stalls;
    int input;
    while(cin>>input)stalls.push_back(input);
    cout<<"brute: "<<brute(stalls,3);
    cout<<"\noptimal: "<<optimal(stalls,2);
    return 0;
}

