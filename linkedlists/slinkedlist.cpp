#include<iostream>
#include<cassert>
using namespace std;
struct node
{
int data;
node *link;
} *head;
void init()
{
head=0;
}
void insert(int var)
{
node *lastNode;
if(head==NULL)
{
head=new node;
head->data=var;
head->link=0;
}
else
{
for(lastNode=head;lastNode->link!=0;lastNode=lastNode->link);
lastNode->link=new node;
lastNode->link->data=var;
lastNode->link->link=0;
}
}
void insert(int index,int var)
{
assert(index>=0);

if(head==NULL&&index==0)
insert(var);
else
{
int ind=index;
node *t1,*t,*newnode;
t1=head;
for(t=head;ind&&t!=0;t=t->link,ind--)
{
if(ind-1>=0)
t1=t;
}
newnode=new node;
newnode->data=var;
newnode->link=t;
if(!index)
head=newnode;
else
t1->link=newnode;
}
}
void reverse()
{
node *head1;
for(head1=head;head1->link!=0;head1=head1->link);
node *currNode,*prevNode,*t;
currNode=head->link;
prevNode=head;
while(currNode!=0)
{
t=currNode->link;
currNode->link=prevNode;
prevNode=currNode;
currNode=t;
}
head->link=0;
head=head1;
}
bool found=false;
void display()
{
node *temp;
for(temp=head;temp!=0;temp=temp->link)
cout<<temp->data<<endl;
}
int displayrev(node* head,int pos)
{
int g;
if(head!=0)
{
g=displayrev(head->link,pos);
if(g==pos&&!found)
{
found=true;
return head->data;
}
if(found)
return g;
return g+1;
}
return 0;
}

int main()
{
init();
for(int i=0;i<10;i++)
insert(i);
//insert(0,10);
display();
cout<<displayrev(head,5)<<endl;
//reverse();
//display();
return 0;
}
