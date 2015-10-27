#include<iostream>
using namespace std;
struct node
{
int data;
node *next;
};
void createnode(node **p,node **x,int data)
{
*p=new node;
(*p)->data=data;
(*p)->next=(*x);
}
void display(node *p)
{
for(node *x=p;x!=0;x=x->next)
cout<<x->data<<endl;
}
int main()
{
node *root;
node *x=0;
createnode(&root,&x,3);
display(root);
return 0;
}

