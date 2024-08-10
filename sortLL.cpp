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
    Node* findMiddle(Node* head){
            Node* slow = head;
            Node* fast = head->next;

            while(fast!= NULL && fast->next !=NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
    }
    Node* merge(Node* l1, Node* l2){
        Node* t1 = l1;
        Node* t2 = l2;
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while(t1!=NULL && t2!=NULL){
            if(t1->data < t2->data){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }

        }
        if(t1) temp->next = t1;
        else temp->next = t2;

        return dummyNode->next;
    }
    Node* sortLL(Node* head){
        if (head == NULL || head->next == NULL) return head;
        Node* middleNode = findMiddle(head);
        Node* leftHead = head;
        Node* rightHead = middleNode->next;
        middleNode->next = NULL;
        leftHead = sortLL(leftHead);
        rightHead = sortLL(rightHead);

        return merge(leftHead,rightHead);
    }
    int main()
    {
        vector<int> arr{21,3,28,12,7};
        Node* head = convertArr2LL(arr);
        head = sortLL(head);
        
        print(head);
        return 0;
    }