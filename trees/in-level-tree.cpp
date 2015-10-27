#include<iostream>
using namespace std;
struct node
{
int data;
node *left,*right;
bool valid;
}*root;
void init()
{
root=0;
}
node * createnode(int data,bool valid)
{
node* newnode;
newnode=new node;
newnode->left=0;
newnode->right=0;
newnode->data=data;
newnode->valid=valid;
return newnode;
}
bool insert(node *p,int data,unsigned int level)
{
if(root==0)
{
root=createnode(0,false);
p=root;
}
if(p->left==0)
p->left=createnode(0,false);
if(p->right==0)
p->right=createnode(0,false);
if(level==0&&p->valid==false)
{
p->data=data;
p->valid=true;
return true;
}
if(level==1)
{
if(!p->left->valid)
{
p->left->data=data;
p->left->valid=true;
return true;
}
if(!p->right->valid)
{
p->right->data=data;
p->right->valid=true;
return true;
}
return false;
}
bool l,r=false;
l=insert(p->left,data,level-1);
if(l)
return true;
r=insert(p->right,data,level-1);
return r;
//return false;
}
void preorder(node *p)
{
if(p!=0)
{
if(p->valid)
cout<<p->data<<endl;
preorder(p->left);
preorder(p->right);
}
}
int main()
{
init();
insert(root,10,5);
insert(root,5,0);
insert(root,6,1);
insert(root,7,1);
insert(root,2,2);
insert(root,3,2);
insert(root,4,2);
insert(root,11,2);
//cout<<root->data<<endl;
preorder(root);
return 0;
}
