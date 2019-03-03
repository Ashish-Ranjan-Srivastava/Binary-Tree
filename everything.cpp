# Binary-Tree in c++
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int key;
	node *left;
	node *right;
}*root=NULL;
void insert(int k)
{
	node *n= new node;
	n->left=NULL;
	n->right=NULL;
	n->key=k;
	if(root==NULL)
		root=n;
	else
	{
		queue<node *> q;
		q.push(root);
		while(!q.empty())
		{
			node *curr =q.front();
			q.pop();
		if(curr->left==NULL)
		{
			curr->left=n;
			break;
		}
		else
			q.push(curr->left);
		if(curr->right==NULL)
		{
			curr->right=n;
			break;
		}
		else
			q.push(curr->right);
		}
	}
}
void sumOfParent()
{
	int sum=0;
	if(root==NULL)
	cout<<"no element"<<endl;
	else
	{
		queue<node *> q;
		q.push(root);
		while(!q.empty())
		{
			node *curr=q.front();
			q.pop();
			int t=curr->key;
			if(curr->left!=NULL && curr->right!= NULL)
			{
				sum+=t;
				q.push(curr->left);
				q.push(curr->right);
			}
			else if(curr->left!=NULL)
			{
				sum+=t;
				q.push(curr->left);
			}
			else if(curr->right!=NULL)
			{
				sum+=t;
				q.push(curr->right);
			}
			
		}
		cout<<sum<<" ";
	}
}
void leaf()
{
	if(root==NULL)
		cout<<"-1";
	else
	{
		queue<node*> q;
		q.push(root);
		while(!q.empty())
		{
			node *curr=q.front();
			q.pop();
			if(curr->left==NULL && curr->right==NULL)
			{
				cout<<curr->key<<" ";
			}
			else if(curr->left!=NULL && curr->right!=NULL)
			{
				q.push(curr->left);
				q.push(curr->right);
			}
			else if(curr->left!=NULL)
			{
				q.push(curr->left);
			}
			else if(curr->right!=NULL)
			{
				q.push(curr->right);
			}
		}
	}
}
void inorder(node* tode)
{
	if (tode==NULL)
	  return ;
	inorder(tode->left);
	cout<<tode->key<<" ";
	inorder(tode->right);
}
void depestNode()
{
	int temp;
	if(root==NULL)
		cout<<"-1";
	else
	{
		queue<node*> q;
		q.push(root);
		while(!q.empty())
		{
			node *curr=q.front();
			q.pop();
			if(curr->left==NULL && curr->right==NULL)
			{
				temp=curr->key;
			}
			else if(curr->left!=NULL && curr->right!=NULL)
			{
				q.push(curr->left);
				q.push(curr->right);
			}
			else if(curr->left!=NULL)
			{
				q.push(curr->left);
			}
			else if(curr->right!=NULL)
			{
				q.push(curr->right);
			}
		}
		cout<<temp<<" ";
	}
}
int Ancester(node* root,int target)
{
	if(root==NULL)
		return 0;
		if(root->key==target)
		{
			return 1;
		}
		if(Ancester(root->left,target)|| Ancester(root->right,target))
		{
			cout<<root->key<<" ";
			return 1;
		}
	return 0;
}
void levelorder()
{
	int count=0,i=0;
	node *curr;
	if(root==NULL)
		cout<<"-1";
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		curr=q.front();
		q.pop();
		cout<<curr->key<<" ";
		count++;
		if(count==pow(2,i))
		{
			cout<<endl;
			count=0;
			i++;
		}
		if(curr->left!=NULL)
			q.push(curr->left);
		if(curr->right!= NULL)
		q.push(curr->right);
	}
}



void desc(node* root1)
{
	int count=0,i=0;
	node *curr;
	if(root==NULL)
		cout<<"-1";
	queue<node *> q;
	q.push(root1);
	while(!q.empty())
	{
		curr=q.front();
		q.pop();
		cout<<curr->key<<" ";
		count++;
		if(count==pow(2,i))
		{
			cout<<endl;
			count=0;
			i++;
		}
		if(curr->left!=NULL)
			q.push(curr->left);
		if(curr->right!= NULL)
		q.push(curr->right);
	}
}


node* search(int target)
{
	
	node *curr;
	node *root1;
	if(root==NULL)
		cout<<"-1";
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{   
		curr=q.front();
		q.pop();
		if(curr->key==target)
		{
			root1=curr;
			break;
		}
		if(curr->left!=NULL)
			q.push(curr->left);
		if(curr->right!= NULL)
		q.push(curr->right);
		
	}
	cout<<endl<<"descendants"<<endl;
	desc(root1);
	return root1;
}

int main()
{
	for(int i=1;i<=20;i++)
	{
		insert(i);
	}
	cout<<"inorder traversal"<<endl;
	inorder(root);
	cout<<endl<<"sum of parent node"<<endl;
	sumOfParent();
	cout<<endl<<"Leaf Node"<<endl;
	leaf();
	cout<<endl<<"depest node"<<endl;
	depestNode();
	cout<<endl<<"Ancestor"<<endl;
	Ancester(root,10);
	cout<<endl<<"levelOrderTraversal"<<endl;
	levelorder();
	//cout<<"descendant"<<endl;
	search(2);
}
  

