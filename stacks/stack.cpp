#include<iostream>
#include<algorithm>
#define SIZE 10
#define UINT unsigned int
using namespace std;
unsigned int stackarr[SIZE];
int top=-1;
void error(string str)
{
cout<<str<<endl;
}
void stackhalfsplit()
{	
     for(int i=top/2,t=top;i>=0;i--,t--)
	swap(stackarr[i],stackarr[t]);		
}
void push(UINT val)
{
if(top+1>SIZE-1)
{
error("Stack Overflow");
return;
}
stackarr[++top]=val;
}
void pop()
{
if(top<=-1)
{
error("Stack Underflow");
return;
}
top--;
}
UINT stacktop()
{
if(top<=-1)
{
error("Stack Underflow");
return 0;
}
return stackarr[top];
}
void display()
{
for(int i=0;i<=top;i++)
cout<<stackarr[i]<<endl;
}

int main()
{
for(int i=0;i<SIZE;i++)
push(i);
display();
cout<<"-------------------------------"<<endl;
stackhalfsplit();
display();

return 0;

}




