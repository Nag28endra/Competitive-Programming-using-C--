#include<iostream>
using namespace std;

void pattern1(int n){
    for(int i=0; i<n ; i++){
        for (int j=1; j<=n-i; j++)cout<<j<<" ";
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    pattern1(n);
    
    return 0;
}