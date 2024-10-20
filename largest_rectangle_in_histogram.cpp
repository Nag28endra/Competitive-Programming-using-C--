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

        pse[i] = st.empty() ? -1 :st.top();
        st.push(i);
    }
    return pse;
}
int optimal(vector<int> arr){
    stack<int> st;
    int maxi = INT_MIN;

    for(int i = 0; i<arr.size() ; i++){
        // computing for pse.
        while(!st.empty() && arr[st.top()] > arr[i]){
            // take out the index of the value to get the area this particular block
            int element_idx = st.top();
            // pop out that index value.
            st.pop();
            // nse will be the current value index from the array.
            int nse = i;
            // pse will be the current value from the stack.
            int pse = st.empty() ? -1:st.top();
            // finding the largest area from the required formula.
            maxi = max(maxi, arr[element_idx]*(nse-pse-1));
        }
        // push the current value index into the stack.
        st.push(i);
    }
    while(!st.empty()){
        // nse will be the size of the array because for the leftover values in the stack won't have the nse for sure.
        int nse = arr.size();
        int element_idx = st.top();
        st.pop();
        int pse = st.empty()? -1 : st.top();
        maxi = max(maxi, arr[element_idx]*(nse-pse-1));
    }
    return maxi;
}
int brute(vector<int> arr){
    /*
        Time complexity: O(5N)
        Space Complexity: O(5N)
    */
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);
    int maxi = INT_MIN;
    for(int i = 0; i<arr.size(); i++) maxi = max(maxi, (arr[i]*(nse[i]-pse[i]-1)));
    return maxi;
}
int main()
{
    vector<int> arr = {2,4};
    cout<<optimal(arr);
    return 0;
}