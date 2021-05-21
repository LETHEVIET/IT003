
#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

node *_get_tail(node *q)
{
    while (q != NULL && q->link != NULL)
        q = q->link;
    return q;
}

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
    while(q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }
    cout << endl;
}


void FrontBackSplit(node* source, node** frontRef, node** backRef)
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

node * partition(node* head, node* end, node** newHead, node** newEnd){
    node* pivot = end;
    node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot){
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->link;
        }else{
            if (prev)
                prev->link = cur->link;
            node* tmp = cur->link;
            cur->link = NULL;
            tail->link = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    (*newEnd) = tail;
 
    return pivot;
}

node* quickSortRecur(node* head, node* end){
    if (head == NULL ){
        return head;
    }
    if (head == end){
        return head;
    }

    node *newHead = NULL, *newEnd = NULL;

    node* pivot = partition(head, end, &newHead, &newEnd);
 
    if (newHead != pivot) {
        node* tmp = newHead;
        while (tmp->link != pivot)
            tmp = tmp->link;
        tmp->link = NULL;
 
        newHead = quickSortRecur(newHead, tmp);
 
        tmp = _get_tail(newHead);
        tmp->link = pivot;
    }
 
    pivot->link = quickSortRecur(pivot->link, newEnd);
 
    return newHead;
}

node* _quick_sort(node* head, node* end){
    node* tmp = quickSortRecur(head, end);
    return tmp;
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

    tail = _get_tail(head);

    //_display(head);

    head = _quick_sort(head, tail);

    _display(head);

    return 0;
}
