#include<iostream>
using namespace std;
struct node
{
int data;
node *next;
};
void display(node **p)
{
cout<<(*p)->data<<endl;
}
int main()
{
node *root;
root=new node;
root->data=5;
root->next=0;
display(&root);
return 0;
}
