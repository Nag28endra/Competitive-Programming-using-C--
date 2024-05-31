#include<bits/stdc++.h>
using namespace std;

int findSecondSmallest(vector<int> &arr){
    int smallest = arr[0];
    int ssmallest = INT_MAX;

    for (int i = 1; i<arr.size(); i++){
        if(arr[i]<smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }

        else if(arr[i]!=smallest && arr[i]<ssmallest) 
                ssmallest = arr[i];
    }

    return ssmallest;
}
int findSecondLargest(vector<int> &arr){
    int largest = arr[0];
    int slargest = -1;

    for (int i = 1; i<arr.size()-1; i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i]>slargest && arr[i]<largest)slargest = arr[i];
    }

    return slargest;
}
int main()
{
    int input;
    vector<int> arr;

    while(cin>>input && input!=EOF)arr.push_back(input);

    int slargest = findSecondLargest(arr);
    int ssmallest = findSecondSmallest(arr);

    cout<<slargest<<" "<<ssmallest; 
    return 0;
}