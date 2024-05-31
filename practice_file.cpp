#include<bits/stdc++.h>
using namespace std;


void optimalApproach(int A[],int B[], int s1, int s2){
    int i = 0, j = 0;
    vector<int> res;

    cout<<"\nOptimal Approach: ";
    while(i<s1 && j<s2){
        if(A[i]<B[j])i++;
        else if(A[i]>B[j])j++;

        else{
            res.emplace_back(A[i]);
            i++;
            j++;
        }
    }
    for(auto i:res)cout<<i<<" ";
    
}

void bruteApproach(int A[],int B[], int s1, int s2){
       int visited[s2]={0};
       vector<int> res;

        cout<<"Brute Approach: ";
       for(int i = 0;i<s1;i++){
        for(int j = 0; j<s2; j++){
            if(A[i]==B[j] && visited[j]==0){
                visited[j]=1;
                res.push_back(A[i]);
                break;
            }
            if(A[i]<B[j])break;
        }
       }
       for(auto i:res)cout<<i<<" ";
}

   
int main(){
    int s1,s2;
    cin>>s1>>s2;
    int A[s1],B[s2];

    for(int i = 0; i<s1; i++)cin>>A[i];
    for(int j = 0; j<s2; j++)cin>>B[j];

    bruteApproach(A,B,s1,s2);
    optimalApproach(A,B,s1,s2);
    return 0;
}