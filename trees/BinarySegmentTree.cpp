#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	int start;
	int end;
	TreeNode *left;
	TreeNode *right;

};


TreeNode* createNode(int val,int start,int end)
{
	TreeNode *t=new TreeNode;
	t->val=val;
	t->start=start;
	t->end=end;
	t->left=0;
	t->right=0;
	return t;
}

void inorder(TreeNode *t)
{
	if(t!=0)
	{
		inorder(t->left);
		cout<<t->val<<" "<<"start: "<<t->start<<" "<<"end: "<<t->end<<endl;
		inorder(t->right);
	}
}

int getSum(vector<int> v,int start,int end)
{
	int sum=0;
	for(int i=start;i<end;i++)
		sum+=v[i];
	return sum;
}


void display(vector<int> v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}


TreeNode * createSegTree(vector<int> v,int start,int end)
{

	if(start==end-1 || start==end)
		return createNode(v[start],start,end-1);

	TreeNode *t=createNode(getSum(v,start,end),start,end-1);

	int mid=(start+end)/2;
	t->left=createSegTree(v,start,mid);
	t->right=createSegTree(v,mid,end);

	return t;


}

int findSum(TreeNode *t,int start,int end)
{
	if(start==t->start && end==t->end || (t->left==0 && t->right==0 && t->start>=start && t->end<=end))
		return t->val;
	if(t->left!=0)
	{
		if(start > t->left->end)
			return findSum(t->right,start,end);

		if(end <=t->left->end)
			return findSum(t->left,start,end);

		if(start>=t->left->start && end > t->left->end)
			return findSum(t->left,start,t->left->end)+findSum(t->right,t->right->start,end);

	}

}


TreeNode* findMin(TreeNode *root,int start,int end){

	if(root->left==0 && root->right==0)
		if(root->start>=start && root->end<=end)
			return root;

	if(root->left!=0){

		if(start > root->left->end){
			return findMin(root->right,start,end);
		}

		if(root->left->end<end){

			TreeNode* lt=findMin(root->left,start,root->left->end);
			TreeNode* rt=findMin(root->right,root->right->start,end);

			return lt->val <rt->val?lt:rt;

		}

		if(root->left->end>=end){
			return findMin(root->left,start,end);
		}


	}

	return 0;


}






int main()
{
	int arr[]={1,8,7,2,6,1};

	vector<int> num;

	int n=sizeof(arr)/sizeof(*arr);

	vector<TreeNode*> t;

	for(int i=0;i<n;i++)
		num.push_back(arr[i]);

	TreeNode *tr=createSegTree(num,0,num.size());
	inorder(tr);


	cout<<endl;

	cout<<findSum(tr,3,20)<<endl;

	TreeNode* r=findMin(tr,3,20);
	if(r!=0)
		cout<<(r->val)<<endl;



}
