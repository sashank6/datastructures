#include<iostream>
using namespace std;
struct dirlist;
struct filep
{
string name;
filep *next;
};
struct directory
{
string name;
filep *list;
dirlist *dlist;
}*root;
struct dirlist
{
directory *dir;
dirlist *next;
};
struct q
{
directory *node;
q * next;
} *head,*lastnode;
void displayfiles(directory *node)
{
filep *p=node->list;
for(;p!=0;p=p->next)
cout<<p->name<<endl;
}
filep * addfile(directory *node,string name)
{
filep *ptr=node->list;
filep *nfile=new filep;
nfile->name=name;
nfile->next=ptr;
return nfile;
}
dirlist * adddirectory(directory *node,string name)
{
directory *ndi=new directory;
ndi->name=name;
ndi->list=0;
ndi->dlist=0;
dirlist *f=node->dlist;
dirlist *n=new dirlist;
n->dir=ndi;
n->next=f;
return n;
}
void displaydirectory(directory *node)
{
dirlist *p=node->dlist;
for(;p!=0;p=p->next)
cout<<p->dir->name<<endl;
}
void init()
{
root=0;
root=new directory;
root->name="root";
root->list=0;
root->dlist=0;
head=0;
lastnode=0;
}
directory *search(directory *node,string name)
{
dirlist *f=node->dlist;
for(;f!=0;f=f->next)
if(f->dir->name==name)
return f->dir;
return 0;
}
void process(directory *node)
{
while(1)
{
cout<<"---------Directory List----------"<<endl;
displaydirectory(node);
cout<<"---------File List---------------"<<endl;
displayfiles(node);
cout<<"1. Add Directory"<<endl;
cout<<"2. Add Files"<<endl;
cout<<"3. Navigate to a directory"<<endl;
cout<<"4. Exit"<<endl;
int ch;
cin>>ch;
string name;
if(ch>0&&ch<4)
{
cout<<"Give a name"<<endl;
cin>>name;
}
else
break;
switch(ch)
{
case 2:
node->list=addfile(node,name);
break;

case 1:
node->dlist=adddirectory(node,name);
break;

case 3:
{
directory *u=search(node,name);
if(u==0)
cout<<"No directory found"<<endl;
else
process(u);
break;
}
}
}
}
void enqueue(directory *node)
{
if(head==0)
{
head=new q;
head->node=node;
head->next=0;
lastnode=head;
return;
}
q *newnode;
newnode=new q;
newnode->node=node;
newnode->next=0;
lastnode->next=newnode;
lastnode=newnode;
}
void exl(directory *dir)
{
directory *node=dir;
cout<<"-------Files in the directory------"<<node->name<<endl;
displayfiles(node);
cout<<"-------Directories in the directory------"<<node->name<<endl;
while(node->dlist!=0)
{
cout<<node->dlist->dir->name<<endl;
enqueue(node->dlist->dir);
node->dlist=node->dlist->next;
}
}
void leveltrav()
{
enqueue(root);
q *aux=head;
while(aux!=0)
{
exl(aux->node);
aux=aux->next;
}
}
void preorder(directory *dir)
{
cout<<dir->name<<endl;
while(dir->dlist!=0)
{
preorder(dir->dlist->dir);
dir->dlist=dir->dlist->next;
}
}


int main()
{
init();
process(root);
//leveltrav();
preorder(root);
return 0;
}
