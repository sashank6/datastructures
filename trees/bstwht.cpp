#include<iostream>
#include<algorithm>
#define MAX max(p->lth,p->rth);
using namespace std;
struct node
{
int data;
int lth;
int rth;
node *left;
node *right;
} *root;
void init()
{
root=0;
}
node * createnode(int data)
{
node *t;
t=new node;
t->data=data;
t->lth=0;
t->rth=0;
t->left=0;
t->right=0;
return t;
}
int createbst(node *p,int data)
{
if(data >=p->data)
{
if(p->right==0)
{
int a=MAX;
p->right=createnode(data);
p->rth=1;
int b=MAX;
return abs(a-b);
}
int a=MAX;
int y=createbst(p->right,data);
p->rth+=y;
int b=MAX;
return abs(a-b);
}
if(data <p->data)
{
if(p->left==0)
{
int a=MAX;
p->left=createnode(data);
p->lth=1;
int b=MAX;
return abs(a-b);
}
int a=MAX;
int y=createbst(p->left,data);
p->lth+=y;
int b=MAX;
return abs(a-b);
}
return 0;
}
void insertdata(int data)
{
if(root==0)
{
root=createnode(data);
return;
}
int x=createbst(root,data);
}
void preorder(node *p)
{
if(p!=0)
{
cout<<p->data<<" LEFT: "<<p->lth<<" RIGHT: "<<p->rth<<endl;
preorder(p->left);
preorder(p->right);
}
}

int main()
{
init();
int arr[]={5,10,3,2,0};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
insertdata(arr[i]);
preorder(root);
return 0;
}
