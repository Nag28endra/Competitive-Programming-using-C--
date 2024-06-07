#include<bits/stdc++.h>
using namespace std;
int optimal(vector<int> &arr,int n){

    /*
        Time complexity: O(2N)
        Space complexity: O(1)

        We use linked list and tortoise technique to solve the problem
    */
    int slow = arr[0];
    int fast = arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow!=fast);

    fast = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int better(vector<int> &arr, int n){

    /*
        Time complexity: O(2N)
        Space complexity: O(N)
    */
    int hash[n+1];
    for(int i = 0; i<n; i++){
        hash[arr[i]]++;
    }
    int val=-1;
    for(int i = 0; i<n; i++){
        if(hash[i]>1){
            val = hash[i];
        }
    }
    return val;
}
int brute(vector<int> &arr, int n){
    /*
        Time complexity: O(NlogN)-for sorting + o(N)
        Space complexity: O(1)
    */
    sort(arr.begin(), arr.end());
    int val=-1;
    for(int i = 1; i<n; i++){
        if(arr[i-1]==arr[i]){
                val = arr[i];
                break;
        }
    }
    return val;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);
    cout<<"brute: "<<brute(arr,arr.size());
    cout<<"\nbetter: "<<better(arr,arr.size());
    cout<<"\noptimal: "<<optimal(arr,arr.size());
    return 0;
}