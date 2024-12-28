#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * prev;
    Node * Next;

    Node(int d){
        data=d;
        prev=Next=NULL;

    }
};
Node * delPos(Node * head, int Pos){
    if(!head)
        return head;

    Node * curr=head;
    for(int i=1;curr && i<Pos;++i){
        curr=curr->Next;

    }
    if(!curr)
        return head;
    if(curr->prev)
    curr->prev->Next=curr->Next;
    if(head==curr)

    head=curr->Next;
    delete curr;
    return head;

}
void printList(Node * head){
    Node * curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->Next;
    }
    cout<<endl;

}
int main(){
    struct Node * head =new Node(1);
    head->Next=new Node(2);
    head->Next->prev=head;
    head->Next->Next=new Node(3);
    head->Next->Next->prev=head->Next;
    cout<<"Original Linked List"<<endl;
    printList(head);

    cout<<"After Deletion at the position"<<endl;
    head=delPos(head,2);
    printList(head);
    return 0;
}