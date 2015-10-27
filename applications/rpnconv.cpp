#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;
map<char,int> mymap;
queue<char> q;
stack<char> s;
string process();
void init()
{
mymap['^']=1;
mymap['/']=2;
mymap['*']=2;
mymap['+']=3;
mymap['-']=3;
}
int val(char c)
{
return mymap[c];
}
bool isopr(char c)
{
return mymap[c];
}
bool isoperand(char c)
{
return isalpha(c);
}
string rpn(string str)
{
string st="";
for(int i=0;i<str.length();i++)
{
if(isoperand(str[i]))
{
q.push(str[i]);
}
else
if(isopr(str[i]))
{
if(s.empty()||(val(str[i])<val(s.top())))
s.push(str[i]);
else
{
st+=process();
i--;
}
}
}
st+=process();
while(!s.empty())
{
st+=s.top();
s.pop();
}
return st;
}

string process()
{
string p="";
while(!q.empty())
{
p+=q.front();
q.pop();
}
p+=s.top();
s.pop();
return p;

}
