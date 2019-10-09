#include <bits/stdc++.h>
using namespace std;

class Stack
{
	private:
	int arr[1000000], cur;

	public:
	int top;

	Stack()
	{
		cur = -1;
		top = NULL;
	}

	void push(int x)
	{
		cur++;
		arr[cur] = top = x;
	}

	void pop()
	{
		if(cur > 0)
		{
			cur--;
			top = arr[cur];
		}
		else
			top = NULL;
	}
};

int main()
{
	Stack stack;
	stack.push(1);
	cout << "stack.push(1) : stack.top = " << stack.top << endl;
	stack.push(3);
	cout << "stack.push(3) : stack.top = " << stack.top << endl;
	stack.push(5);
	cout << "stack.push(5) : stack.top = " << stack.top << endl;
	stack.pop();
	cout << "stack.pop() : stack.top = " << stack.top << endl;
	stack.pop();
	cout << "stack.pop() : stack.top = " << stack.top << endl;
	stack.pop();
	cout << "stack.pop() : stack.top = " << stack.top << endl;
	stack.pop();
	cout << "stack.pop() : stack.top = " << stack.top << endl;
	return 0;
}
