
#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

void _append(node **, int);
void _addatbeg(node **, int);
void _addafter(node *, int, int);
int _count(node *);
void _delete(node **, int);


void _append(node ** head, int val){
    node *new_node = new node();
    new_node->data = val;
    new_node->link = NULL;
    if (*head == NULL){
        *head = new_node;
        return;
    }
    node* q = *head;
    while(q->link != NULL)
    {
        q = q->link;
    }
    q->link = new_node;
}

void _addatbeg(node** head_ref, int new_data){
    node* new_node = new node();
    new_node->data = new_data;
    new_node->link = (*head_ref);
    (*head_ref) = new_node;
}

void _addafter(node * p_head_, int id, int val){
    node* new_node = new node();
    new_node->data = val;
    if (id == 0){
        new_node->link = p_head_;
        p_head_ = new_node;
        return;
    }
    node* pre_node = new node();
    pre_node = p_head_;
    id;
    while(id-- &&  pre_node->link != NULL){
        pre_node = pre_node->link;
    }
    new_node->link = pre_node->link;
    pre_node->link = new_node;

}

int _count(node* head) { 
    int count = 0; 
    node* current = head; 
    while (current != NULL) 
    { 
        count++; 
        current = current->link; 
    } 
    return count; 
}

void _delete(node **head, int val){
    node* current = *head; 
    node* last = NULL;
    while (current != NULL) 
    { 
        if (current->data == val){
            last->link = (current->link);
            current = current->link; 
        }else{
            last = current;
            current = current->link; 
        }
    } 
}


void _display(node *q)
{
    while(q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }
    cout << endl;
}

int main()
{
    node *head;
    head = NULL;

    _append(&head, 1);
    _append(&head, 2);
    _append(&head, 3);
    _append(&head, 4);
    _append(&head, 17);

    _display(head);

    _addatbeg(&head, 999);
    _addatbeg(&head, 888);
    _addatbeg(&head, 777);

    _display(head);

    _addafter(head, 7, 0);
    _addafter(head, 2, 1);
    _addafter(head, 1, 99);

    _display(head);

    cout << "No. of element in the Linked List = " << _count(head) << endl;

    _delete(&head, 888);
    _delete(&head, 1);
    _delete(&head, 10);

    _display(head);

    cout << "No. of element in the Linked List = " << _count(head) << endl;

    return 0;
}