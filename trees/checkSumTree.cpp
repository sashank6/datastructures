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
bool checkSumTree(node* p,int &sum)
{
if(p->left==0&&p->right==0)
{
sum=p->data;
return true;
}
if(p!=0)
{
int lsum=0,rsum=0;
bool x=checkSumTree(p->left,lsum);
bool y=checkSumTree(p->right,rsum);
if(x&y)
{
if(lsum+rsum==p->data)
{
sum=2*p->data;
return true;
}
return false;
}
return false;
}
sum=0;
return true;
}



int main()
{
node* root=0;
int arr[]={10,6,12,4,7,11,13};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
root=insert(root,arr[i]);
preorder(root);
int sum=0;
cout<<checkSumTree(root,sum)<<endl;
return 0;
}



