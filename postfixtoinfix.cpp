#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){

    // checking if the value is operand or not.
    return ( (ch >= 'A' && ch <= 'Z' ) || (ch >= 'a' && ch <='z') || (ch >='0' && ch <= '9') );
}
string changeBrackets(string s){
    int len = s.size();
    for(int i = 0; i < len; i++){
        if( s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
        else continue;
    }
    return s;
}
string PostToInfix(string s){
    int i = 0;
    stack<string> st;

    while(i<s.size()){
        // if it is operand push it into the stack.
        if(isOperand(s[i])){
            string value = "";
            value += s[i];
            st.push(value);
        }
        //if it is operator, take out first and second operands from the stack and keep operator between them.
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string newString = "(" + t1 + s[i] + t2+ ")";
            st.push(newString);
        }
        i++;
    }
    string ans = st.top();
    reverse(ans.begin(),ans.end());

    return changeBrackets(ans);
}
int main()
{
    string s;
    cin>>s;
    cout<<PostToInfix(s);
    return 0;
}

/*
    Time complexity : O(2N)
    Space complexity: O(N)
*/