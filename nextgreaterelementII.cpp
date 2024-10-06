#include<bits/stdc++.h>
using namespace std;
vector<int> optimal(vector<int> arr){
    /*
        Time complexity: O(2N)
        Space complexity: O(2N) +O(N)

    */
    vector<int> nge( arr.size() );
    stack<int> st;
    int N = arr.size();
    for(int i = 2*N-1; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i%N]) st.pop();

        if(i<N) nge[i] = st.empty() ? -1 : st.top();
        st.push(arr[i % N]);
    }
    return nge;
}
vector<int> naive(vector<int> arr){
    vector<int> nge(arr.size(),-1);
    int N = arr.size();
    for(int i = 0; i<N ; i++){
        for(int j = i+1; j<= i+N-1; j++){
                int idx = j % N;

                if( arr[idx] > arr[i]){
                    nge[i] = arr[idx];
                    break;
                }
        }
    }
    return nge;
}
int main()
{
    vector<int> arr = {2,10,12,11,1};
    vector<int> res = naive(arr);
    for( int value : res) cout<< value << " ";
    return 0;
}