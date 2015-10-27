#include<iostream>
#include<algorithm>
using namespace std;
struct tnode
{
int data;
tnode *left;
tnode *right;
}*root;
struct node
{
tnode *data;
node *next;
}*head,*lastnode;
void init()
{
root=0;
head=0;
}
bool checkperfecttree(tnode *p,int &level)
{
if(p==0)
{
level--;
return true;
}
int level_l=level,level_r=level;
bool k=checkperfecttree(p->left,++level_l);
bool k1=checkperfecttree(p->right,++level_r);
level=max(level_l,level_r);
return k&&k1&&!(level_l^level_r);
}
node* createbufnode(tnode *data)
{
node* newnode;
newnode=new node;
newnode->data=data;
newnode->next=0;
return newnode;
}
tnode* createtreenode(int data)
{
tnode* newnode;
newnode=new tnode;
newnode->data=data;
newnode->left=0;
newnode->right=0;
return newnode;
}
void cachetnode(tnode *data)
{
if(head==0)
{
head=createbufnode(data);
lastnode=head;
return;
}
lastnode->next=createbufnode(data);
lastnode=lastnode->next;
}
void insert(int data)
{
if(root==0)
{
root=createtreenode(data);
cachetnode(root);
return;
}
if(head->data->left==0)
{
head->data->left=createtreenode(data);
cachetnode(head->data->left);
return;
}
if(head->data->right==0)
{
head->data->right=createtreenode(data);
cachetnode(head->data->right);
head=head->next;
return;
}
}
void preorder(tnode *p)
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
init();
for(int i=1;i<9;i++)
insert(i);
preorder(root);
int level=0;
cout<<checkperfecttree(root,level);
return 0;
}

