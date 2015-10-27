#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
int data;
node *left;
node *right;
};
node* createnode(int data)
{
node* t=new node;
t->data=data;
t->left=0;
t->right=0;
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
node* getParent(node *p,node *m)
{
if(m==p)
{
return 0;
}
if(p->data > m->data)
{
if(p->left!=m)
{
return getParent(p->left,m);
}
else
return p;
}
else
{
if(p->right!=m)
{
return getParent(p->right,m);
}
else
return p;
}
}
node * inordersucc(node *t,node *root)
{
if(t->right==0)
{
node *p=getParent(root,t);
while(p!=root&&p->data<t->data)
{
node *x=getParent(root,p);
p=x;
}
if(p->data < t->data)
return 0;
return p;
}
else
{
node *p=t->right;
while(p->left!=0)
{
node *x=p->left;
p=x;
}
return p;
}
return 0;
}



int main()
{
node* root=0;
int arr[]={10,6,12,4,7,11,13};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
root=insert(root,arr[i]);
//preorder(root);
cout<<inordersucc(root->left,root)->data<<endl;

return 0;
}



