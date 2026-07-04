#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node(int value){
        this->value=value;
        this->next=NULL;
    }
};


class LinkedList {
private:
    Node* head;
    int _size;
public:
    LinkedList(){
        this->head=NULL;
        this->_size=0;
    }

    void addNode(int value){
        Node* newNode = new Node(value);
        newNode->next=head;
        head=newNode;
        _size++;
    }

    int deleteNode(){
        if(empty())return -1;
        Node* temp = head;
        int poppedValue=temp->value;
        head=head->next;
        delete temp;
        _size--;
        return poppedValue;
    }

    int topNode(){
        if(empty())return -1;
        return head->value;
    }

    bool empty(){
        return _size==0;
    }

    int size(){
        return _size;
    }

};

class MyStack {
private:
    LinkedList list;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        list.addNode(x);
    }
    
    int pop() {
        return list.deleteNode();
    }
    
    int top() {
        return list.topNode();
    }
    
    bool empty() {
        return list.empty();
    }

    int size()
    {
        return list.size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyStack st;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            st.push(x);
            cout << "null" << '\n';
        }
        else if (op == "pop")
        {
            cout << st.pop() << '\n';
        }
        else if (op == "top")
        {
            cout << st.top() << '\n';
        }
        else if (op == "empty")
        {
            cout << (st.empty() ? "true" : "false") << '\n';
        }
        else // size
        {
            cout << st.size() << '\n';
        }
    }

    return 0;
}