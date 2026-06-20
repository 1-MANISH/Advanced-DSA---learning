#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void build(int n) {
        Node* tail = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            Node* node = new Node(x);
            if (!head) head = tail = node;
            else tail->next = node, tail = node;
        }
    }

    void print() {
        bool first = true;
        Node* cur = head;
        while (cur) {
            if (!first) cout << ' ';
            cout << cur->val;
            first = false;
            cur = cur->next;
        }
        cout << "\n";
    }

    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

/*
    Implement only the class below.
*/
class MyLinkedList {
public:
    Node* head;
    MyLinkedList(Node* head) {
        this->head=head;
    }

    int get(int index) {
        if(index<=0){
            return head?head->val:-1;
        }
        int cnt = 0 , len = 0;
        Node* temp = this->head ;
        Node* ptr = this->head;
        while(ptr!=NULL){
            len++;
            if(cnt<index){
                cnt++;
                temp = temp->next;    
            }
            ptr=ptr->next;
        }
        return index>=len ? -1 :temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = this->head;
        this->head=newNode;
    }

    void addAtTail(int val) {
        if(this->head==NULL){
            addAtHead(val);
            return;
        }
        Node* temp = this->head;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
        }
        Node* newNode = new Node(val);
        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {
        index = index<0 ?0:index;
        if(index==0){
            addAtHead(val);
            return;
        }
        int cnt = 0 ,len  = 0;
        Node* temp = this->head;
        Node* ptr = this->head;
        while(ptr!=NULL){
            len++;
            if(cnt<index-1){
                cnt++;
                temp=temp->next;
            }
            ptr=ptr->next;
        }
        if(index>len){
             return;
        }
        if(index==len){
            addAtTail(val);
            return;
        }
        Node* t = temp->next;
        temp->next = new Node(val);
        temp->next->next = t;


    }

    void deleteAtIndex(int index) {
        if(head==NULL)return;
        if(index<=0){
            Node* temp = this->head;
            this->head = temp->next;
            delete temp;
            return;
        }
        int cnt =0 ,len = 0 ;
        Node* temp = this->head;
        Node* ptr = this->head;
        while( ptr!=NULL){
            len++;
            if(cnt<index-1){
                temp=temp->next;
                cnt++;
            }
            ptr=ptr->next;
            
        }
        if(index>=len)return;
        Node* t  = temp->next;
        temp->next = t->next;
        delete t;
    }

    Node* getHead() {
        return this->head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;
    ll.build(n);

    MyLinkedList my(ll.head);


    int Q;
    cin >> Q;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int index;
            cin >> index;
            cout << my.get(index) << "\n";
        } else if (type == 1) {
            int val;
            cin >> val;
            my.addAtHead(val);
        } else if (type == 2) {
            int val;
            cin >> val;
            my.addAtTail(val);
        } else if (type == 3) {
            int index, val;
            cin >> index >> val;
            my.addAtIndex(index, val);
        } else {
            int index;
            cin >> index;
            my.deleteAtIndex(index);
        }
    }

    ll.head = my.getHead();
    ll.print();
    return 0;
}