#include<bits/stdc++.h>
using namespace std;

int main()
{
    string jewels, stones;
    getline(cin,jewels);
    getline(cin,stones);
    int count=0;

    for(int i = 0; i<jewels.length();i++){
        for( int j = 0; j<stones.length(); j++){
                if(jewels[i]==stones[j])count++;
        }
    }
    cout<<"Stones:"<<count;
    return 0;
}