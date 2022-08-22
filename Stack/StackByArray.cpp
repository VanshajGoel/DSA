#include<iostream>
using namespace std;

class Stack
{
	int *arr;
	int top = -1;
    int capacity;
	public:

		void push (int i)
		{
			top++;
			if (top == capacity)
			{
				int *newArr = new int[2*capacity];
				for (int i = 0; i < capacity; i++)
				{
					newArr[i] = arr[i];
				}
				delete[] arr;
				arr = newArr;
				capacity *=2;
				arr[top] = i;
			}
			else
				arr [top] = i;
		}

		void pop()
		{
			if (top == -1)
				cout << "Stack underfow" << endl;
			else
				top--;
		
		}
		void DisplayTop()
		{
			if (top != -1)
				cout << arr [top] << endl;
			else
				cout << "Stack Underflow" <<endl;
		}
		bool isEmpty()
		{
			if (top == -1)
				return 1;
			return 0;
		}
		int size()
		{
			return top+1;
		}
};

int main ()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.pop();
	cout<<s.size()<<endl;
	cout<<s.isEmpty()<<endl;
	s.DisplayTop();
	return 0;
}
