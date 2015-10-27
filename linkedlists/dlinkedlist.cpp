#include<iostream>
using namespace std;
struct Node
{
int data;
Node *flink;
Node *blink;
}*head1,*head2;

void init()
{
head1=0;
head2=0;
}
void insert(int var)
{
if(head1==0)
{
head1=new Node;
head1->data=var;
head1->flink=0;
head1->blink=0;
head2=head1;
//cout<<head2->data<<endl;
}
else
{
Node* t,*newnode;
for(t=head1;t->flink!=0;t=t->flink);
newnode=new Node;
newnode->data=var;
newnode->flink=0;
newnode->blink=t;
t->flink=newnode;
head2=newnode;
}
}
void display()
{
Node* t;
for(t=head2;t!=0;t=t->blink)
cout<<t->data<<endl;
}
int main()
{
init();
for(int i=0;i<10;i++)
insert(i);
display();
}


