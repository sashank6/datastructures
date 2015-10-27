#include<iostream>
#include"rpnconv.h"
#include<stack>
using namespace std;
struct node
{
char data;
node *left;
node *right;
};
stack<node*> t;
void createnode(node **p,char c)
{
*p=new node;
(*p)->data=c;
(*p)->left=0;
(*p)->right=0;
}
void inorder(node *p)
{
if(p!=0)
{
inorder(p->left);
cout<<p->data<<" ";
inorder(p->right);
}
}
int main()
{
init();
string str=rpn("a+b*c/d");
for(int i=0;i<str.length();i++)
{
if(isoperand(str[i]))
{
node *p;
createnode(&p,str[i]);
t.push(p);
}
else
if(isopr(str[i]))
{
node *q;
createnode(&q,str[i]);
q->right=t.top();
t.pop();
q->left=t.top();
t.pop();
t.push(q);

}
}
node *root;
root=t.top();
inorder(root);

}
