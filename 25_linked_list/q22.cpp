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
    Sort the linked list in ascending order and return the new head.
*/

Node* mergeTwoLists(Node* list1, Node* list2) {
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

Node* sortList(Node* head)
{
        if(head==NULL || head->next==NULL)return head;
        //findmid
        Node* slow=head,*fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* l1,*l2;
        l2=slow->next;
        slow->next=NULL;
        l1 =head;
        //sort further
        Node* sort1Result = sortList(l1);
        Node* sort2Result = sortList(l2);
        //now merge
        Node* mergeResult = mergeTwoLists(sort1Result,sort2Result);
        return mergeResult;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    ll.head = sortList(ll.head);

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