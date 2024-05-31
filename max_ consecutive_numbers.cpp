#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(vector<int> &arr){
    int Max = 0,cnt = 0;

    for (int i =0 ; i<arr.size(); i++){
        if(arr[i]==1){
            cnt++;
            Max = max(cnt,Max);
        }
        else{
            cnt = 0;
        }
    }
    return Max;
}
int main()
{
    vector<int> arr;
    int input;
    while(cin>>input && input!=EOF)arr.push_back(input);

    cout<<maxConsecutiveOnes(arr);
    return 0;
}