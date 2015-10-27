#include<iostream>
#include<algorithm>
#include<stack>
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
stack<node*> childStack;
stack<node*> rootStack;
void inorder(node *root)
{
childStack.push(root);
while(!(childStack.empty()&&rootStack.empty()))
{
if(!(childStack.empty()))
{
node *t=childStack.top();
if(t->left==0&&t->right==0)
{
cout<<t->data<<" ";
childStack.pop();
}
else
{
if(t->left!=0)
{
childStack.pop();
childStack.push(t->left);
rootStack.push(t);
}
else
if(t->right!=0)
{
childStack.pop();
childStack.push(t->right);
cout<<t->data<<" ";
}
}
}
else
{
node *t=rootStack.top();
if(t->right!=0)
{
childStack.push(t->right);
rootStack.pop();
cout<<t->data<<" ";
}
}
}
}



int main()
{
node* root=0;
int arr[]={10,6,12,4,7,11,13};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
root=insert(root,arr[i]);
inorder(root);
return 0;
}



