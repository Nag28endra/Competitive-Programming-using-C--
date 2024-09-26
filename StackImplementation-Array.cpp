#include<bits/stdc++.h>
using namespace std;

class Stack {
public:
    int top = -1;
    int stack[10];

    // Push an element onto the stack
    void push(int value) {
        if (top >= 9) { // Updated condition for stack overflow
            cout << "stack overflow\n";
        } else {
            top += 1;
            stack[top] = value;
        }
    }

    // Return the top element of the stack
    int Top() {
        if (top == -1) { // Check if stack is empty
            cout << "stack is empty\n";
            return -1; // Return a sentinel value to indicate an empty stack
        }
        return stack[top]; // Return the top element
    }

    // Pop an element from the stack
    void pop() {
        if (top == -1) {
            cout << "cannot delete - stack is empty\n";
        } else {
            top -= 1;
        }
    }

    // Return the size of the stack
    int Size() {
        return top + 1;
    }

    // Print the stack
    void print_stack() {
        if (top == -1) {
            cout << "stack is empty - cannot display it\n";
        } else {
            for (int i = 0; i <= top; i++) { // Print all elements up to top
                cout << stack[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Stack st;
    st.push(12);
    st.push(22);
    st.push(23);
    st.push(42);
    st.push(12);
    st.pop();
    st.pop();
    st.print_stack();
    cout << "Top element: " << st.Top() << endl;
    return 0;
}
