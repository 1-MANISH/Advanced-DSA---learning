#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
    void push_front(int x) -- insert x at the front.
    void push_back(int x)  -- insert x at the back.
    int  pop_front()       -- remove and return the front element; -1 if empty.
    int  pop_back()        -- remove and return the back element; -1 if empty.
    int  front()           -- return the front element; -1 if empty.
    int  back()            -- return the back element; -1 if empty.
    bool empty()           -- return true if the deque is empty, else false.
    int  size()            -- return the number of elements.
    All operations must run in O(1).
*/

class Node{
public:
    int value;
    Node* next ,*prev;

    Node(int value){
        this->value=value;
        this->next=this->prev=NULL;
    }
};


class LinkedList{
public:
    Node* head,*tail;
    int _size;

    LinkedList(){
        this->_size = 0;
    }

    void intsetAtHead(int value){
        if(empty()){
            head=tail=new Node(value);
        }else{
            Node* newNode = new Node(value);
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }
        _size++;
    }

    void insertAtTail(int value){
        if(empty()){
            head=tail=new Node(value);
        }else{
            Node* newNode = new Node(value);
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        _size++;
    }

    int deleteAtHead(){
        if(empty()){
            return -1;
        }else{
            Node* temp=head;
            int value = head->value;
            head=head->next;
            if(head)
                head->prev=NULL;
            
            delete temp;
            _size--;
            return value;
        }
    }
    int deleteAtTail(){
        if(empty()){
            return -1;
        }else{
            Node* temp=tail;
            int value = tail->value;
            tail=tail->prev;
            if(tail)
                tail->next=NULL;
            
            delete temp;
            _size--;
            return value;
        }
    }

    int getHead(){
        return empty()?-1:head->value;
    }
    int getTail(){
        return empty()?-1:tail->value;
    }

    bool empty(){
        return _size==0;
    }
    int size(){
        return _size;
    }
};

class MyDeque {
public:

    LinkedList ll;

    MyDeque()
    {

    }

    void push_front(int x)
    {
        ll.intsetAtHead(x);
    }

    void push_back(int x)
    {
        ll.insertAtTail(x);
    }

    int pop_front()
    {
        return ll.deleteAtHead();
    }

    int pop_back()
    {
        return ll.deleteAtTail();
    }

    int front()
    {
        return ll.getHead();
    }

    int back()
    {
        return ll.getTail();
    }

    bool empty()
    {
        return ll.empty();
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

    MyDeque dq;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push_front")
        {
            int x;
            cin >> x;
            dq.push_front(x);
            cout << "null" << '\n';
        }
        else if (op == "push_back")
        {
            int x;
            cin >> x;
            dq.push_back(x);
            cout << "null" << '\n';
        }
        else if (op == "pop_front")
            cout << dq.pop_front() << '\n';
        else if (op == "pop_back")
            cout << dq.pop_back() << '\n';
        else if (op == "front")
            cout << dq.front() << '\n';
        else if (op == "back")
            cout << dq.back() << '\n';
        else if (op == "empty")
            cout << (dq.empty() ? "true" : "false") << '\n';
        else // size
            cout << dq.size() << '\n';
    }

    return 0;
}