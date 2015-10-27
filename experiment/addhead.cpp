#include<iostream>
using namespace std;
struct node
{
int data;
node *next;
}*root;
void init()
{
root=0;
}
node * adddata(node *p,int data)
{
node *newnode;
newnode=new node;
newnode->data=data;
newnode->next=p;
return newnode;
}
void display()
{
for(node *x=root;x!=0;x=x->next)
cout<<x->data<<endl;
}
int main()
{
init();
for(int i=1;i<5;i++)
root=adddata(root,i);
display();
}
