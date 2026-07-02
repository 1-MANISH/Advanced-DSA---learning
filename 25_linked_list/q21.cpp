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

/*
    Implement only the function below.
    Merge two sorted (non-decreasing) lists into one sorted list and return
    the head of the merged list. Either list may be empty (nullptr).
*/

Node* mergeTwoLists(Node* list1, Node* list2)
{
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        Node* p1 =list1->val<=list2->val? list1:list2,*p2,*prev=NULL;
        p2=p1==list1?list2:list1;
        Node* mainHead=p1;
        while(p1!=NULL && p2!=NULL){
            if(p1->val<=p2->val){
                prev=p1;
                p1=p1->next;
            }else {
                prev->next=p2;
                prev=p2;
                p2=p2->next;
                p2=p1;
                p1=prev->next;
            }
        }
        if(p1==NULL)prev->next=p2;
        else if(p2==NULL)prev->next=p1;
        return mainHead;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1;
    cin >> n1;

    LinkedList a;
    a.build(n1);

    int n2;
    cin >> n2;

    LinkedList b;
    b.build(n2);

    Node* head = mergeTwoLists(a.head, b.head);

    Node* cur = head;

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
