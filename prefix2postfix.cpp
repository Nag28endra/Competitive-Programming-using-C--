#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
    // checks it is an character or digit.
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
}
string PrefixToPostfix(string s){
    int i = s.size() - 1;
    stack<string> st;

    while(i>=0){
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

            string newString = t1+t2+s[i]; // expression: top1 + top2 + operator;
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
    cout<<PrefixToPostfix(s);
    return 0;
}