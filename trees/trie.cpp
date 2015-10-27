#include<iostream>
using namespace std;
struct node
{
int isChild;
node* arr[26];
};
node *root;
void traversal(node*);
void init()
{
root=0;
}
node * newnode(int a)
{
node *t=new node;
for(int i=0;i<26;i++)
t->arr[i]=0;
t->isChild=a;
return t;
}
node * insert(node *p,string str)
{

if(str.length()==0)
return newnode(1);
if(p->arr[str[0]-'a']==0)
{
if(str.length()>2)
{
p->arr[str[0]-'a']=newnode(0);
}
else
{
p->arr[str[0]-'a']=newnode(1);
cout<<str[0]<<endl;
}
p->arr[str[0]-'a']=insert(p->arr[str[0]-'a'],str.substr(1));
return p;
}
else
{
if(str.length()==1)
{
p->isChild=1;
}
else
{
p->arr[str[0]-'a']=insert(p->arr[str[0]-'a'],str.substr(1));
}
return p;
}
}
void traversal(node* p)
{
if(p!=0)
{
for(int i=0;i<26;i++)
{
if(p->arr[i]!=0)
{
cout<<(char)(i+'a')<<" "<<p->isChild<<endl;
traversal(p->arr[i]);
}
}
}
}




int main()
{

init();
root=newnode(0);
root=insert(root,"at");
root=insert(root,"ate");
root=insert(root,"atmost");
traversal(root);
cout<<endl;
return 0;
}

