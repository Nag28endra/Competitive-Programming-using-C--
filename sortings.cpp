#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;

    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i<=high ; i++) arr[i]=temp[i-low];
}
void mergeSort(vector<int> &arr, int low, int high){
    if(low == high)return;

    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int Partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){

        while(arr[i]<=pivot && i<=high-1)i++;
        while(arr[j]>pivot && j>=low+1) j--;

        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high){

    if(low<high){
        int partition = Partition(arr, low, high);
        quickSort(arr,low,partition-1);
        quickSort(arr,partition+1,high);
    }
}
int main()
{
    int input;
    vector<int> arr;
    while(cin>>input && input!=EOF) arr.push_back(input);

    // quickSort(arr,0,arr.size()-1);
    // cout<<"Quick Sort :";
    mergeSort(arr,0,arr.size()-1);
    cout<<"Merge Sort: ";
    for(auto i: arr)cout<<i<<" ";
    return 0;
}