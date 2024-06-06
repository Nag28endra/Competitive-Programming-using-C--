#include<bits/stdc++.h>
using namespace std;
vector<int> optimal(vector<int> &arr, long long n){
    /*
        Time  complexity: O(N);
        space complexity: O(1);

        most probably take the long long as the data type to avoid overflow.
    */

    cout<<"optimal:\n";

    long long s = (n*(n+1))/2;
    long long s2 = (n*(n+1)*(2*n+1))/6;

    int sn =0, s2n = 0;
    for(int i = 0; i<n; i++){
        sn +=arr[i];
        s2n += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = s-sn;
    long long val2 = s2-s2n;

    val2 = val2/val1;
    long long y = (val1+val2)/2;
    long long x = y -val1;

    return {(int)x,(int)y};
}
vector<int> better(vector<int> &arr, int n){
    /*
        Time complexity: O(2N)
        Space compelxity: O(N+1)
    */
    cout<<"better:\n";
    int hash[n+1]= {0};
    int repeating = -1,missing = -1;
    for(int i = 0; i<n; i++){
        hash[arr[i]]++;
    }

    for(int i = 1; i<=n; i++ ){
        if (hash[i]==2)repeating = i;
        else if (hash[i]==0)missing = i;

        if (repeating !=-1 &&  missing !=-1)break;
    }
    return {repeating, missing};
}
vector<int> brute(vector<int> &arr, int n){
    /*
        time complexity: O(N^2)
        space complexity: O(1);
    */
    int repeating = -1;
    int missing = -1;
    cout<<"Brute:\n";
    for(int i = 1; i<=n; i++){
        int cnt = 0;
        for(int j = 0 ;j<n; j++){
            if(arr[j]==i)cnt++;
        }
        if (cnt==2)repeating = i;
        else if (cnt==0) missing = i;

        if(repeating  !=-1 && missing !=-1)break;
    }
    return {repeating, missing};
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);
    // vector<int> res = brute(arr,arr.size());
    // vector<int> res = better(arr,arr.size());
    vector<int> res = optimal(arr,arr.size());
    cout<<"repeating: "<<res[0]<<"\nmissing: "<<res[1];
    return 0;
}