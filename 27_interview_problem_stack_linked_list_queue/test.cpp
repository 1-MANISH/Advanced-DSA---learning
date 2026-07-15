#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below (a queue backed by two stacks).
    void push(int x) -- insert x at the back.
    int  pop()       -- remove and return the front element; -1 if empty.
    int  front()     -- return the front element; -1 if empty.
    int  back()      -- return the last element; -1 if empty.
    bool empty()     -- return true if the queue is empty, else false.
    int  size()      -- return the number of elements.
    All operations must run in O(1).
*/

class MyQueue {
    void helper(){
        while(!inStack.empty()){
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
    void helper2(){
        while(!outStack.empty()){
            inStack.push(outStack.top());
            outStack.pop();
        }
    }
public:
    stack<int>inStack,outStack;

    MyQueue()
    {

    }

    void push(int x)
    {
        inStack.push(x);
    }

    int pop()
    {
        if(outStack.empty())
            helper();
        if( outStack.empty())
            return -1;
        int ele = outStack.top();
        outStack.pop();
        return ele;

    }

    int front()
    {
        helper();
        return outStack.empty()?-1: outStack.top();
    }

    int back()
    {
        helper2();
        return inStack.empty()?-1: inStack.top();
    }

    bool empty()
    {
        return inStack.empty() && outStack.empty();
    }

    int size()
    {
        return inStack.size() + outStack.size();
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