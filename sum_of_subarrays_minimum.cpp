#include<bits/stdc++.h>
using namespace std;
vector<int> findNSE(vector<int> arr){
    vector<int> nse(arr.size());
    stack<int> st;

    for(int i = arr.size() - 1; i>=0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        nse[i] = st.empty() ? arr.size() : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPSE(vector<int> arr){
    vector<int> pse(arr.size());
    stack<int> st;

    for(int i = 0; i<arr.size(); i++){
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
int optimal(vector<int> arr){
    /*
        Time complexity : O(5N)
        Space Complexity : O(4N)

        we use mod to avoid the overflow
    */
    int total = 0;
    vector<int> nse = findNSE(arr);
    
    vector<int> pse = findPSE(arr);
    int mod = (1e9 +7);

    for(int i =0 ;i<arr.size();i++){
        int left = i - pse[i];
        int right = nse[i] - i;

        total = (total + (right*left*1LL*arr[i])%mod)%mod;
    }
    return total;
}
int brute(vector<int> arr){
    int Sum = 0 ;
    int len = arr.size();

    for(int i = 0; i<len ; i++){
        for(int j = 0; j<len; j++){
            Sum += min(arr[i],arr[j]);
        }
    }
    return Sum;
}
int main()
{
    vector<int> arr = {3,1,4,2};
    cout<<optimal(arr);
    return 0;
}