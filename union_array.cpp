#include<bits/stdc++.h>
using namespace std;

void Union_Optimal(int arr1[],int arr2[],int s1, int s2){
    int i = 0, j =0;
    vector<int> temp;
    while(i<s1 && j<s2){
        if(arr1[i]<=arr2[j]){
                if(temp.size()==0 || temp.back()!=arr1[i]){
                    temp.push_back(arr1[i]);
                }
                i++;
        }
        else{
            if(temp.size()==0 || temp.back()!=arr2[j]){
                    temp.push_back(arr2[j]);
                }
                j++;
        }
    }
    while(j<s2){
        if(temp.size()==0 || temp.back()!=arr2[j]){
                    temp.push_back(arr2[j]);
                }
                j++;
    }
    while(i<s1){
        if(temp.size()==0 || temp.back()!=arr1[i]){
                    temp.push_back(arr1[i]);
                }
                i++;
    }

    for(auto i: temp)cout<<i<<" ";

}
void Union_Brute(int arr1[], int arr2[],int s1, int s2){
    set<int> temp;
   

    for(int i = 0 ; i<s1; i++){
        temp.insert(arr1[i]);
    }
    for(int i = 0 ; i<s1; i++){
        temp.insert(arr2[i]);
    }

    for (auto i:temp)cout<<i<<" ";

}
int main()
{
    int s1, s2;
    cin>>s1>>s2;
    int arr1[s1];
    int arr2[s2];
    
    for (int i = 0; i<s1; i++)cin>>arr1[i];
    for (int i = 0 ; i<s2; i++)cin>>arr2[i];
                
    // Union_Brute(arr1,arr2,s1,s2);
    Union_Optimal(arr1,arr2,s1,s2);
    return 0;
}