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
Node* removeHead(Node* head){
    if (head == NULL)return head;
    Node* temp = head;
    head = head->next;
    //deleting the previous head from the heap.
    delete temp;
    return head;
}
Node* removeTail(Node* head){

    //checking if the linked list is empty or it is having only one node
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    // deleting the last node called tail from the heap
    free(temp->next);
    temp->next = nullptr;
    return head;
}
Node* removePos(Node* head,int k){
    // if the linked list is null return the linked list.
    if(head == NULL) return head;

    // if the linked list is having single element return that.
    if(k==1) return removeHead(head);
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node* removeValue(Node* head,int value){
    // if the linked list is null return the linked list.
    if(head == NULL) return head;

    // if the linked list is having single element return that.
    if(head->data==value) return removeHead(head);
    Node* temp = head;
    Node* prev = NULL;
    
    while(temp){
        if(temp->data == value){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr{1,4,25,5};
    Node* head = convertArr2LL(arr);
    head = removeValue(head,5);
    traverse(head);
    return 0;
}