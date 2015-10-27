#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
vector<int> v;
vector<node*> l;
}*root;
void init()
{
root=0;
}

