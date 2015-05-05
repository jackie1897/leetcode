//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if(preorder.empty())
    	{
    		return NULL;
    	}

    	TreeNode * head = buildTree(preorder,0, preorder.size()-1,inorder,0,inorder.size()-1);

    	return head;
    }

private:
    TreeNode* buildTree(vector<int>& preorder,int preBegin,int preEnd,vector<int>& inorder,int inBegin,int inEnd ){
    	if(preEnd < preBegin || inEnd < inBegin)
    	{
    		return NULL;
    	}

    	int root = preorder[preBegin];
    	int index = 0;

    	for(int i = inBegin; i <= inEnd; i++)
    	{
    		if(inorder[i] ==  root)
    		{
    			index = i;
    			break;
    		}
    	}

    	int len = index - inBegin;

    	TreeNode * left = buildTree(preorder,preBegin + 1,preBegin + len,inorder, inBegin, index - 1);
    	TreeNode * right = buildTree(preorder,preBegin + len + 1,preEnd, inorder, index + 1, inEnd);


    	TreeNode * node = new TreeNode(root);

    	node->left =  left;
    	node->right = right;

    	return node;


    }
};



void parse(vector<int>& vInt,string& str)
{
	//1,2,3,4
	size_t index = 0;
	size_t indNext = 0;
	string strTmp;

	int intTmp = 0;
	while((indNext = str.find(',',index))!= string::npos)
	{

		strTmp = str.substr(index,indNext-index);

		intTmp = atoi(strTmp.c_str());
		vInt.push_back(intTmp);
		cout<<"figure:"<<intTmp<<endl;

		index = indNext + 1;
	}
	if( index < str.length())
	{
		strTmp = str.substr(index,str.length()-index);
		intTmp = atoi(strTmp.c_str());
		vInt.push_back(intTmp);
		cout<<"figure:"<<intTmp<<endl;
	}


}

void inOrderTraversal(TreeNode *head)
{
	if(NULL == head)
		return;

	TreeNode *left = head->left;
	inOrderTraversal(left);

	cout<<"head:"<<head->val<<endl;

	TreeNode *right = head->right;
	inOrderTraversal(right);

}

int main()
{
	string strTmp;
	cout<<"please input preorder string(delimited with ,):";
	cin>>strTmp;
	vector<int> vPreorder;
	parse(vPreorder,strTmp);

	strTmp.clear();
	cout<<"please input inorder string(delimited with ,):";
	cin>>strTmp;
	vector<int> vInorder;
	parse(vInorder,strTmp);

	Solution sl;
	TreeNode* head = sl.buildTree(vPreorder,vInorder);
	cout<<"is head null:"<<(NULL == head)<<endl;
	inOrderTraversal(head);

}

