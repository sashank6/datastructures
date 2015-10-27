#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> mymap;
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
int maxelement(map<int,int> mymap)
{
	int ele=0;
	map<int,int>::iterator it;
	for(it=mymap.begin();it!=mymap.end();++it)
	ele=(ele < it->second)?it->second:ele;
	return ele;
}
void maxwidth(node *p,int height)
{
if(p!=0)
{
maxwidth(p->left,height+1);
mymap[height]++;
maxwidth(p->right,height+1);
}
}


int main()
{
node* root=0;
int arr[]={10,6,12,4,7,11,13};
int len=sizeof(arr)/sizeof(*arr);
for(int i=0;i<len;i++)
root=insert(root,arr[i]);
preorder(root);
maxwidth(root,1);
cout<<maxelement(mymap)<<endl;
return 0;
}



