#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int prices[N];
    for(int i = 0; i<N; i++)cin>>prices[i];

    int mini = prices[0];
    int maxProfit = 0;

    for(int i = 1; i<=N; i++){
        int cost = prices[i]-mini;
        maxProfit = max(maxProfit,cost);
        mini = min(mini,prices[i]);
    }
    cout<<"Maximum Profit: "<<maxProfit<<" Buying at: "<<mini<<" Selling at: "<<maxProfit+mini;
    return 0;
}