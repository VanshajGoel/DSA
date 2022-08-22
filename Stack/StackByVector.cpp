#include<iostream>
using namespace std;
#include<vector>
class Stack
{
	vector<int> elements;
	public:

		void push (int i)
		{
			elements.push_back (i);
		}

		void pop()
		{
			if (elements.size() == 0)
			{
				cout << "Stack Underflow" << endl;
			}
			else
				elements.pop_back();
		}
		void DisplayTop()
		{
			if (elements.size() != 0)
				cout << elements [elements.size()-1] << endl;
			else
				cout << "Stack Underflow" <<endl;
		}
		bool isEmpty()
		{
			return 0 == elements.size();
		}
		int size()
		{
			return elements.size();
		}
};

int main ()
{
	Stack s;
	s.push(40);
	s.pop();
	s.pop();
	s.push(10);
	cout<<s.size()<<endl;
	s.pop();
	cout<<s.isEmpty()<<endl;
	s.DisplayTop();
	return 0;
}
