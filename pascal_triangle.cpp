#include<bits/stdc++.h>
using namespace std;
int NcR(int n, int r){
    int res=1;
    for(int i = 0; i<r; i++){
        res = res*(n-i);
        res = res/(i+1); 
    }
    return res;
}
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(ans);

    for(int i = 1; i<row; i++){
        ans *= (row-i);
        ans /= i;
        ansRow.push_back(ans);
    }
    return ansRow;
}
void PascalTriangle_optimal(int n){
    vector<vector<int>> ans;

    for(int i=1; i<=n; i++){
        ans.push_back(generateRow(i));
    }
    for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j]<<" ";
            }
            cout<<endl;
        }
}
int PascalTriangle_brute(int  n){
    vector<vector<int>> res;

    for(int row =1; row<n; row++){
        vector<int> temp;
        for(int col = 1; col<n; col++){
                int val = NcR(row-1,col-1);
                if(val!=0)
                    temp.push_back(val);
        }
        res.push_back(temp);
    }
    for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                cout << res[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
}
int printRow_optimal(int n){
    int res = 1;
    cout<<res<<" ";
    for(int i = 1; i<n; i++){
        res *=(n-i);
        res /= i;
        cout<<res<<" ";
    }
    return 0;
}

int printRow_brute(int n){
    for(int c = 1; c<=n;c++){
        cout<<NcR(n-1,c-1)<<" ";
    }
    return 0;
}

int main()
{
    int row,col;
    int n;
    // cin>>row>>col;
    cin>>n;
    // cout<<"Print the element at particular row and column\n";
    // cout<<NcR(row,col);
    // printRow_brute(n);
    // printRow_optimal(n);
    // PascalTriangle_brute(n);
    PascalTriangle_optimal(n);
    return 0;
}