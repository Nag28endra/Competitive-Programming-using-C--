#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int data, Node* next, Node* prev){
            this->data  = data;
            this->next = next;
            this->prev = prev;
        }
    public:
        Node(int data){
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }
};
Node* convert2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,mover);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"null";
}
Node* reverse_brute(Node* head){
    /*
        Time complexity: O(2N);
        Space ocmplexity: O(N)
    */
    stack<int> st;
    Node* temp = head;

    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;

    while(temp){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
Node* optimal(Node* head){
    /*
        time complexity = O(N)
        space complexity = O(1)
    */
    if (head == NULL || head->next == NULL) return head;
    Node* prevNode = NULL;
    Node* current = head;

    while(current){
        prevNode = current->prev;
        current->prev = current->next;
        current->next = prevNode;
        current = current->prev;
    }
    return prevNode->prev;
}
int main()
{
    vector<int> arr{1,3,5,7};
    Node* head = convert2LL(arr);
    head = optimal(head);
    print(head);
    return 0;
}