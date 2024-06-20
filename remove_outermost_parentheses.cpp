#include<bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s, int n){
    /*
        Time complexity: O(N)
        Space complexit: O(N)
    */
    string res = "";
    int balance = 0;

    for(int i = 0; i<n; i++){
        if(s[i]=='('){
            // if the balance is greater than 0 that means it is not the outermost parantheses.
            if(balance>0){
                res +=s[i];
            }
            balance++;
        }
        else{
            balance--;
            // if the balance is greater than 0 that means it is not the outermost parantheses.
            if(balance>0) res +=s[i];
        }
    }
    return res;
}
int main()
{
    string s;
    getline(cin,s);
    cout<<removeOuterParentheses(s,s.size());
    return 0;
}