/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

#include <iostream>
#include <limits.h>
using namespace std;

int reverse(int x) {

	int sign = 1;
	if(x < 0)
	{
		x = -x;
		sign = -1;
	}
	int result = 0;

	while(x >0 )
	{

		if(result>((INT_MAX - x%10)/10) )//overflow check
			return 0;
		result = result*10 + x%10;
		x /= 10;
		cout<<"result:"<<result<<endl;
		//输入1000000003,溢出之后打印结果是-1294967295,但是此判断条件不知为何不成立;被编译器的-o2参数优化了
		//不能依赖编译器行为,要在之前做判断,参见overflow check标识的代码
		/*if(result < 0 )
		{
			cout<<"in?"<<endl;
			return 0 ;//overflow
		}*/
	}

	return result*sign;
}

int main()
{
	cout<<"reverse integer!input integer:"<<endl;
	int input = 0;
	cin>>input;

	int output = reverse(input);
	cout<<"after reverse:"<<output<<endl;
	if(output<0)//输入1000000003,溢出之后打印结果是-1294967295,此判断条件成立
		cout<<"negative?"<<endl;

	return 0;

}
