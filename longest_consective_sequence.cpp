#include<bits/stdc++.h>
using namespace std;

int optimalApproach(vector<int> &arr, int n){
    cout<<"\nOptimal: ";
    unordered_set<int> uarr;
    int longest = 1;
    if (arr.size()==0) return 0;

    for(int i = 0; i<n; i++)uarr.insert(arr[i]);

    for(auto i : uarr){
        if (uarr.find(i-1) == uarr.end()){
            int cnt = 1;
            int x = i;
            while(uarr.find(x+1)!=uarr.end()){
                x +=1;
                cnt +=1;
            }
             longest = max(longest, cnt);
        }
       
    }
    return longest;
}
int betterApproach(vector<int> &arr, int n){
    int cnt = 0;
    int previous = INT_MIN;
    int longest = 1;
    sort(arr.begin(),arr.end());
    cout<<"\nBetter: ";
    for (int i = 0; i<n;  i++){
        if (arr[i]-1 == previous){
            cnt +=1;
            previous = arr[i];
        }
        else if (arr[i] != previous){
            cnt = 1;
            previous =  arr[i];
        }
        longest = max(longest,cnt);
    }
    return longest;
}
bool linearSearch(vector<int> &arr, int x){
    for(int i = 0; i<arr.size(); i++){
        if (arr[i]==x)return true;
    }
    return false;
}
int  bruteApproach(vector<int> &arr, int n){
    cout<<"Brute: ";
        int longest = 1;
        for(int i = 0; i<n; i++){
            int x = arr[i];
            int cnt = 1;

            while(linearSearch(arr,x+1)){
                    x += 1;
                    cnt +=1;
            }
            longest = max(longest,cnt);
        }
        return longest;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.push_back(input);
    cout<<bruteApproach(arr,arr.size());
    cout<<betterApproach(arr,arr.size());
    cout<<optimalApproach(arr,arr.size());
    return 0;
}