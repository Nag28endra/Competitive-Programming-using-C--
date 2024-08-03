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
Node* reverse_recursion(Node* head){
    /*
        time complexity: O(N)
        space complexity: O(N) bcoz it is using stack  
    */
    // if there is a single node.
    if ( head == NULL || head->next == NULL)return head;
    
    //recursion
    Node* newNode = reverse_recursion(head->next);
    Node* frontNode = head->next;
    frontNode->next = head;
    head->next = NULL;
    return newNode;

}
Node* reverse_iterative(Node* head){
    /*
        Time complexity: O(N)
        space complexity: O(1)
    */
      Node* temp = head;
      Node* prev = NULL;

      while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
      }
      return prev;
}
int main()
{
    vector<int> arr{1,4,25,5};
    Node* head = convertArr2LL(arr);
    
    // head = reverse_iterative(head);
    head = reverse_recursion(head);
    print(head);
    return 0;
}