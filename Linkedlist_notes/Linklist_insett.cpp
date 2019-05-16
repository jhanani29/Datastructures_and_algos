/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
void printList(Node *node)
{
    while(node != NULL)
    {
        printf("%d", node->data);
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
int main()
{   struct Node* head = NULL;
    push(&head, 6);
    //printList(head);
     append(&head, 4); 
     insert(head->next, 8); 
    printList(head);
    Node* a = reverselist(&head);
    printList(head);
    return 0;
}
