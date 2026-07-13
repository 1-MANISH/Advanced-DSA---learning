#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below (a queue backed by a singly linked list).
    void push(int x) -- insert x at the back.
    int  pop()       -- remove and return the front element; -1 if empty.
    int  front()     -- return the front element; -1 if empty.
    int  back()      -- return the last element; -1 if empty.
    bool empty()     -- return true if the queue is empty, else false.
    int  size()      -- return the number of elements.
    All operations must run in O(1).
*/

class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value=value;
        this->next=NULL;
    }
};

class LinkedList{
    public:
    Node* head,*tail;
    int _size;

    LinkedList(){
        this->_size=0;
    }

    void insertAtTail(int x){
        Node* newNode = new Node(x);
        if(size()==0){
            tail=head=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
        _size++;
    }
    int deleteAtHead(){
        if(size()==0)return -1;
        Node* temp = head;
        head=head->next;
        int value = temp->value;
        delete temp;
        _size--;
        return value;
    }
    int size(){
        return _size;
    }
};


class MyQueue {
    LinkedList ll;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        ll.insertAtTail(x);
    }
    
    int pop() {
        return ll.deleteAtHead();
    }
    
      int front()
    {
         return ll.size()==0?-1:ll.head->value;
    }

    int back()
    {
         return ll.size()==0?-1:ll.tail->value;
    }

    
    bool empty() {
        return ll.size()==0;
    }
    int size()
    {
        return ll.size();
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyQueue que;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            que.push(x);
            cout << "null" << '\n';
        }
        else if (op == "pop")
            cout << que.pop() << '\n';
        else if (op == "front")
            cout << que.front() << '\n';
        else if (op == "back")
            cout << que.back() << '\n';
        else if (op == "empty")
            cout << (que.empty() ? "true" : "false") << '\n';
        else // size
            cout << que.size() << '\n';
    }

    return 0;
}