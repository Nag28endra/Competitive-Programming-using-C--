#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute(vector<int> &arr, int n , int target){
    
    cout<<"brute:\n";
    set<vector<int>> s;
    for(int i = 0 ; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                for(int l = k+1; l<n; l++){
                    long long sum = arr[i]+arr[j];
                    sum += arr[k];
                    sum += arr[l];

                    if (target == sum){
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }
     vector<vector<int>> res(s.begin(),s.end());
     return res;
}
vector<vector<int>> better(vector<int> &arr, int n , int target){
    cout<<"better:\n";

    set<vector<int>> s;

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            set<int> hashset;
            for(int k = j+1; k<n; k++){
                long long sum = arr[i]+arr[j];
                sum +=arr[k];
                long long fourth = target - sum;

                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> temp = {arr[i],arr[j],arr[k],(int)fourth};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> res(s.begin(),s.end());
    return res;
}
vector<vector<int>> optimal(vector<int> &arr, int n , int target){
    sort(arr.begin(),arr.end());
    vector<vector<int>> res;
    cout<<"optimal:\n";

    for(int i = 0; i<n; i++){
        if (i>0 && arr[i]==arr[i-1])continue;

        for(int j = i+1; j<n; j++){
            if (j>i+1 && arr[j]==arr[j-1])continue;

            int k = j+1;
            int l = n-1;

            while(k<l){
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];

                if(target == sum){
                    vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                    res.push_back(temp);
                    k++;
                    l--;

                    while(k<l && arr[k]==arr[k-1])k++;
                    while(k<l && arr[l]==arr[l+1])l--;
                }
                else if (sum<target)k++;
                else l--;
            }
        }
    }
    return res;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);

    // vector<vector<int>> res = optimal(arr, arr.size(),8);
    // vector<vector<int>> res = better(arr, arr.size(),8);
    vector<vector<int>> res = brute(arr, arr.size(),8);

    for(const auto &triplet: res){
        for(auto num: triplet){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}