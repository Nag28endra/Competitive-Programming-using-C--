#include<bits/stdc++.h>
using namespace std;
int findArea(vector<int> boards, int area){
    int n = boards.size();
    int cntBoards = 1;
    long long partition = 0;

    for(int i = 0; i<n; i++){
        if (partition+boards[i]<=area){
            partition +=boards[i];
        }
        else{
            partition = boards[i];
            cntBoards++;
        }
    }
    return cntBoards;
}
int brute(vector<int> boards, int k){
    /*
        Time complexity: O(sum-max)xO(N)
    */
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);

    if(k>boards.size()) return -1;
    for(int i = low; i<=high; i++){
        int areas = findArea(boards,i);
        if(areas==k) return(i);
    }
    return -1;
}
int optimal(vector<int> boards, int k){
    /*
        Time complexity: O(log(sum-max))xO(N)
    */
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);

    while(low<=high){
        int mid = low + (high-low)/2;

        int area = findArea(boards,mid);
        if(area>k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
int main()
{
    vector<int> boards;
    int input;
    while(cin>>input)boards.push_back(input);
    cout<<"brute: "<<brute(boards,2);
    cout<<"\noptimal: "<<optimal(boards,2);
    return 0;
}