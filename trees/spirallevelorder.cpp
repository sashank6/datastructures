#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
struct node
{
int data;
node *left;
node *right;
};
stack<node*> q;
stack<node*> s;
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
void spirallevelorder(node *root)
{
q.push(root);
while((!q.empty()) ||(!s.empty()))
{
cout<<endl;
while(!q.empty())
{
node *t=q.top();
cout<<t->data<<" ";
if(t->left!=0)
s.push(t->left);
if(t->right!=0)
s.push(t->right);
q.pop();
}
cout<<endl;
while(!s.empty())
{
node *t=s.top();
cout<<t->data<<" ";
if(t->right!=0)
q.push(t->right);
if(t->left!=0)
q.push(t->left);
s.pop();
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
preorder(root);
spirallevelorder(root);
return 0;
}



