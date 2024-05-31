#include<bits/stdc++.h>
using namespace std;
void intersection_Optimal(vector<int> &arr1, vector<int> arr2, int n1, int n2){
        int i=0, j=0;
        vector<int> res;
        while(i<n1 && j<n2){
            if( arr1[i]<arr2[j]) i++;

            else if(arr2[j]>arr1[i])j++;

            else{
                    res.push_back(arr1[i]);
                    i++;
                    j++;
            }
        }

        for(auto i:res)cout<<i<<" ";
}

void intersection_Brute(vector<int> &arr1,vector<int> arr2,int n1, int n2){
    vector<int> res;
    int visited[n2]={0};

    for (int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            if(arr1[i]== arr2[j] && visited[j]==0){
                res.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if(arr2[j]>arr1[i])break;
        }
    }

    for(auto i : res)cout<<i<<" ";
}
int main()
{
    vector<int> arr1={1,2,3,3,5,6};
    vector<int> arr2={2,3,4,5,6};

    // intersection_Brute(arr1,arr2,arr1.size(),arr2.size());
    intersection_Optimal(arr1,arr2,arr1.size(),arr2.size());
    return 0;
}