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
bool isidentical(node *t1, node *t2)
{
if(t1==0&&t2==0)
return true;
if(t1!=0&&t2!=0)
{
if(!(t1->data^t2->data))
{
bool leftcheck=isidentical(t1->left,t2->left);
bool rightcheck=isidentical(t2->right,t2->right);
return leftcheck & rightcheck;
}
else
return false;
}
return false;
}
int main()
{
node* root=0;
node *root1=0;
int arr[]={10,6,12,4,7,11,13};
int arr1[]={10,6,12,8,7,11,13};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
root=insert(root,arr[i]);
//preorder(root);
int len1=sizeof(arr1)/sizeof(*arr1);
for(int i=0;i<len1;i++)
root1=insert(root1,arr1[i]);
cout<<isidentical(root,root1)<<endl;
return 0;
}



