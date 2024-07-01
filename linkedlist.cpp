#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int d, Node* n){
        data = d;
        next = n;
    }
    
    public:
    Node(int d){
        data =d;
        next = nullptr;
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
void traverse(Node* head){
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
int length(Node* head){
    /*
        Time complexity: O(N)
    */
    int len = 0;
    Node* temp = head;

    while(temp){
        temp = temp->next;
        len++;
    }
    return len;
}
int search(Node* head, int target){
    /*
        Time complexity: O(N) in the worst case O(1) in the best 
    */
    Node* temp = head;

    while(temp){
        if( temp->data == target)return 1;
        temp = temp->next;
    }
    return 0;
}
int main()
{
    vector<int> arr{1,4,25,5};
    Node* head = convertArr2LL(arr);
    cout<<"lenght of the linked list: "<<length(head)<<endl;
    traverse(head);
    cout<<"\n"<<search(head,28);
    return 0;
}