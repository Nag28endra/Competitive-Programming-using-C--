#include<bits/stdc++.h>
using namespace std;
void brute(string s){
    s+=" ";
    stack<string> st;
    
    string str="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            st.push(str);
            str="";
        }
        else str+=s[i];
    }
    string ans="";
    while(st.size()!=1)
    {
        ans+=st.top()+" ";
        st.pop();
    }
    ans+=st.top();// The last word should'nt have a space after it
    cout<<"After reversing words: "<<endl;
    cout<<ans;
}
int main()
{
    string s;
    getline(cin,s);
    cout<<"Before reversing words: "<<endl;
    cout<<s<<endl;
    brute(s);
    
    return 0;
}