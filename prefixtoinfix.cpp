#include<bits/stdc++.h>
using namespace std;
bool isOperand(char ch){
    // checks it is an character or digit.
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
}
string PrefixToInfix(string s){
    int i = s.size() - 1; // traverse from the back.
    stack<string>st;

    while(i>=0){
        // if operand store it in the stack.
        if(isOperand(s[i])) {
            string value = "";
            value += s[i];
            st.push(value);
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string newString = "("+t1+s[i]+t2+")";
            st.push(newString);
        }
        i--;
    }
    return st.top();
}
int main()
{
    string s;
    cin>>s;
    cout<<PrefixToInfix(s);
    return 0;
}