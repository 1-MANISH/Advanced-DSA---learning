#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v)
    {
        val = v;
        next = nullptr;
    }
};

class LinkedList {
public:

    Node* head;
    Node* tail;
    vector<Node*> nodes;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void build(int n)
    {
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            Node* node = new Node(x);

            nodes.push_back(node);

            if(!head)
            {
                head = tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }
};

/*
    Implement only the function below.
    Return the number of nodes in the loop, or 0 if there is no loop.
*/

int lengthOfLoop(Node* head)
{
    if(head==NULL || head->next==NULL)return 0;
    if(head==head->next)return 1;

    Node* slow=head;
    Node* fast=head->next;
  
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            //lest calculate number of cycle node
            int loopNodes = 0;
            fast=fast->next;
            while(slow!=fast){
                loopNodes++;
                fast=fast->next;
            }
            return loopNodes+1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int pos;
    cin >> pos;

    if(pos != -1)
        ll.tail->next = ll.nodes[pos];

    cout << lengthOfLoop(ll.head) << '\n';

    return 0;
}