#include<iostream>
#include<algorithm>
using namespace std;
unsigned int ct=0;
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
bool checkcomplete(node *p,int &level)
{
if(p==0)
{
level--;
return true;
}
if(p->left==0&&p->right==0)
return true;
if(p->left==0&&p->right!=0)
return false;
int level_l,level_r;
level_l=level;level_r=level;
bool l=checkcomplete(p->left,++level_l);
bool r=checkcomplete(p->right,++level_r);
if(p==root)
{
cout<<level_l<<","<<level_r<<endl;
}
level=max(level_l,level_r);
if(l&&r&&((level_l-level_r)==0||(level_l-level_r)==1))
return true;
return false;
}



bool islevelfull(node *p,int level)
{
if(p==0)
return true;
if(level==1)
{
if(p->left==0||p->right==0)
return true;
return false;
}
bool l=islevelfull(p->left,level-1);
bool r=islevelfull(p->right,level-1);
return l|r;
}
void nodecount(node * p)
{
if(p!=0)
{
ct++;
nodecount(p->left);
nodecount(p->right);
}
}
int extremenode(node *p, node **res,int k)
{
if(p==0)
{
*res=0;
return k-1;
}
node *res_l,*res_r;
int x=extremenode(p->left,&res_l,k+1);
int y=extremenode(p->right,&res_r,k+1);
*res=(max(x,y)==x)?res_l:res_r;
if(*res==0)
*res=p;
return max(x,y);
}
void func(node **p)
{
*p=root->right;
}
node * createnode(int data)
{
node *newnode;
newnode=new node;
newnode->data=data;
newnode->left=0;
newnode->right=0;
return newnode;
}
void childnode(node *p)
{
if(p==0)
{
}
else
if(p->right==0&&p->left==0)
{
cout<<p->data<<endl;
}
else
{
childnode(p->left);
childnode(p->right);
}
}
int depth(node *p,int k)
{
if(p==0)
return k-1;
int x=depth(p->left,k+1);
int y=depth(p->right,k+1);
//if(p==root)
//return max(x,y)-1;
return max(x,y);
}
int depth(node *p)
{
if(p==0)
return 0;
int x=depth(p->left);
int y=depth(p->right);
if(p!=root)
return 1+max(x,y);
return max(x,y);
}
void insert(node *p,int data)
{
if(root==0)
{
root=createnode(data);
}
else
{
if(p->left!=0 && data<p->data)
insert(p->left,data);
else
if(p->right!=0&&data>=p->data)
insert(p->right,data);
else
if(p->left==0&&data<p->data)
p->left=createnode(data);
else
if(p->right==0&&data>=p->data)
p->right=createnode(data);
}
}
void inorder(node * p)
{
if(p!=0)
{

cout<<p->data<<endl;
inorder(p->left);
inorder(p->right);
}
}
int main()
{

for(int i=0;i<7;i++)
insert(root,i);
for(int i=-5;i<1;i++)
insert(root,i);
insert(root,-6);
inorder(root);
cout<<depth(root)<<endl;
cout<<"---childnodes---"<<endl;
childnode(root);
cout<<"---another way for depth----"<<endl;
cout<<depth(root->left,0)<<endl;
cout<<"---extremenode-----"<<endl;
node *ext;
//func(&ext);
extremenode(root,&ext,0);
cout<<ext->data<<endl;
cout<<"---Node Count----"<<endl;
nodecount(root);
cout<<ct<<endl;
cout<<"------islevel full----------"<<endl;
cout<<islevelfull(root,1)<<endl;
cout<<islevelfull(root,2)<<endl;
cout<<islevelfull(root,5)<<endl;
cout<<"---------------check complete-----------"<<endl;
int level=0;
cout<<checkcomplete(root,level)<<endl;



return 0;
}
