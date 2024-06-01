#include<bits/stdc++.h>
using namespace std;
int printValue(int n, int r){
    int res=1;
    for(int i = 0; i<r; i++){
        res = res*(n-i);
        res = res/(i+1); 
    }
    return res;
}

int printRow(int n){
    for(int c = 1; c<=n;c++){
        cout<<printValue(n-1,c-1)<<" ";
    }
    return 0;
}

int main()
{
    int row,col;
    int n;
    cin>>row>>col;
    cin>>n;
    // cout<<"Print the element at particular row and column\n";
    // cout<<printValue(row,col);
    printRow(n);
    return 0;
}