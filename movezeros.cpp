#include<bits/stdc++.h>
using namespace std;
void moveZeros_Optimal(int arr[], int n){
    int j = -1;
    int flag = 1;
    for (int i = 0; i<n; i++){
        if (arr[i]== 0){
            flag = 0;
            break;
        }
    }
    if(flag)return;

    else{
    for (int i = 0 ;i<n; i++){
        if(arr[i]==0){
            j = i;
            break;
        }
    }

    for (int i = j+1; i<n; i++){
        if(arr[i]!=0){
          int temp = arr[j];
          arr[j] = arr[i];
          arr[i] = temp;
          j++;
        }
    }
    }
}
void moveZeros_Brute(int arr[],int n){
    int j = -1;
    int flag = 1;
    for (int i = 0; i<n; i++){
        if (arr[i]== 0){
            flag = 0;
            break;
        }
    }
    if(flag)return;
    else{
        vector<int> temp;
        for (int i = 0; i<n ; i++){
            if(arr[i]!=0){
                temp.push_back(arr[i]);
            }
        }

        int size = temp.size();
        for (int i= 0; i<size; i++){
            arr[i] = temp[i];
        }
        for(int i = size; i < n ; i++){
            arr[i] = 0;
        }
    }
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++)cin>>arr[i];

    // moveZeros_Brute(arr,size);
    moveZeros_Optimal(arr,size);
    cout<<"Optimal Approach: ";
    for(int i = 0; i<size; i++)cout<<arr[i]<<" ";
    return 0;
}