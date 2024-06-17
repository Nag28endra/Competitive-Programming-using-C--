#include<bits/stdc++.h>
using namespace std;

int fun(int mid, int n, int m){
    __int128_t res = 1;

    for(int i = 1; i<=n; i++){
        res *= mid; //mid*mid*..
        if(res>m)return 2; //saying that the answer exceeds the m value.
    }
    if (res==m)return 1; // if the answer equals to m
    return 0;   // if the answer is less than m.
}
int optimal(int n, int m){

    /*
        Time compelxity: O(logN)+ O(n)
        Space complexity: O(1)
    */
    int low = 1;
    __int128_t high = m;

    while(low<=high){
        __int128_t mid = (low+high)/2;

        __int128_t midN = fun(mid,n,m); //find m^n

        if(midN==1)return mid;
        else if(midN==2)high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<"optimal: "<<optimal(n,m);
    return 0;
}