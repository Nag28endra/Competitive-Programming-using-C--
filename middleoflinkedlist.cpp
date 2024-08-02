#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
        Node(int data, Node* next){
            this->data = data;
            this->next = next;
        }

        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};
Node* convertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1;i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node* head){
    /*
        Time complexity: O(N)
    */
    Node* temp = head;

    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null";
}
Node* optimal(Node* head){
    /* 
        Time complexity: O(N/2)
        Space complexity: o(1)
    */
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* brute(Node* head){
    /*
        Time complexity: O(N + N/2)
        Space complexity: O(1)
    */
    int length = 0;
    if (head == NULL || head->next == NULL) return head;
    Node* temp = head;

    while(temp){
        length++;
        temp = temp->next;
    }
    temp = head;
    int middle = (length/2) + 1;

    while(temp){
        middle -= 1;
        if (middle == 0) break;
        temp = temp->next;
    }
    return temp;
}
int main()
{
    vector<int> arr{1,4,25,5,6};
    Node* head = convertArr2LL(arr); 
    Node* middleNode_brute = brute(head); 
    Node* middleNode_optimal = optimal(head); 
    cout<<"brute: "<<middleNode_brute->data;
    cout<<"\noptimal: "<<middleNode_optimal->data;
    // print(head); 
    return 0;
}