#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

void _addatbeg(node **q, int num)
{
    node *temp;
    temp = new node;
    temp->data = num;
    temp->link = *q;
    *q = temp;
}


void FrontBackSplit(node* source,
                    node** frontRef, node** backRef)
{
    node* fast;
    node* slow;
    slow = source;
    fast = source->link;
 
    while (fast != NULL) {
        fast = fast->link;
        if (fast != NULL) {
            slow = slow->link;
            fast = fast->link;
        }
    }
 
    *frontRef = source;
    *backRef = slow->link;
    slow->link = NULL;
}

node* SortedMerge(node* a, node* b)
{
    node* result = NULL;
 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    if (a->data <= b->data) {
        result = a;
        result->link = SortedMerge(a->link, b);
    }
    else {
        result = b;
        result->link = SortedMerge(a, b->link);
    }
    return (result);
}

void _merge_sort(node** headRef)
{
    node* head = *headRef;
    node* a;
    node* b;
 
    if ((head == NULL) || (head->link == NULL)) {
        return;
    }
 
    FrontBackSplit(head, &a, &b);
 
    _merge_sort(&a);
    _merge_sort(&b);
 
    *headRef = SortedMerge(a, b);
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
    node *head, *tail;

    head = NULL;

    int n, temp_val;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp_val;
        _addatbeg(&head, temp_val);
    }

    //_display(head);

    _merge_sort(&head);

    _display(head);

    return 0;
}
