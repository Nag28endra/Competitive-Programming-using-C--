#include<bits/stdc++.h>
using namespace std;

/*
    QUESTION:
        You are given a matrix of NxN with values 1,0. You need to find the celebrity person in them. A celebrity is someone who is 'known by everyone' but he 'don't know anyone'.

            0   1   2   3
       0 |  0   1   1   0  |
       1 |  0   0   0   0  |
       2 |  0   1   0   0  |
       3 |  1   1   0   0  |

       In the above given matrix person-1 don't know anyone but he is known by everyone.
*/
int brute(vector<vector<int>> mat){
    /*
        Time Complexity: O(N^2) + O(N)
        Space Complexity: O(2N)
    */
    int n = mat[0].size();
    vector<int> KnowMe(n,0);
    vector<int> Iknow(n,0);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(mat[i][j] == 1){
                KnowMe[j]++;
                Iknow[i]++;
            }
        }
    }

    for(int i = 0; i<n; i++){
            if(KnowMe[i] == n - 1 && Iknow[i] == 0) return i;
    }

    return -1;
}
int optimal(vector<vector<int>> mat){
    /*
        Time Complexity = O(2N)
        Space Complexity = O(1)
    */
    int top = 0, down = mat[0].size()-1;
    
    while(top<down){
        if(mat[top][down] == 1) top++;
        else if(mat[down][top] == 1) down--;
        else{
            top++;
            down--;
        }
    }

    for(int i = 0; i<mat[0].size()-1; i++){
        if( i == top) continue;
        else if (mat[top][i] == 0 && mat[i][top] == 1) continue;
        else return -1;
    }
    return top;
}
int main()
{
    vector<vector<int>> mat={
            {0,1,1,0},
            {0,0,0,0},
            {0,1,0,0},
            {1,1,0,0},
    };
    cout<<brute(mat);
    return 0;
}