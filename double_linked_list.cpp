#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data, Node* next, Node* prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    Node(int data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};
Node* convert2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head){
    while(head){
        cout<<head->data<<"<->";
        head = head->next;
    }
    cout<<"null";
}
Node* deleteHead(Node* head){
    /*
        Time complexity: O(1)
    */
    Node* prev = head;
    if(head == NULL || head->next == NULL) return NULL;

    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}
Node* deleteTail(Node* head){
    Node* temp = head;
    // checking if the linked list is empty or containing single element
    if(head == NULL || head->next == NULL) return NULL;
    while(temp->next){
        temp = temp->next;
    }
    Node* prevNode = temp->prev;
    prevNode->next = nullptr;
    temp->prev = nullptr;
    //deleting the old tail from the memory.
    delete temp;
    return head;
}
Node* deletePos(Node* head,int pos){
    Node* temp = head;
    int cnt = 0;

    while(temp){
        cnt++;
        if(cnt==pos)break;
        temp = temp->next;
    }
    Node* prevNode = temp->prev;
    Node* afterNode = temp->next;
    //checking if it is single node;
    if(prevNode==NULL && afterNode == NULL) {
        delete temp;
        return NULL;
    }
    // checking if it is the head of the node.
    else if (prevNode == NULL) return deleteHead(head);
    // if it is a tail of the node that is to be deleted.
    else if (afterNode == NULL) return deleteTail(head);
    else{
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }
    return head;
}
void deleteNode(Node* node){
    Node* prevNode = node->prev;
    Node* afterNode = node->next;

    if(afterNode == NULL){
        prevNode->next = nullptr;
        node->prev = nullptr;
        free(node);
        return;
    }
    prevNode->next = afterNode;
    afterNode->prev = prevNode;
    
    node->next = nullptr;
    node->prev = nullptr;
    free(node);
}
Node* insertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val,head,nullptr);
    head->prev = newNode;
    return newNode;
}
Node* insertAfterHead(Node* head, int val){
    Node* newNode = new Node(val,head,nullptr);
    Node* afterHeadNode = head->next;
    newNode->next =afterHeadNode;
    afterHeadNode->prev = newNode;
    head->next = newNode;
    newNode->prev = head;
    return head;
}
Node* insertBeforeTail(Node* head, int val){
    if(head == NULL) return new Node(val);
    if (head->next == NULL) return insertAfterHead(head, val);

    Node* temp = head;

    while(temp->next->next){
        temp = temp->next;
    }
    Node* tail = temp->next;
    Node* newNode = new Node(val,tail,temp);
    temp->next = newNode;
    tail->prev = newNode;
    return head;
}
Node* insertAfterTail(Node* head, int val){
    if(head == NULL) return new Node(val);
    if(head->next == NULL) return insertAfterHead(head, val);

    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* newNode = new Node(val,nullptr,temp);
    temp->next = newNode;
    return head;
}
Node* insertBeforePos(Node* head, int val, int pos){
    if(pos == 1) return insertBeforeHead(head, val);
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if (cnt == pos) break;
        temp = temp->next;
    }
    Node* prevNode = temp->prev;
    Node* afterNode = temp;

    Node* newNode = new Node(val,afterNode, prevNode);
    prevNode->next = newNode;
    afterNode->prev = newNode;

    return head;
}
Node* insertAfterPos(Node* head, int val, int pos){
    if(pos == 1) return insertBeforeHead(head, val);
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if (cnt == pos) break;
        temp = temp->next;
    }
    Node* prevNode = temp;
    Node* afterNode = temp->next;

    Node* newNode = new Node(val,afterNode, prevNode);
    prevNode->next = newNode;
    afterNode->prev = newNode;

    return head;
}
int main()
{
    vector<int> arr{15,25};
    Node* head = convert2DLL(arr);
    head = deletePos(head,2);
    print(head);
    return 0;
}