
#include <iostream>

using namespace std;

struct node
{
    int8_t data;
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

void _display(node *q)
{
    int current_data = q->data;
    int current_data_freq = 0;
    while(q != NULL)
    {
        if(q->data == current_data)
            current_data_freq++;
        else
        {
            cout << current_data << " : " << current_data_freq << endl;
            current_data = q->data;
            current_data_freq = 1;
        }

        q = q->link;
    }

    cout << current_data << " : " << current_data_freq << endl;
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

node* _sort(node* head){
    _merge_sort(&head);

    return head;
}

int main()
{
    node *head;

    head = NULL;

    int n, temp_val;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp_val;
        _addatbeg(&head, temp_val);
    }

    head = _sort(head);

    _display(head);

    return 0;
}
