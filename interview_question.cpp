#include<bits/stdc++.h>
using namespace std;
bool wordPattern(string p,string s){
    vector<string> words;
    string t="";

    for(int i=0; i<=s.size(); i++){
        
        if(s[i]=='\0'){
            words.emplace_back(t);
            break;
        }

        else if(s[i]==' '){
            words.emplace_back(t);
            t="";
        }

        else t+=s[i];

    }
    
    if(words.size()!=p.size())return false;
    for(int i=0; i<words.size()-1 ;i++){
        for(int j=0; j<words.size()-1; j++){
            if(words[i]==words[j] && p[i]!=p[j])
            {
                return false;
                
            }

            if(p[i]==p[j] && words[i]!=words[j]) {
                return false;
                
            }
    }
    
    }
    return true;
}

int main()
{
    string p,s;
    getline(cin,p);
    getline(cin,s);

    cout<<wordPattern(p,s);
    
    return 0;
}