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
    int size;
    LinkedList() : head(nullptr),size(0) {}

    void build(int n) {
        Node* tail = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            Node* node = new Node(x);
            if (!head) head = tail = node;
            else tail->next = node, tail = node;
            size++;
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
    int size;
    MyLinkedList(Node* head,int size=0) {
        this->head=head;
        this->size=size;
    }

    int get(int index) {
        if(index<0 || index>=size)return -1;
        int cnt = 0 ;
        Node* current  = head ;
        while(cnt<index){
            cnt++;
            current  = current ->next;    
        }
        return current ?current ->val:-1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head=newNode;
        size++;
    }

    void addAtTail(int val) {
        if(head==NULL || size==0){
            addAtHead(val);
            return;
        }
        Node* current  = head;
        while(current!=NULL && current->next!=NULL){
            current=current->next;
        }
        Node* newNode = new Node(val);
        current->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        index = index < 0 ? 0 : index;
        if(index>size)
            return;

        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }

        int cnt = 0 ;
        Node* current =head;
        while(cnt<index-1){
            cnt++;
            current=current->next;
        }
        Node* newNode = new Node(val);
        Node* temp = current->next;
        current->next=newNode;
        newNode->next = temp;
        size++;
    }

    void deleteAtIndex(int index) {
        if(head==NULL)return;
        if(index<0 || index>=size)return;
        size--;
        if(index==0){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        int cnt = 0;
        while(cnt<index-1){
            current=current->next;
            cnt++;
        }
        Node* temp = current->next;
        current->next = temp?temp->next:NULL;
        delete temp;
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

    MyLinkedList my(ll.head,ll.size);


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