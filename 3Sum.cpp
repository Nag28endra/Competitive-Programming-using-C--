#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> brute(vector<int> &arr, int n){
    set<vector<int>> s;
    cout<<"Brute:\n";
    for(int i = 0; i<n; i++){
        for(int j =i+1; j<n; j++){
            for (int k = j+1; k<n; k++){
                int sum = arr[i]+arr[j]+arr[k];
                if (sum == 0){
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> res(s.begin(),s.end());
    return res;
}
vector<vector<int>> better(vector<int> &arr, int n){
    set<vector<int>> s;
    cout<<"better:\n";
    for(int i = 0 ; i<n; i++){
        set<int> hashSet;
        for(int j = i+1; j<n; j++){
            int third = -(arr[i]+arr[j]);
            if(hashSet.find(third)!=hashSet.end()){
                vector<int> temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                s.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> res(s.begin(),s.end());
    return res;
}
vector<vector<int>> optimal(vector<int> &arr, int n){
    vector<vector<int>> res;
    sort(arr.begin(),arr.end());
    cout<<"Optimal:\n";
    for(int i = 0; i<n; i++){
        if (i>0 &&  arr[i]==arr[i-1])continue;

        int j = i+1;
        int k = n-1;

        while(j<k){
            int sum =arr[i]+arr[j]+arr[k];

            if(sum > 0 )k--;
            else if(sum<0)j++;
            else{
                vector<int> temp = {arr[i],arr[j],arr[k]};
                res.push_back(temp);
                j++;
                k--;

                while(j<k && arr[j]==arr[j-1])j++;
                while(j<k && arr[k]==arr[k+1])k--;

            }    
        }
    }
    return res;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input) arr.push_back(input);
    // vector<vector<int>> res = optimal(arr,arr.size());
    // vector<vector<int>> res = better(arr,arr.size());
    vector<vector<int>> res = brute(arr,arr.size());

     for (const auto &triplet : res) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}