#include<bits/stdc++.h>
using namespace std;
string changeBrackets(string s){
    int len = s.size();
    for(int i = 0; i < len; i++){
        if( s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
        else continue;
    }
    return s;
}
bool isOperand(char ch){
    return ( (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <='z') || (ch >= '0' && ch <='9') );
}
int priority(char ch){
    if (ch == '^') return 3;
    else if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else return -1;
}
string InfixToPrefix(string s){
    reverse(s.begin(),s.end());
    s = changeBrackets(s);

    int i = 0;
    stack<char> st;
    string ans = "";

    while(i < s.size()){
        // if operand store it in the answer.
        if( isOperand(s[i])) ans += s[i];

        // if opening bracket push it into the stack.
        else if( s[i] == '(') st.push(s[i]);

        // if closing bracket, pop out the operators from the stack 
        else if (s[i] == ')'){
            while( !st.empty() && st.top() != '(' ){
                ans += st.top();
                st.pop();
            }
            // pop out the '(' bracket
            st.pop();
        }

        else{
                if(s[i] == '^'){
                    while( !st.empty() && priority(s[i]) <= priority(st.top())){
                        ans += st.top();
                        st.pop();
                    }
                }
                else{
                    while( !st.empty() && priority(s[i]) < priority(st.top()) ){
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(s[i]);
        }
        i++;
    }

    while( !st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
     string s;
     cin>>s;
     cout<<InfixToPrefix(s);
    return 0;
}