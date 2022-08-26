#include <iostream>
using namespace std;

template <typename T>
class Queue
{
	int lastidx, capacity, frontidx;
	int size;
	int *arr;
	public:
		Queue ()
		{
			frontidx = -1;
			lastidx = -1;
			capacity = 2;
			size = 0;
			arr = new T[capacity];
		}
		Queue (int n)
		{
			frontidx = -1;
			lastidx = -1;
			capacity = n;
			size = 0;
			arr = new T[capacity];
		}
		void push (T data)
		{
			if (size == capacity)
			{
				cout <<"Queue full"<<endl;
			}
			else
			{
				lastidx++;
				arr[lastidx % capacity] = data;
				lastidx = lastidx % capacity;
				size++;
				if(frontidx == -1)
					frontidx++;
			}
		}
		T front ()
		{
			if (size == 0)
			{
				cout << "Queue Empty"<<endl;
				return -1;
			}
			return arr[frontidx];
		}
		void pop ()
		{
			if (size == 0)
			{
				cout <<"Queue Empty"<<endl;
				return;
			}
			else
			{
				frontidx = (frontidx+1) % capacity;
				size--;
				if (size == 0)
				{
					frontidx = -1;
					lastidx = -1;
				}
			}
		}
		int getSize ()
		{
			return size;
		}
		bool isEmpty ()
		{
			return size == 0;
		}
};

int main ()
{
	Queue <int> q(5);
	q.push (10);
	q.push (20);
	q.push (30);
	q.push (40);
	q.push (50);
	cout<<q.front()<<endl;
	q.pop ();
	cout<<q.front()<<endl;
	cout<<q.getSize()<<endl;
	cout<<q.isEmpty()<<endl;
	q.pop ();
	q.pop ();
	q.pop ();
	q.pop ();
	q.pop ();
	cout<<q.isEmpty()<<endl;
	return 0;
}
