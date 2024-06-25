#include<bits/stdc++.h>

using namespace std;
double optimal(vector<int> arr1, vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    if(n1>n2) return optimal(arr2,arr1);
    int left = (n1+n2+1)/2;
    int low = 0;
    int high = n1;
    int n = n1 + n2;
    while(low<=high){
        int mid1 =  (low+high)>>1;
        int mid2 = left - mid1;
        int r1 = INT_MAX, r2 = INT_MAX;
        int l1 = INT_MIN, l2 = INT_MIN;
        if(mid1<n1) r1 = arr1[mid1];
        if(mid2<n2) r2 = arr2[mid2];
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];

        if(l1<=r2 && l2<=r1){
            if (n%2==1) return(max(l1,l2));
            else{
                return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }
        }
        else if (l1>r2) high = mid1 - 1;
        else low = mid1 + 1;

    }
    return 0;
}
double brute(vector<int> arr1, vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1+n2;
    vector<int> res;
    int i = 0, j = 0;

    while(i<=n1 && j<=n2){
        if(arr1[i]<arr2[j]){
            res.push_back(arr1[i]);
            i++;
        }
        else{
            res.push_back(arr2[j]);
            j++;
        }
    }
    while(i<=n1){
        res.push_back(arr1[i++]);
    }
    while(j<=n2){
        res.push_back(arr2[j++]);
    }
    if(n%2==1){
        return n/2;
    }
    else{
        int idx = n/2;
        return (double)(res[idx-1]+res[idx])/2.0;
    }
    return 0;
}
int main()
{
    vector<int> arr1{2,4,6};
    vector<int> arr2{1,3,5};
    cout<<"brute: "<<brute(arr1,arr2);
    cout<<"\noptimal: "<<optimal(arr1,arr2);
    return 0;
}