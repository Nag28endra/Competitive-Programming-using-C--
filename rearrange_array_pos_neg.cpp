 #include<bits/stdc++.h>
 using namespace std;
 void optimalApproach(vector<int> &arr, int n){
    vector<int> res(n,0);
    int pos = 0, neg = 1;
    cout<<"Optimal Approach: ";
    for(int i = 0; i<n; i++){
        if (arr[i]>0){
            res[pos] = arr[i];
            pos += 2;
        }
        else{
            res[neg]=arr[i];
            neg +=2;
        }
    }

    for(auto i:res)cout<<i<<" ";
 }
 void betterApproach(vector<int> &arr, int n){
    vector<int> pos;
    vector<int> neg;

    for(int i =0 ; i<n; i++){
        if (arr[i]>0)pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    for(int i = 0; i<n/2; i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }

    for(auto i:arr)cout<<i<<" ";
 }
 int main()
 {
     vector<int> arr={3,-1,1,2,-4,-5};
     int input;
    //  betterApproach(arr,arr.size());
     optimalApproach(arr,arr.size());

     return 0;
 }