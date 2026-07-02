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

    LinkedList()
    {
        head = nullptr;
    }

    void build(int n)
    {
        Node* tail = nullptr;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            Node* node = new Node(x);

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



Node* partition(Node* head, int x)
{
     Node* p1H = new Node(-1) , *p2H = new Node(-1) ,*p1,*p2,*current=head;
        p1=p1H,p2=p2H;

        while(current!=NULL){
            if(current->val<x){
                p1->next=current;
                p1=p1->next;
            }else{
                p2->next=current;
                p2=p2->next;
            }
            current=current->next;
        }
        p1->next=p2H->next;
        p2->next=NULL;
        return p1H->next;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int x;
    cin >> x;

    ll.head = partition(ll.head, x);

    Node* cur = ll.head;

    bool first = true;

    while(cur)
    {
        if(!first)
        {
            cout << ' ';
        }

        first = false;

        cout << cur->val;

        cur = cur->next;
    }

    cout << '\n';

    return 0;
}