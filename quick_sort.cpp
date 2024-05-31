#include<bits/stdc++.h>
using namespace std;

int Partition(vector<int> &arr,int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){i++;} 

        while(arr[j]>pivot && j>=low+1) {j--;}

        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high){
    if(low<high){
        int partition = Partition(arr,low,high);
        quickSort(arr,low,partition-1);
        quickSort(arr,partition+1,high);
    }
    
}
int main()
{
    vector<int> arr;
    int input;
    cout<<"Quick sort\n";
    while(cin>>input && input!=EOF){
        arr.push_back(input);
    }

    quickSort(arr,0,arr.size()-1);

    for(auto i: arr)cout<<i<<" ";
    return 0;
}