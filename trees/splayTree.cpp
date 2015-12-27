#include<iostream>
using namespace std;
struct node
{
int data;
node *left;
node *right;
}*root;
void init()
{
root=0;
}
node *createnode(int data)
{
node *t;
t=new node;
t->data=data;
t->left=0;
t->right=0;
return t;
}
node* createbst(node *p,int data)
{
if(p==0)
return createnode(data);
if(data < p->data)
{
p->left=createbst(p->left,data);
}
else
{
p->right=createbst(p->right,data);
}
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
node *rightrotate(node *mst)
{
node *x=mst->left;
node *y=x->right;
x->right=mst;
mst->left=y;
return x;
}
node *leftrotate(node *mst)
{
node *x=mst->right;
node *y=x->left;
x->left=mst;
mst->right=y;
return x;
}
node *doubleright(node *mst)
{
mst->left=leftrotate(mst->left);
return rightrotate(mst);
}
node *doubleleft(node *mst)
{
mst->right=rightrotate(mst->right);
return leftrotate(mst);
}
node* getParent(node *p,node *m)
{
if(m==root)
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
node* search(int data)
{
node *p;
p=root;
while(p->data!=data)
{
if(data >= p->data)
p=p->right;
else
p=p->left;
}
return p;
}
node *zigzagright(node *mst)
{
mst->left=rightrotate(mst->left);
node *x=mst->left;
node *t=x->right;
node *t1=t->right;
t->right=mst;
mst->left=t1;
return x;
}
void splay(node *t)
{
node *x=t;
while(t!=root)
{
node *parent=getParent(root,x);
if(parent==root)
{
root=rightrotate(root);
return;
}
node *grandParent=getParent(root,parent);
if(grandParent==root)
{
root=zigzagright(root);
return;
}
node *ggrand=getParent(root,grandParent);
ggrand->left=zigzagright(grandParent);
}
}

int main()
{
init();
int arr[]={7,6,5,4,3,2,1};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
{
root=createbst(root,arr[i]);
}
node *t=search(1);
splay(t);
preorder(root);
return 0;
}
