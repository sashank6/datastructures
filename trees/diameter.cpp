#include<iostream>
#include<algorithm>
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
void diameter(node *p,int &width,int &height)
{
if(p!=0)
{
int wl,wr,hl,hr;
wl=width;
wr=width;
hl=height;
hr=height;
diameter(p->left,wl,hl);
diameter(p->right,wr,hr);
width=max(max(hl+hr+1,wl),wr);
height=max(hl,hr);
height++;
}
}


int main()
{
node* root=0;
//int arr[]={25,10,5,15,14,16,30,35,40,45,38,37,39};
int arr[]={30,20,40,15,25,35,45};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
root=insert(root,arr[i]);
int width=0;
int height=0;
diameter(root,width,height);
cout<<width<<","<<height<<endl;
return 0;
}



