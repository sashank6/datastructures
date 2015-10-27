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
node* search(node* p,int data)
{
if(p!=0)
{
if(p->data==data)
return p;
if(data > p->data)
return search(p->right,data);
if(data < p->data)
return search(p->left,data);
}
return 0;
}
bool identical(node *t1,node *t2)
{
   if(t1!=0&&t2!=0)
   {
	if(!(t1->data^t2->data))
         {
           return identical(t1->left,t2->left) & identical(t1->right,t2->right); 
         } 
          return false;

   }
   if(t1==0&&t2==0)
    return true;
    return false;
}


int main()
{
node* root=0;
int arr[]={10,6,12,4,7,11,13};
int arr1[]={6,7,4};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
root=insert(root,arr[i]);
node *root1=0;
len=sizeof(arr1)/sizeof(*arr1);
for(int i=0;i<len;i++)
root1=insert(root1,arr1[i]);
preorder(root1);
node *x;
x=search(root,root1->data);
cout<<identical(x,root1)<<endl;
//preorder(x);
return 0;
}



