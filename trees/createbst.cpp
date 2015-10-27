#include<iostream>
using namespace std;
struct node
{
int data;
node *left;
node *right;
}*root;
int deletem(node **s,node **r);
node * createnode(int data)
{
node *p;
p=new node;
p->data=data;
p->left=0;
p->right=0;
return p;
}
void createbst(node *p,int data)
{
if(root==0)
{
root=createnode(data);
return;
}
if(data >= p->data)
{
if(p->right==0)
p->right=createnode(data);
else
createbst(p->right,data);
}
if(data<(p->data))
{
if(p->left==0)
p->left=createnode(data);
else
createbst(p->left,data);
}
}
void init()
{
root=0;
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
bool ischild(node *p)
{
return (p->left==0)&(p->right==0);
}
bool deletenode(int data,node **p, node **s)
{
if((*p)==0)
{
return false;
}
if((*p)->data==data)
{
if(ischild(*p))
{
cout<<"is child"<<endl;
(*p)=0;
return true;
}
if((*p)->left==0)
{
*s=(*p)->right;
return true;
}
if((*p)->left!=0)
{
cout<<"Deletem"<<endl;
(*p)->data=deletem(&(*p)->left,&(*p)->left);

}
}
if(data >=(*p)->data)
deletenode(data,&(*p)->right,&(*p));
else
if(data<(*p)->data)
deletenode(data,&(*p)->left,&(*p));
return false;
}
int deletem(node **r,node **s)
{
node *x=(*r)->left;
node *y=(*r)->right;
if(ischild(*r))
{

int x=((*r)->data);
(*s)->right=0;
*r=0;
return x;
}
if(y!=0)
{
return deletem(&y,r);
}
if((y==0)&(x!=0))
{
(*s)->right=x;
return (*r)->data;
}
}




int main()
{
init();
int arr[]={90,50,150,20,75,95,175,5,25,66,80,92,111,166,200,62,73,72,70,71,76,83};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
createbst(root,arr[i]);
preorder(root);
deletenode(175,&root,&root);
preorder(root);
return 0;
}
