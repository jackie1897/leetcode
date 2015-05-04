//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return NULL;

        TreeNode *head = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

        return head;
    }

private:
    TreeNode* buildTree(vector<int>& inorder,int inBegin,int inEnd,vector<int>& postorder, int poBegin,int poEnd){
        if(inBegin > inEnd)
            return NULL;

        int root = postorder[poEnd];

        int index=0;
        for(int i = inBegin;i <= inEnd; i++){
            if( inorder[i] == root ){
                index = i;
                break;
            }
        }

        int len = index - inBegin;
        TreeNode* left =  buildTree(inorder,inBegin,index-1, postorder, poBegin,poBegin+len-1);
        TreeNode* right =  buildTree(inorder,index+1,inEnd, postorder, poBegin+len,poEnd - 1);

        TreeNode *node = new TreeNode(root);
        node->left = left;
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
	cout<<"please input inorder string(delimited with ,):";
	cin>>strTmp;
	vector<int> vInorder;
	parse(vInorder,strTmp);

	strTmp.clear();
	cout<<"please input postorder string(delimited with ,):";
	cin>>strTmp;
	vector<int> vPostorder;
	parse(vPostorder,strTmp);

	Solution sl;
	TreeNode* head = sl.buildTree(vInorder,vPostorder);
	cout<<"is head null:"<<(NULL == head)<<endl;
	inOrderTraversal(head);

}
