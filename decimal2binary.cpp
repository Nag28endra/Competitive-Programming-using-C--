#include<bits/stdc++.h>
using namespace std;

string toBinary(int data) {
    if (data == 0) return "0"; // Handle the case for data = 0
    string s = "";
    while (data > 0) {
        if (data % 2 == 1) s += '1';
        else s += '0';
        data /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    int data;
    cin >> data;

    string result = toBinary(data);
    cout << result;
    return 0;
}
