#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &arr){

    
    
}
bool isSorted(vector<int> &arr){
        if(check(arr)) return true;
        
        else{
            // rotate the array
            vector<int> temp;
            int x = arr[0];
            for (int i = 0; i<arr.size(); i++){
                temp.push_back(arr[(i+x)%arr.size()]);
            }

            // for(auto i: temp)cout<<i<<" ";
            if(check(temp)) return true;
            else return false;
        }
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.push_back(input);
    cout<<isSorted(arr);

    return 0;
}