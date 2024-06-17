#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> bloomDays, int day, int m, int k){

    
    int n = bloomDays.size();
    int cnt = 0;
    int nBouquets = 0;
    for(int i = 0; i<n; i++){
        if (bloomDays[i]<=day){
            cnt++;
        }
        else{
            nBouquets += cnt/k;
            cnt = 0;
        }
    }
    nBouquets += cnt/k;
    if(nBouquets>=m)return true;
    else return false;
}
int optimal(vector<int> bloomDays, int m, int k){

    /*
        Time complexity: O(log(max-minElement) * N );
    */
    int low = *min_element(bloomDays.begin(),bloomDays.end());
    int high = *max_element(bloomDays.begin(),bloomDays.end());

    while(low<=high){
        int mid = low + (high-low)/2;

        if (possible(bloomDays,mid,m,k)){
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}
int brute(vector<int> bloomDays, int m , int k){
    /*
        Time complexity: O(maxElement-minElement+1 * N)
        Space Complexity: O(1)
    */

    //finding min and maximum values to start checking flowers are bloomed or not.
    int mini = *min_element(bloomDays.begin(),bloomDays.end());
    int maxi = *max_element(bloomDays.begin(),bloomDays.end());
    int n = bloomDays.size();

    // if the number of adjacent flowers and number of bouquets you need to prepare exceeds the given flowers in the data structure just return -1.
    if ((m*k)>n) return -1;
    for(int day = mini; day<=maxi; day++){
            //check whether we can take this day to prepare the bouquet or not.
            if(possible(bloomDays,day,m,k)){
                return day;
            }
    }
    return -1;
}
int main()
{
    vector<int> bloomDays;
    int input,m,k;

    while(cin>>input){
        bloomDays.push_back(input);
    }
    cout<<"brute approach: "<<brute(bloomDays,3,1);
    cout<<"\noptimal approach: "<<optimal(bloomDays,3,1);
    return 0;
}