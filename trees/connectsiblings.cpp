#include<iostream>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;
struct node
{
int data;
node *left;
node *right;
node *nextRight;
};
node* createnode(int data)
{
node* t=new node;
t->data=data;
t->left=0;
t->right=0;
t->nextRight=t;
return t;
}
node* insert(node* p,int data)
{
if(p==0)
return createnode(data);
if(data >=p->data)
p->right=insert(p->right,data);
if(data < p->data)
p->left=insert(p->left,data);
return p;
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
void func(node *root)
{
list<node*> l;
l.push_back(root);
while(!(l.empty()))
{
list<node *>::iterator it;
for(it=l.begin();next(it)!=l.end();++it)
{
(*it)->nextRight=*(next(it));
}
(*it)->nextRight=0;
while(1)
{
node *t=l.front();
if(t->left!=0)
l.push_back(t->left);
if(t->right!=0)
l.push_back(t->right);
l.pop_front();
if(l.empty())
break;
else
if(l.front()->nextRight==l.front())
break;
}
}
}
void ltraversal(node *p)
{
if(p!=0)
{
node* t=p;
while(t!=0)
{
cout<<t->data<<" ";
t=t->nextRight;
}
ltraversal(p->left);
}
}
int main()
{
node* root=0;
int arr[]={10,6,12,4,7,11,13};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
root=insert(root,arr[i]);
//preorder(root);
func(root);
ltraversal(root);
cout<<endl;
return 0;
}



