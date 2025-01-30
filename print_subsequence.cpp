#include <iostream>
#include <vector>

using namespace std;

void printS(vector<int>& result, int n, vector<int>& input,int idx) {
    if (idx==n) {
        for (int i : result) cout<<i<<" ";
        if (result.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    // pick the first element
    result.push_back(input[idx]);
    // call the function
    printS(result,n,input,idx+1);
    // remove the picked element
    result.pop_back();
    // call the function to don't pick any element
    printS(result,n,input,idx+1);
}

int main() {
    int size;
    cin >> size;
    
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    vector<int> result;
    printS(result, size, arr,0);
    
    return 0;
}