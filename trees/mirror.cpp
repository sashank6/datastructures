#include<iostream>
#include<string>
using namespace std;
struct node
{
int data;
node *left;
node *right;
};
node *newnode(int data)
{
node *t;
t=new node;
t->data=data;
t->left=0;
t->right=0;
return t;
}
node *createbst(node *p,int data)
{
if(p==0)
return newnode(data);
if(data <p->data)
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
void printroottonode(node *p, string str)
{
if(p!=0)
{
str+=to_string(p->data);

printroottonode(p->left,str);
printroottonode(p->right,str);
}
else
cout<<str<<endl;
}


node* mirror(node *p)
{
node *t=0;
if(p!=0)
{
t=newnode(p->data);
t->left=mirror(p->right);
t->right=mirror(p->left);
}
return t;
}
int main()
{
int arr[]={5,3,7,4,2,6,8};
int len=sizeof(arr)/sizeof(*arr);
node *root=0;
for(int i=0;i<len;i++)
root=createbst(root,arr[i]);
preorder(root);
printroottonode(root,"");

return 0;
}

