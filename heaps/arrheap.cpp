#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void display(vector<char> v)
{
for(int i=1;i<v.size();i++)
cout<<v[i]<<" ";
cout<<endl;
}
void swim(int k,vector<char> &v)
{
while(k>1)
{
//cout<<k<<endl;
if(v[k] > v[k/2])
swap(v[k],v[k/2]);
k=k/2;
}
}
void sink(int k,vector<char> &v)
{
while(2*k+1<=v.size()-1)
{
if(v[k] > v[2*k+(v[2*k+1]<v[2*k])])
swap(v[k],v[2*k+(v[2*k+1]<v[2*k])]);
k=2*k+(v[2*k+1]>v[2*k]);
}
while(2*k<=v.size()-1)
{
if(v[k] > v[2*k])
swap(v[k],v[2*k]);
k=2*k;
}
}
int main()
{
vector<char> v;
v.push_back('a');
char arrl[]={'S','O','R','T','E','X','A','M','P','L','E'};
for(int i=0;i<sizeof(arrl)/sizeof(*arrl);i++)
{
v.push_back(arrl[i]);
if(i<sizeof(arrl)/sizeof(*arrl)-1)
swim(i+1,v);
}
display(v);
return 0;
}

