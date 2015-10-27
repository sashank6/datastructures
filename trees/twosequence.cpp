#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
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
void separate(vector<int> in,vector<int> pre,vector<int> &inleft,vector<int> &preleft,vector<int> &inright, vector<int> &preright, int rootindex)
{
	int insize=in.size();
	int presize=pre.size();
	for(int i=1;i<=rootindex;i++)
	preleft.push_back(pre[i]);
	for(int i=rootindex+1;i<presize;i++)
	preright.push_back(pre[i]);
	for(int i=0;i<rootindex;i++)
	inleft.push_back(in[i]);
	for(int i=rootindex+1;i<insize;i++)
	inright.push_back(in[i]);
}

node* createtree(vector<int> in,vector<int> pre)
{
 if(pre.size() > 0)
 {
 int data=pre[0];
 vector<int> inleft,preleft,inright,preright;
 int rootindex=distance(in.begin(),find(in.begin(),in.end(),pre[0]));
 separate(in,pre,inleft,preleft,inright,preright,rootindex);
 node *t=0;
 t=createnode(data);
 t->left=createtree(inleft,preleft);
 t->right=createtree(inright,preright);
 return t;
 }
 return 0;
}



int main()
{
vector<int> in,pre;
pre.push_back(1);pre.push_back(2);pre.push_back(4);pre.push_back(5);pre.push_back(3);pre.push_back(6);
in.push_back(4);in.push_back(2);in.push_back(5);in.push_back(1);in.push_back(3);in.push_back(6);
//in.push_back(2);in.push_back(1);in.push_back(3);
//pre.push_back(1);pre.push_back(2);pre.push_back(3);
node *root=0;
root=createtree(in,pre);
preorder(root);
return 0; 
}



