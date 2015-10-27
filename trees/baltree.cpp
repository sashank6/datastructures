#include<iostream>
using namespace std;
struct node
{
int data;
bool bal;
node *left;
node *right;
} *root;
void init()
{
root=0;
}
node * createnode(int data)
{
node* newnode;
newnode=new node;
newnode->bal=true;
newnode->left=0;
newnode->right=0;
newnode->data=data;
return newnode;
}
void insert(node* p,int data)
{
if(root==0)
{
root=createnode(data);
}
else
{
if(p->left==0||p->right==0)
{
if(p->bal)
{
p->bal=false;
p->left=createnode(data);
}
else
{
p->bal=true;
p->right=createnode(data);
}
}
else
{
if(p->bal)
{
p->bal=false;
insert(p->left,data);
}
else
{
p->bal=true;
insert(p->right,data);
}
}
}
}
void preorder(node *p)
{
if(p!=0)
{
cout<<p->data<<endl;
preorder(p->left);
preorder(p->right);
}
}


int main()
{

for(int i=0;i<11;i++)
insert(root,i);
preorder(root);
return 0;
}


