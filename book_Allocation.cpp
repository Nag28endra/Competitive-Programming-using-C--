#include<bits/stdc++.h>
using namespace std;

int canHold(vector<int> bookPages, int pages, int students){
    int cntStudent = 1;
    int holding = 0;

    for(int i = 0; i<bookPages.size(); i++){
        if(holding+bookPages[i]<=pages){
            holding +=bookPages[i];
        }
        else{
            cntStudent++;
            holding = bookPages[i];
        }
    }
    return cntStudent;
}
int brute(vector<int> &bookPages, int students){
    /*
        Time complexity: O(high-low+1)xO(N)
    */
    int low = *max_element(bookPages.begin(),bookPages.end());
    int high = accumulate(bookPages.begin(),bookPages.end(),0);

    if(students>bookPages.size()) return -1;
    for(int pages = low; pages<=high; pages++){
        int cntStudents = canHold(bookPages,pages,students);
        if(cntStudents==students) return pages;
    }
    return -1;
}

int optimal(vector<int> &bookPages, int students){
    /*
        Time complexity: O(log(high-low+1)*N)
    */
    int low =  *max_element(bookPages.begin(),bookPages.end());
    int high = accumulate(bookPages.begin(),bookPages.end(),0);

    while(low<=high){
        int mid = low + (high-low)/2;
        int cntStudents = canHold(bookPages,mid,students);
        if(cntStudents>students)low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
int main()
{
    vector<int> bookPages;
    int input;
    while(cin>>input)bookPages.push_back(input);
    cout<<"brute: "<<brute(bookPages,2);
    cout<<"\noptimal: "<<optimal(bookPages,2);
    return 0;
}