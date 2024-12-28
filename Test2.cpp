#include<iostream>
using namespace std;


struct Node{
    int data;
    Node* next;

};
class LinkedList{
    Node* head;
    public:


LinkedList(): head(NULL){}
void InsertAtBeginning(int value){
    Node* newNode =new Node();
    newNode->data=value;
    newNode->next=head;
    head=newNode;

}
void insertAtEnd(int value){
    Node* newNode= new Node();
    newNode->data=value;
    newNode->next=NULL;
    if(!head){
        head=newNode;
        return;

    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;

    }
    temp->next=newNode;
}
void insertAtposition(int value, int position){
    if(position<1){
        cout<<"position should be >1"<<endl;
        return;
    }
    if(position==1){
        InsertAtBeginning(value);
        return;

    }
    Node* newNode = new Node();
    newNode->data=value;


    Node* temp=head;
    for(int i=0;i<position-1 && temp;++i){
        temp=temp->next;

    }
    if(!temp){
        cout<<"Position out of range"<<endl;
        delete newNode;
        return;

    }
    newNode->next=temp->next;
    temp->next=newNode;

}
void deleteFromBeginning(){
    if(!head){
        cout<<"List is empty"<<endl;
        return;

    }
    Node* temp = head; 
        head = head->next; 
        delete temp;      
    
}
void deleteFromEnd(){
    if(!head){
        cout<<"List is Empty"<<endl;
        return;

    }
    Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        
        //  Delete the last node
        delete temp->next; 
        // Set the second-to-last node's next to NULL
        temp->next = NULL; 
    }
void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        Node* nodeToDelete=temp->next;
        temp->next=temp->next->next;
        delete nodeToDelete;
}
        void display(){
            if(!head){
                cout<<"List is Empty"<<endl;
                return;

            }
            Node* temp=head;
            while(temp){
                cout<<temp->data<<"->";
                temp=temp->next;

            }
            cout<<"NULL"<<endl;
        }
        
};
int main(){
    LinkedList list1;
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.InsertAtBeginning(5);
    list1.insertAtposition(30,5);
    cout<<"Linked list after insertion"<<endl;
    list1.display();
    list1.deleteFromBeginning();
    cout<<"Linked list after deleting from beginning: ";
    list1.display();
    list1.deleteFromEnd();
     cout << "Linked list after deleting from end: ";
    list1.display();
    list1.deleteFromPosition(2);
    cout << "Linked list after deleting from position 2: ";
    list1.display();

    return 0;

}