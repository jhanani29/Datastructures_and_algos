#include <iostream>
struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node** head_ref, int new_data)
{   

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    
}
void insert(struct Node* prev_node, int new_data)
{
    if(prev_node == NULL)
    {
        printf("error");
        return;
    }
    struct Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void append(struct Node** head_Ref, int new_data)
{
    struct Node* new_node = new Node();
    Node* last = *head_Ref;
    //Create a new node
    new_node->data = new_data;
    new_node->next = NULL;
    //If the list is empty then make the new node as a head node
    if(head_Ref == NULL)
    {
        *head_Ref = new_node;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}
void Deletenode(Node** head_Ref, int d)
{
    Node* n = *head_Ref;
    if(n->data == d)
    {    *head_Ref = n->next; return;}
    while(n->next != NULL)
    {
        if(n->next->data == d)
        {
            n->next = n->next->next;
            return;
        }
        n = n->next;
    }
    return;
}

void printList(Node *node)
{
    while(node != NULL)
    {
        printf(" %d", node->data);
        node = node->next;
    }
}

Node* reverselist(Node** head)
{
    Node* current = *head;
    Node* prev = NULL, *next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return *head;
}
/* Set is a container which stores unique element in a specific order. The value in the set cannot be
modified once it is stored in the container. The value is always contant. But, it can be inserted or 
removed from the container*/

void RemoveDup(Node** head_Ref)
{
    Node *ptr1,*ptr2,*dup;
    ptr1 = *head_Ref;
    while(ptr1 != NULL && ptr1->next != NULL)
    {
        int d = ptr1->data;
  
        ptr2 = ptr1;
        while(ptr2->next!= NULL)
        {   
            if(d == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int main()
{   struct Node* head = NULL;
    push(&head, 6);

     append(&head, 4); 
     insert(head->next, 8); 
    //printList(head);
    Node* a = reverselist(&head);
   // printList(head);
    //Deletenode(&head,6);
    push(&head, 6);
    push(&head, 6);
    push(&head, 8);
    RemoveDup(&head);
    printList(head);
    return 0;
}
