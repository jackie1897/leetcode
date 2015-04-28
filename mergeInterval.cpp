/*
 For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}

};


const string gmergedebug = "e:\\mergedebug.txt";
class Solution {
public:
	class ltCompareInterval
	{
	public:
		bool operator()(const Interval& left,const Interval& right)
		{
	  	  return left.start < right.start;
		}
	};

	  //BAD solution. It cost about 600 ms.!!!!!!!!!!
    vector<Interval> merge(vector<Interval> &intervals) {
    	
    	if(intervals.size() <= 1)
    		return intervals;


    	sort(intervals.begin(),intervals.end(),ltCompareInterval());

    	vector<Interval> ans;
    	size_t i = 0;
    	int start = intervals[i].start;
    	int end = intervals[i].end;

    	Interval oInt;
    	do
    	{

    		if(intervals[i].start > end)
    		{
    			oInt.start = start;
    			oInt.end = end;
    			ans.push_back(oInt);
    			start = intervals[i].start;
    			end = intervals[i].end;

    		}else
    		{

    			end = max(intervals[i].end,end);
    		}

    		++i;
    	}while( i < intervals.size());
    	
    	if((ans.empty() ||( !ans.empty() && ans.back().end < start)))
    	{
    	  oInt.start = start;
    	  oInt.end = end;
    	  ans.push_back(oInt);
    	}
    	
    	return ans;
    }
};

const string gstr= "[74,78],[61,63],[46,50]"
const string gfilename = "e:\\debug.txt";

void parse(vector<Interval>& vInt)
{
	//[74,78],[61,63],[46,50]
	size_t index = 0;
	size_t indNext = 0;
	string strTmp;
	Interval oInt;
	ofstream fout(gfilename.c_str(),ios::out);
	while((index = gstr.find('[',index))!= string::npos)
	{
		indNext =  gstr.find(',',index);
		strTmp = gstr.substr(index+1,indNext-index-1);

		oInt.start = atoi(strTmp.c_str());
		cout<<"start:"<<oInt.start<<endl;
		fout<<"start:"<<oInt.start<<endl;

		index = gstr.find(']',indNext);
		strTmp = gstr.substr(indNext+1,index-indNext-1);
		oInt.end = atoi(strTmp.c_str());
		cout<<"end:"<<oInt.end<<endl;
		fout<<"end:"<<oInt.end<<endl;
		vInt.push_back(oInt);

	}
	fout.close();

}

int main()
{
	Interval oInt;
	vector<Interval> vInt;


	parse(vInt);
	Solution oSl;
	vInt = oSl.merge(vInt);

	cout<<"********result**********"<<endl;
	vector<Interval>::iterator it = vInt.begin();
	for(;it != vInt.end();++it)
	{
		cout<<"start:"<<it->start<<"--end:"<<it->end<<endl;
	}
	return 0;
}

