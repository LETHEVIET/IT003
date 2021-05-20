#include <iostream>
#include <conio.h>
using namespace std;
class PTLinkedList
{
    struct Node    
    {
        int data_;
        Node* p_next_;
    };
 
public:
    PTLinkedList() { p_head_ = NULL; }
    ~PTLinkedList()
    {
        Node* head = p_head_;
        while (head)
        {
            Node* temp = head;
            head = head->p_next_;
            delete temp;
            temp = NULL;
        }

        p_tail_ = p_head_;
        size = 1;
    }
 
    void push_front(int val) 
    {
        Node* new_node = new Node();
        new_node->data_ = val;
        new_node->p_next_ = p_head_;
        p_head_ = new_node;
        size++;
    }

    void push_back(int val){
        Node* new_node = new Node();
        new_node->data_ = val;
        new_node->p_next_ = NULL;
        p_tail_->p_next_ = new_node;
        p_tail_ = new_node;
        size++;
    }

    void insert(int val, int id){
        Node* new_node = new Node();
        new_node->data_ = val;
        if (id == size-1){
            push_back(val);
            return;
        }
        if (id == 0){
            push_front(val);
            return;
        }
        Node* pre_node = new Node();
        pre_node = p_head_;
        id--;
        while(--id){
            pre_node = pre_node->p_next_;
        }
        new_node->p_next_ = pre_node->p_next_;
        pre_node->p_next_ = new_node;
        size++;
    }
    
    void Show() 
    {
        Node* temp = p_head_;
        while (temp != NULL)
        {
            int value = temp->data_;
            std::cout << "  " << value;
            temp = temp->p_next_;
        }
    }
private:
    Node* p_head_;  
    Node* p_tail_;
    int size = 0;
};
 
int main()
{
    PTLinkedList data_list;
    data_list.push_front(5);
    data_list.push_front(6);
    data_list.push_front(7);
    data_list.push_front(8);
    data_list.push_front(9);
    
    cout<< "danh sach ban dau: " <<endl;
    data_list.Show();
    cout << endl;
 
    cout<< "them phan tu 2 vao dau danh sach: " <<endl;
    data_list.push_front(2);
    data_list.Show();
    cout << endl;

    cout<< "them phan tu 10 vao cuoi danh sach: " <<endl;
    data_list.push_front(10);
    data_list.Show();
    cout << endl;

    cout<< "chen phan tu 9 vao vi tri thu 4 cua danh sach: "<<endl;
    data_list.insert(9,4);
    data_list.Show();
    cout << endl;

    return 0;
}
 