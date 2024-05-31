#include<bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr){
    for (int i = arr.size()-1; i>=1; i--){
        for(int j = 0; j<=i-1 ; j++){
            if (arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
        }
    }
}

int missingValue(vector<int> &arr){
    for(int i=0; i<=arr.size(); i++){
        if (arr[i]!=i+1)return (i+1);
    }
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input && input!=EOF)arr.push_back(input);
    sortArray(arr);

    cout<<missingValue(arr);
    return 0;
}