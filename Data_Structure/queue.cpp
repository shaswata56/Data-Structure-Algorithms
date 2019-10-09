#include <bits/stdc++.h>
using namespace std;

class Queue
{
	private:
	int arr[1000000], fcur, bcur;

	public:
	int front, back;

	Queue()
	{
		fcur = bcur = 0;
		front = back = NULL;
	}

	void enqueue(int x)
	{
		if(fcur == bcur && fcur == NULL)
			front = back = x;
		else
			back = x;
		arr[bcur] = back;
		bcur++;
	}

	void dequeue()
	{
		if(fcur < bcur)
		{
			fcur++;
			if(fcur == bcur) 
				back = front = arr[fcur];
			else
				front = arr[fcur];
		}
		else if(fcur == bcur)
		{
			front = back = NULL;
			fcur = bcur = 0;
		}
	}
};

int main()
{
	Queue queue;
	queue.enqueue(1);
	cout << "queue.enqueue(1) : queue.front = " << queue.front << ", " << "queue.back = " << queue.back << endl;
	queue.enqueue(3);
	cout << "queue.enqueue(3) : queue.front = " << queue.front << ", " << "queue.back = " << queue.back << endl;
	queue.enqueue(5);
	cout << "queue.enqueue(5) : queue.front = " << queue.front << ", " << "queue.back = " << queue.back << endl;
	queue.dequeue();
	cout << "queue.dequeue() : queue.front = " << queue.front << ", " << "queue.back = " << queue.back << endl;
	queue.dequeue();
	cout << "queue.dequeue() : queue.front = " << queue.front << ", " << "queue.back = " << queue.back << endl;
	queue.dequeue();
	cout << "queue.dequeue() : queue.front = " << queue.front << ", " << "queue.back = " << queue.back << endl;
	queue.dequeue();
	cout << "queue.dequeue() : queue.front = " << queue.front << ", " << "queue.back = " << queue.back << endl;
	return 0;
}

