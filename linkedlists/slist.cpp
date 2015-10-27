#include<iostream>
using namespace std;
struct node
{
int data;
node *link;
}*root,*lastnode;
void init()
{
root=0;
}
node * createnode(int data)
{
node* newnode;
newnode=new node;
newnode->data=data;
newnode->link=0;
return newnode;
}
void insert(int data)
{
if(root==0)
{
root=createnode(data);
lastnode=root;
return;
}
lastnode->link=createnode(data);
lastnode=lastnode->link;
}

void display()
{
for(node* t=root;t!=0;t=t->link)
cout<<t->data<<endl;
}

void deletenode(int data,node **p)
{
node *t=*p;
for(;t!=0&&t->link->data!=data;t=t->link);
cout<<t->data<<endl;
free(t->link);
}

int main()
{
init();
for(int i=0;i<11;i++)
insert(i);
display();
delete root;
display();
return 0;
}

