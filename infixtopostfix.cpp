#include<bits/stdc++.h>
using namespace std;

bool check(char ch){
        
        return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >='0' && ch <='9') );
}
    
int priority(char ch){
        if (ch == '^') return 3;
        else if (ch == '*' || ch =='/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        else return -1;
}
string InfixToPostfix(string s) {
        int i = 0;
        stack<char> st;
        string ans = "";
        
        int len = s.size();
        
        while(i<len){
            
            if(check (s[i])) ans += s[i];
            
            else if(s[i] == '(') st.push(s[i]);
            
            else if (s[i] == ')'){
                while( !st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            
            else{
                
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
}
int main()
{
    string input;
    cin>>input;
    cout<< InfixToPostfix(input);   
    return 0;
}

/*
    Time complexity : O(N) + O(N)
    Space complexity : O(N) + O(N)
    
*/