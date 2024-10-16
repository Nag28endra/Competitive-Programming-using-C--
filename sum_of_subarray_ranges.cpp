#include<bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int> arr){
    stack<int> st;
    vector<int> nse(arr.size());
    for(int i = arr.size() - 1; i>=0; i--){

        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        nse[i] = st.empty() ? arr.size() : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPSE(vector<int> arr){
    stack<int> st;
    vector<int> pse(arr.size());
    for(int i = 0; i<arr.size(); i++){

        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
vector<int> findNGE(vector<int> arr){
    stack<int> st;
    vector<int> nge(arr.size());
    for(int i = arr.size() - 1; i>=0; i--){

        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();

        nge[i] = st.empty() ? arr.size() : st.top();
        st.push(i);
    }
    return nge;
}
vector<int> findPGE(vector<int> arr){
    stack<int> st;
    vector<int> pge(arr.size());
    for(int i = 0; i<arr.size(); i++){

        while(!st.empty() && arr[st.top()] < arr[i]) st.pop();

        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pge;
}
int sum_of_subarrays_min(vector<int> arr){
    int minTotal = 0;
    int mod = 1e9 + 7;
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);

    for(int i = 0; i < arr.size(); i++){
        int left = i - pse[i];
        int right = nse[i] - i;

        minTotal = (minTotal + (right * left * arr[i] * 1LL) % mod) % mod;
    }
    return minTotal;
}

int sum_of_subarrays_max(vector<int> arr){
    int maxTotal = 0;
    int mod = 1e9 + 7;
    vector<int> nge = findNGE(arr);
    vector<int> pge = findPGE(arr);

    for(int i = 0; i < arr.size(); i++){
        int left = i - pge[i];
        int right = nge[i] - i;

        maxTotal = (maxTotal + (right * left * arr[i] * 1LL) % mod) % mod;
    }
    return maxTotal;
}

int optimal(vector<int> arr){
    return sum_of_subarrays_max(arr) - sum_of_subarrays_min(arr);
}
int brute(vector<int> arr){
    int sum = 0;
    for(int i = 0; i<arr.size(); i++){
        int largest = arr[i], smallest = arr[i];
        for(int j = i+1; j<arr.size(); j++){
            largest = max(largest, arr[j]);
            smallest = min(smallest, arr[j]);
            sum += (largest - smallest);
        }
    }
    return sum;
}
int main()
{
    vector<int> arr = {1,2,3};
    cout<<optimal(arr);
    return 0;
}