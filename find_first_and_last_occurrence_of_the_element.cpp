#include<bits/stdc++.h>
using namespace std;

int findLast(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n-1;
    int last = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if (arr[mid]==x){
            last = mid;
            low = mid + 1; 
        }
        else if (arr[mid]>x)high = mid - 1;
        else low = mid + 1;
    }
    return last;
}
int findFirst(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n-1;
    int first = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if (arr[mid]==x){
            first = mid;
            high = mid - 1; 
        }
        else if (arr[mid]>x)high = mid - 1;
        else low = mid + 1;
    }
    return first;
}
pair<int,int> optimal(vector<int> &arr, int n, int x){

    /*
        The optimal solution makes use of simple binary search;
        It performs binary search 2-times to find the first and last element.

        When it is find the first occurrence using BS it eliminates the right search space.

        when it is finding the last occurrence using BS it eliminates the left search space.

        Time complexity: 2xo(logN)
        Space complexity: O(1)
    */
    cout<<"Optimal:\n";
    int first = findFirst(arr,n,x);
    if (first == -1) return {-1,-1};
    int last = findLast(arr,n,x);

    return {first,last};
}
int findUpperBound(vector<int> &arr,int n, int x){
    int low = 0;
    int high = n - 1;
    int res = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (arr[mid]>x){
            res = mid ;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return res;
}
int findLowerBound(vector<int> &arr,int n, int x){
    int low = 0;
    int high = n-1;
    int res = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]>=x){
            res = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return res;

}
pair<int,int> better(vector<int> &arr, int n, int x){
    /*
        The better solution uses the concept of lower bound and upper bound.

        The lower bound -- will find the first occurrence of the value.
        The upper bound -- will find the last occurrence of the value.

        At the end we need to subtract 1 from the returned value of the upper bound or else we may encounter size of the data structure.

        Time complexity : 2xO(logN)
        Space complexity: O(1)
    */

    cout<<"\nbetter:";
    int lowerBound = findLowerBound(arr,n,x);
    // check if the lower bound is out index or not.
    if ((lowerBound == n) || (arr[lowerBound]!=x)) return {-1,-1};
    
    return {lowerBound, findUpperBound(arr,n,x)-1};
}
pair<int,int> brute(vector<int> &arr, int n , int x){
    /*
        Time complexity: O(N)
        Space complexity: O(1)
    */
    cout<<"brute:\n";
    int first = -1;
    int last = -1;

    for(int i = 0; i<n; i++){
        if (arr[i]==x){
            if (first == -1) first = i;
            last = i; // we are only changing the last value till the end of the array once if we found the first.
        }
    }
    return {first,last};
}
int main()
{
    vector<int> arr;
    int input;

    while(cin>>input)arr.push_back(input);

    // pair<int,int> res  = brute(arr,arr.size(),4);
    // pair<int,int> res = better(arr,arr.size(),4);
    pair<int,int> res = optimal(arr,arr.size(),4);

    cout<<"["<<res.first<<","<<res.second<<"]";
    return 0;
}