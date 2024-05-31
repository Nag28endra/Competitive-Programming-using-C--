#include<iostream>
using namespace std;
void Reverse(int arr[], int start, int end){
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void leftRotate_Optimal(int arr[], int n , int d){
    d %= n;
    if(n<d){
        Reverse(arr,0,n-1);
    }
    else{
        Reverse(arr,0,n-1);
        Reverse(arr,0,d-1);
        Reverse(arr,d,n-1);
        
    }
}
void leftRotate_Brute(int arr[],int n, int d){

    // overall time complexity = O(n+d)
    // overall space complexity = O(d)

    d %= n;
    int temp[d];

    for(int i =0 ;i<d; i++)temp[i] = arr[i]; //O(d)

    for(int i = d;i<n; i++){
        arr[i-d] = arr[i]; //O(n-d)
    }

    for(int i = n-d; i<n; i++){
        arr[i] = temp[i - (n-d)]; //O(d)
    }
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    
    for(int i =0; i<size; i++)cin>>arr[i];

    // leftRotate_Brute(arr,size, 3);
    // cout<<"Brute Force: ";
    // for(int i = 0; i<size; i++)cout<<arr[i]<<" ";

    leftRotate_Optimal(arr,size,2);
    cout<<"Optimal appraoch:";
    for(int i = 0; i<size; i++)cout<<arr[i]<<" ";
    return 0;
}