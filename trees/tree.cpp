#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
int data;
node *llink;
node *rlink;
}*root;
void init()
{
root=0;
}
int ask()
{
cout<<"1. Left"<<endl<<"0. Right"<<endl;
int ch;
cin>>ch;
return ch;
}
bool checkfulltree(node *p)
{
if(root==0)
return true;
if((p->llink==0)&(p->rlink==0))
return true;
if((p->llink==0)||(p->rlink==0))
return false;
bool l=checkfulltree(p->llink);
bool r=checkfulltree(p->rlink);
return l&r;
}
bool checkcomplete(node *p,int &level)
{
if(p==0)
{
level--;
return true;
}
if(p->llink==0&&p->rlink==0)
return true;
if(p->llink==0&&p->rlink!=0)
return false;
int level_l,level_r;
level_l=level;level_r=level;
bool l=checkcomplete(p->llink,++level_l);
bool r=checkcomplete(p->rlink,++level_r);
if(p==root)
{
cout<<level_l<<","<<level_r<<endl;
}
level=max(level_l,level_r);
if(l&&r&&((level_l-level_r)==0||(level_l-level_r)==1))
return true;
return false;
}





void inorder(node * p)
{
	if(p!=0)
	{
	inorder(p->llink);
	cout<<p->data<<" ";
	inorder(p->rlink);
	}
}
void postorder(node * p)
{
if(p!=0)
{
postorder(p->llink);
postorder(p->rlink);
cout<<p->data<<" ";
}	
}
node * createnewnode(int data)
{
node *newnode;
newnode=new node;
newnode->data=data;
newnode->llink=0;
newnode->rlink=0;
return newnode;
}
void preorder(node *p)
{
if(p!=0)
{
cout<<p->data<<" ";
preorder(p->llink);
preorder(p->rlink);
}
}
void insert(node * p,int data)
{
if(root==0)
{
root=new node;
root->data=data;
root->llink=0;
root->rlink=0;
}
else
{
cout<<"current data "<<p->data<<endl;
if(ask())
{
if(p->llink!=0)
insert(p->llink,data);
else
{
p->llink=createnewnode(data);
}
}else
{
if(p->rlink!=0)
insert(p->rlink,data);
else
{
p->rlink=createnewnode(data);
}
}
}
}
int main()
{
init();
while(1)
{
int i;
cin>>i;
if(i==0)
break;
insert(root,i);
}

cout<<"Pre-order"<<" ";
preorder(root);
cout<<endl;
cout<<"in-order"<<" ";
inorder(root);
cout<<endl;
cout<<"Post-order"<<" ";
postorder(root);
cout<<endl;
cout<<"check completeness "<<endl;
int level=0;
cout<<checkcomplete(root,level)<<endl;
cout<<"---------checkfull-------------"<<endl;
cout<<checkfulltree(root)<<endl;

return 0;
}



