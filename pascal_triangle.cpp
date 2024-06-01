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
int main()
{
    int row,col;
    cin>>row>>col;
    cout<<"Print the element at particular row and column\n";
    cout<<printValue(row,col);
    return 0;
}