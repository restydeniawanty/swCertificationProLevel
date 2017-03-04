#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

//functions
// Print elements of a linked list on console
void Print(Node *head){
    Node* curr = head; //current position
    while(curr!=NULL){
        cout << curr->data << endl;
        curr = curr->next;
    }
}

// Insert Node at the end of a linked list
Node* InsertAtTheEnd(Node *head, int data){
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    if(head == NULL) head = node;
    else{
        Node* curr = head;
        while(curr->next!=NULL) curr = curr->next;
        curr->next = node;
    }
    return head;
}

Node* InsertAtTheBeginning(Node* head,int data){
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    if(head == NULL) head = node;
    else{
        node->next = head;
        head = node;
    }
    return head;
}

Node* InsertNth(Node *head, int data, int position){
    Node* node = new Node;
    node->data = data;
    node->next = NULL;

    if(head == NULL) head = node;
    else{
        Node* curr = new Node();
        curr = head;
        if(position==0){
            node->next=head;
            head = node;
        }else {
            for(int i=0;i<(position-1);i++) curr = curr->next;
                node->next = curr->next;
                curr->next = node;
        }
    }
    return head;
}

// Delete a node in a specific position
Node* Delete(Node *head, int position)
{
    if(position==0){
        if(head->next!=NULL) head = head->next;
    } else {
        Node* curr = head;
        for(int i=0;i<(position-1);i++) curr = curr->next;
        curr->next = curr->next->next;
    }
    Node* curr = head;
  return head;
}

// Print elements of a linked list in reverse order as standard output
void ReversePrint(Node *head)
{
  if(head!=NULL){
      ReversePrint(head->next);
      cout << head->data << endl;
  }
}

//Reverse a linked list and return pointer to the head
Node* Reverse(Node *head)
{
  Node* currentHead;
  if(head!=NULL){
      if(head->next!=NULL){
          currentHead = Reverse(head->next);
          head->next->next = head;
          head->next = NULL;
      } else currentHead = head;

  } else {
      currentHead = head;
  }
  return currentHead;
}

// Compare two linked lists A and B
int CompareLists(Node *headA, Node* headB)
{
  if(headA==NULL){
      if(headB==NULL) return 1;
      else return 0;
  } else{
    Node* currA = headA;
    Node* currB = headB;
    int isIdentic = 1;
    while(currA!=NULL && currB!=NULL){
        if(currA->data != currB->data){
            isIdentic = 0;
            break;
        } else {
            currA = currA->next;
            currB = currB->next;
        }
    }
    if(isIdentic == 1){
        if(currA!=NULL && currB==NULL) isIdentic = 0;
        else if (currA==NULL && currB!=NULL) isIdentic = 0;
    }

    return isIdentic;
  }
}

// Merge two sorted lists A and B as one linked list


int main(){
    return 0;
}
