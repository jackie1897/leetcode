/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
 */

#include <iostream>
#include <vector>
#include <sys/time.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

	if( gas.size() == 0 || gas.size() != cost.size())
		return -1;
        int n = gas.size();
        int i = 0;
        int idx = 0;
        int g = 0;
        int c = 0;
        bool start = true;
        while( (i != idx && !start) || (i == idx && start ))
        {
            g += gas[i];
            c += cost[i];
            if(c > g)
            {
                i  = (i+1)%n;
                if((i <= idx) || (idx >= (n-1)))
                    return -1;
                idx = i;
                //start again
                start = true;
                g = 0;
                c = 0;

            }
            else
            {
                i = (i+1)%n;

                start = false;
            }
        }

         return idx;

    }
};

void input (vector<int>& input)
{


    cout<<"input number of vector:"<<endl;
    int n = 0;
    cin>>n;
    cout<<"n is "<<n<<endl;
    int tmp = 0;
    for( int i = 0;i<n;i++)
    {
        cout<<"input value:"<<endl;
        cin>>tmp;
        cout<<"value is "<<tmp<<endl;
        input.push_back(tmp);
    }

}

int main()
{
    vector<int> gas;
    vector<int> cost;

    cout<<"*********************gas input ********************"<<endl;
    input(gas);
    cout<<"*********************cost input ********************"<<endl;
    input(cost);

    Solution ln;
	struct timeval begin_tv, end_tv;
	gettimeofday(&begin_tv, NULL);
    int starting = ln.canCompleteCircuit(gas,cost);
	gettimeofday(&end_tv, NULL);
	int eclapsed = (end_tv.tv_sec - begin_tv.tv_sec) * 1000 + (end_tv.tv_usec - begin_tv.tv_usec) / 1000;

	cout<<"end_tv.tv_usec:"<<end_tv.tv_usec<<"-begin_tv.tv_usec:"<<begin_tv.tv_usec<<endl;
    cout<<"starting gas index:"<<starting<<"--eclapsed time:"<<eclapsed<<endl;
    return 0;
}
