#include<bits/stdc++.h>
using namespace std;

class MyLinkedList {
public:
        int val;
        MyLinkedList* next;
        MyLinkedList* tail;
        int size;
        MyLinkedList(int value=-1) {
                this->val=value;
                this->next=NULL;
                this->tail=NULL;
                this->size=0;
        }
        
        int get(int index) {
                // if(index>=size)return -1;
                int count=0;
                MyLinkedList* head = this;
                while(head!=NULL){
                        if(index==count)return head->val;
                        head=head->next;
                        count++;
                }
                return -1;
        }
        
        void addAtHead(int val) {
                MyLinkedList* current = this;
                this->size+=1;
                if(current->val==-1){
                        // first node
                        current->val=val;
                        tail=current;
                        return;
                }
                MyLinkedList* newNode = new MyLinkedList(current->val);
                current->val=val;
                        if(current->next==NULL){// only single node
                        current->next=newNode;
                        tail=newNode;
                }else{// rest cases
                        MyLinkedList* temp = current->next;
                        current->next = newNode;
                        newNode->next = temp; 
                }
         }
    
        void addAtTail(int val) {
                MyLinkedList* current = this;
                this->size+=1;
                        if(current->val==-1){//first node
                        current->val=val;
                        tail=current;
                        return;
                }
                MyLinkedList* newNode = new MyLinkedList(val);
                tail->next = newNode;
                tail=newNode;

        }
        
         void addAtIndex(int index, int val) {
                if(index>this->size)return;
                MyLinkedList* current = this;
                if(index==0){
                        addAtHead(val);
                        return;
                }else if(index==this->size){
                        addAtTail(val);
                        return;
                }else{
                        this->size+=1;
                        MyLinkedList* prev=NULL;
                        while(index>0 && current!=NULL){
                                index--;
                                prev=current;
                                current=current->next;
                        }
                        MyLinkedList* newNode = new MyLinkedList(val);
                        prev->next=newNode;
                        newNode->next=current;
                        return;
                }

    }
        
         void deleteAtIndex(int index) {
                if(index>=this->size)return;// invalid index
                if(this->val==-1)return;// node node
                this->size-=1;
                if(this->next==NULL){
                        //deleting single node
                        this->val=-1;
                        tail=NULL;
                        return;
                }
                MyLinkedList* current = this;
                if(index==0){// two node over there
                        current->val=current->next->val;
                        current->next=current->next->next ?current->next->next : NULL;
                        tail= current->next ? tail : current;
                        return;
                }
                MyLinkedList* prev = NULL;
                int count = 0 ;
                while(current!=NULL && count< index){
                        prev=current;
                        current=current->next;
                        count++;
                }
                
                prev->next=current ? current->next : NULL;
                if(index==this->size || index==this->size-1){
                        if(index==this->size-1)tail=prev->next;
                        else tail=prev;
                        current->val=-1;
                }
                if(current)current->next=NULL;

    }

        void display(){
                MyLinkedList* current = this;
                while(current != NULL){
                        cout<<current->val<<" ----> ";
                        current=current->next;
                }
                cout<< "NULL"<<endl;
        }
};

// ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
// [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]

int main(){

        MyLinkedList* obj = new MyLinkedList();

        obj->addAtHead(7);
        obj->addAtHead(2);
        obj->addAtHead(1);
        obj->addAtIndex(3,0);
        obj->display();
        obj->deleteAtIndex(3);
        obj->display();
        obj->addAtHead(6);
        obj->addAtTail(4);
        cout <<obj->get(4) << endl;
        obj->display();
        
        // obj->addAtHead(4);
        // obj->addAtIndex(5,0);
        // obj->addAtHead(6);



        
        


        return 0;
}