#include<bits/stdc++.h>
using namespace std;

int findSecondLargest_optimal(vector<int> &arr){
    int slarge = -1;
    int largest = arr[0];

    for (int i=0 ; i<arr.size()-1 ; i++){
        if( arr[i]>largest){
            slarge = largest;
            largest = arr[i];
        }

        else if(arr[i]>slarge && arr[i]<largest) slarge = arr[i];
    }
    return slarge;
}
int findSecondLargest_better(vector<int> &arr){
    int largest = arr[0];
    int slargest = -1;

    for(int i = 1; i<arr.size()-1; i++){
        if(arr[i]>largest) largest = arr[i];
    }

    for(int i = 0; i<arr.size()-1; i++){
        if(arr[i]>slargest && arr[i] != largest) slargest = arr[i];
    }

    return slargest;
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF) arr.push_back(input);

    cout<<"Second Largest (better): "<<findSecondLargest_better(arr);   
    cout<<"\nSecond Largest (optimal): "<<findSecondLargest_optimal(arr);   
    return 0;
}