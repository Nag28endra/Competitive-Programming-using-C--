#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
    // checks it is an character or digit.
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
}
string Postfix2Prefix(string s){
    int i = 0;
    stack<string> st;

    while(i< s.size()){
        // if operand push it into the stack
        if(isOperand(s[i])) {
            string value = "";
            value += s[i];
            st.push(value);
        }
        // if the value is an operator.
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string newString = s[i]+t2+t1; // this is the main expression: operator + top2 + top1;
            st.push(newString);
        }
        i++;
    }
    // answer will at the top of the stack
    return st.top();
}
int main()
{
    string s;
    cin>>s;
    cout<<Postfix2Prefix(s);
    return 0;
}

/*
 Time complexity: O(2N)
 Space complexity: O(N)

*/