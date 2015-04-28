//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5
//
//Credits:
//Special thanks to @mithmatt for adding this problem and creating all test cases.


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	if( NULL ==  head)
    		return head;
    	cout<<"enter.."<<endl;
    	ListNode root(0);
    	root.next = head;
    	ListNode* last = &root;
    	while(NULL != head)
    	{
    		if(head->val == val)
    		{
    			last->next = head->next;
    			delete head;
    			head = NULL;
    			head = last;
    		}
    		last = head;
    		head = head->next;
    	}

    	return root.next;
    }
};

const string gstr= " 1 --> 1 --> 6 --> 3 --> 4 --> 5 --> 6";

void parse(vector<int>& vInt)
{
	//[74,78],[61,63],[46,50]
	size_t index = 1;
	size_t indNext = 0;
	string strTmp;

	int intTmp = 0;
	while((indNext = gstr.find('-',index))!= string::npos)
	{

		strTmp = gstr.substr(index,indNext-index-1);

		intTmp = atoi(strTmp.c_str());
		vInt.push_back(intTmp);
		cout<<"figure:"<<intTmp<<endl;

		index  = gstr.find('>',indNext);
		index ++;
	}
	if( index < gstr.length())
	{
		strTmp = gstr.substr(index,gstr.length()-1);
		intTmp = atoi(strTmp.c_str());
		vInt.push_back(intTmp);
		cout<<"figure:"<<intTmp<<endl;
	}


}

ListNode * constructNode(const vector<int>& vInt)
{
	ListNode * head = NULL;
	ListNode * last = NULL;
	ListNode * node = NULL;
	for(vector<int>::const_iterator it = vInt.begin(); it != vInt.end(); ++it)
	{
		if(it == vInt.begin())
		{
			head = new ListNode(*it);
			head->next = NULL;
			node = head;
			last = node;
		}else
		{
			node = new ListNode(*it);
			last->next = node;
			node->next = NULL;
			last = node;
		}
	}
	return head;
}

int main()
{
	vector<int> vInt;
	parse(vInt);
	ListNode* head = constructNode(vInt);
	ListNode* node = head;
	while(NULL != node)
	{
		cout<<"node:"<<node->val<<endl;
		node = node->next;
	}

	Solution sl;
	head = sl.removeElements(head,1);
	while(NULL != head)
	{
		cout<<"after remove, node:"<<head->val<<endl;
		head = head->next;
	}
	return 0;

}
