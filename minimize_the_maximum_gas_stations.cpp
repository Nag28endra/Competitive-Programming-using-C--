#include<bits/stdc++.h>
using namespace std;

long double brute(vector<int> &arr, int k){

    /*
        Time complexity: O(K * N-1) + O(N-1)
        Space complexity: O(N-1)
    */
    int n = arr.size();
    vector<int> howMany(n-1,0);

    for(int i = 1; i<=k; i++){
        long double maxi = -1;
        int maxIdx = -1;

        for(int i = 0; i<n-1; i++){
            long double sectionLength = (arr[i+1]-arr[i]) / (howMany[i]+1);
            if (maxi<sectionLength){
                maxi = sectionLength;
                maxIdx = i;  
            }
        }
        howMany[maxIdx]++;
    }

    long double maxAns = -1;
    for(int i = 0; i<n-1; i++){
        long double sectionLength =(arr[i+1]-arr[i]) / (howMany[i]+1);
        maxAns = max(maxAns,sectionLength);
    }
    return maxAns;
}
long double better(vector<int> arr, int k){

    /*
        Time complexity: O(NlogN)+ (KlogN)
        Space complexity: O(N-1)
    */
    int n = arr.size();
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double, int>>pq;

    for(int i = 0; i<n-1;i++){
        pq.push({arr[i+1]-arr[i], i});
    }
    for(int gasStations = 1; gasStations<=k ; gasStations++){
        auto top = pq.top();
        pq.pop();
        int sectionIndex = top.second;
        howMany[sectionIndex]++;
        long double initialDifference = arr[sectionIndex+1]-arr[sectionIndex];
        long double newSectionLength = initialDifference/(long double)(howMany[sectionIndex]+1);

        pq.push({newSectionLength,sectionIndex});
    }
    return pq.top().first;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);
    cout<<"brute: "<<brute(arr,5);
    cout<<"\nbetter: "<<better(arr,5);
    return 0;
}