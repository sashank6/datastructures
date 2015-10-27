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
bool mirrorcheck(node *p, node *t)
{
if(p!=0&&t!=0)
{
return mirrorcheck(p->left,t->right)&mirrorcheck(p->right,t->left);
}
if(p==0&&t==0)
return true;
return false;
}
bool isFoldable(node* root)
{
if(root==0)
return true;
return mirrorcheck(root->left,root->right);
}
int main()
{
node* root=0;
int arr[]={50,10,9,8,100,71,70,69};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
root=insert(root,arr[i]);
preorder(root);
cout<<isFoldable(root)<<endl;
return 0;
}



