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
node *lca(node *p,int data1,int data2)
{
if(p!=0)
{
int mie=min(data1,data2);
int mae=(mie==data1)?data2:data1;
if(mae<p->data)
{
return lca(p->left,data1,data2);
}
if(mae >= p->data)
{
if(mie > p->data)
return lca(p->right,data1,data2);
return p;
}
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
node *t1=lca(root,6,11);
node *t2=lca(root,4,7);
node *t3=lca(root,12,13);
cout<<t1->data<<endl;
cout<<t2->data<<endl;
cout<<t3->data<<endl;
return 0;
}



