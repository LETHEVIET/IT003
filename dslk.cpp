
#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void append(Node** head_ref, int new_data) 
{ 
   
    Node* new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data; 
    new_node->next = NULL; 
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return; 
} 
int length(Node* head) { 
    int count = 0; 
    Node* current = head; 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
}
void insertAtMiddle(Node** head_ref, int length, int new_data){
    int index= length/2;
    Node* new_node = new Node();
    new_node->data = new_data; 
    Node* last =*head_ref;
    for(int i =2; i<=index-1;i++){
        last = last->next;
        if(last == NULL){
            break;
        }
        if(last != NULL)
        {
            new_node->next = last->next; 
            last->next = new_node;
        }
    }
}
void display(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}
int main() {
    //Creat a linked list with 5 element:
    int a =1,b=2,c=3,d=4,e=5;
    Node* second = NULL;
    Node* third  = NULL;
    Node* forth  = NULL;
    Node* fiveth = NULL;
    
    head = new Node();
    second = new Node();
    third  = new Node();
    forth  = new Node();
    fiveth = new Node();

    head->data = a;
    head->next = second;
    
    second->data = b;
    second->next = third;
    
    third->data = c;
    third->next = forth;
    
    forth->data = d;
    forth->next = fiveth;
    
    fiveth->data = e;
    fiveth->next = NULL;
    
    cout<<"The linked list is: ";
    display(head);
    cout<<endl;
    
    //Insert at Head:
    push(&head, 1111);
    cout<<"The linked list is: ";
    display(head);
    cout<<endl;
    
    //Insert at Tail:
    append(&head, 2222);
    cout<<"The linked list is: ";
    display(head);
    cout<<endl;

    //Insert at middle
    insertAtMiddle(&head,length(head),8888);
    cout<<"The linked list is: ";
    display(head);
    cout<<endl;
   return 0;
}
