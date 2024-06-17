#include<bits/stdc++.h>
using namespace std;

int optimal(int n){

    /*
        Time complexity: O(logN)
        Space compleixyt: O(1)
    */
    int low = 1;
    int high = n;

    __int128_t res = 1;

    while(low<=high){
        __int128_t mid = (low+high)/2;

        if((mid*mid)<=n){
            res = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return res;
}
int brute(int n){

    /*
        Time complexity: O(N)
        Space compleixty: o(1)
    */
    __int128_t res=1;

    for(int i = 0; i<=n; i++){
        if(i*i<=n){
            res = i;
        }
        else{
            break;
        }
    } 
    return res;
}
int main()
{
    int n;
    cin>>n;

    cout<<"Brute: "<<brute(n);
    cout<<"\nOptimal: "<<optimal(n);
    return 0;
}