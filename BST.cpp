#include <iostream>
#include<queue>
using namespace std;

struct Node
{
  int data;
  Node *left = NULL;
  Node *right = NULL;
};


void insert_node(Node *&head, int data)
{
  Node *temp = new Node;
  temp->data = data;
  
  Node* curr = head;
  Node* parent = NULL;
   
  if(head==NULL){head = temp; return;}
 
  while(curr!=NULL)
  { parent = curr;
    
    if(curr->data>data) 
     curr = curr->left;
    else  
     curr = curr->right;
  }
 
  if(parent->data>data)
  { parent->left = temp; }
  else
  { parent->right = temp;}
  
}
//Inorder print
void print(Node *head)
{ if(head!= NULL)
    {
    print(head->left);
    cout<<" "<<head->data;
    print(head->right);
   }
   else
     return;
}
void search(Node* root, int key)
{   //Curr node is the key node
    Node* curr = root;
    while(curr!=NULL && curr->data != key)
    {
        if(key<curr->data){curr= curr->left;}
        else curr = curr->right;
    }
    if(curr==nullptr)
        cout<<"\nkey not found";
    else
       cout<<"\nfound :"<<curr->data;
    return;
}
void deletenode(Node *&head, int key)
{   //Curr node is the key node
    Node* curr = head;
    //Parent keeps track of previous node
    Node* parent = NULL;
    while(curr!=NULL && curr->data != key)
    {   parent = curr;
        if(key<curr->data){curr= curr->left;}
        else curr = curr->right;
    }
    
    if(curr==nullptr)
        {
            cout<<"\nkey not found";
            return;
        }
    //case 1: Delete Node with no child
    if(curr->left == NULL && curr->right == NULL)
    {
        if(curr != head)
        {
            if(parent->left == curr)
                parent->left =NULL;
            else 
                parent->right = NULL;
        }
        else
        {
            head = NULL;
            free(curr);
        }
    }
    //case 1: Delete Node with both child
    else if(curr->left!=NULL&&curr->right!= NULL)
    {
        //Find minimum value in the right subtree
        Node* temp = curr->right;
        while(temp->left != NULL) 
        {temp = temp->left;}
        int temp_val = curr->data;
        deletenode(head,temp_val);
        curr->data = temp_val;
    }
    //case 2: Delete Node with one child
    else
    {   
        Node* child = (curr->left)?curr->left:curr->right;
        if(curr!=head)
        {
            if(curr==parent->left)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
        else
        {
            head = child;
            free(curr);
        }
    }
}

bool isIdentical(Node* x, Node* y)
{
    if(x==NULL && y==NULL)
        return true;
    return (x->data == y->data) && isIdentical(x->left,y->left) &&isIdentical(x->right,y->right);
}

int height(Node* x)
{
    if(x==NULL)
        return 0;
    return 1 + max(height(x->right),height(x->left));
}
void levelordertraversal(Node* x)
{
    if(x==NULL)
        return;
    queue<Node *> q;
    q.push(x);
    while(!(q.empty()))
    {
        Node* temp = q.front();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        cout<<" "<<temp->data;
        q.pop();
    }
}

int main()
{
  Node* x = NULL;
  Node* y = NULL;
  int keys[6] = {2,4,8,6,1,7};
  for(int i:keys)
   {
       insert_node(x,i);
       insert_node(y,i);
   }
  print(x);
  search(x,8);
  print(y);
  bool bal = isIdentical(x,y);
  cout<<"\n"<<bal;
 // deletenode(x,8);
  //bal = isIdentical(x,y);
 // cout<<"\n"<<bal;
  int h = height(x);
  cout<<"\n";
  levelordertraversal(x);
  //print(x);
  //cout<<h;
  
}
