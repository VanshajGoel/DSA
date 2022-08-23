#include<iostream>
using namespace std;

template<typename T>
class Node
{
	public:
		T data;
		Node<T>* next;
		Node (T data)
		{
			this->data = data;
			next = NULL;
		}
};

template<typename T>
class Stack
{
	Node<T>* top;
	int numEle;
	public:
		Stack ()
		{
			top = NULL;
			numEle = 0;
		}
		void push (T data)
		{
			Node<T>* newNode = new Node(data);
			newNode -> next = top;
			top = newNode;
			numEle++;
		}

		void pop ()
		{
			if (top)
			{
				Node<T>* temp = top;
				top = top -> next;
				temp->next = NULL;
				delete temp;
				numEle--;
			}
			else
				cout<<"Stack Underflow"<<endl;
		}

		void Top ()
		{
			if (top)
				cout << top->data << endl;
			else
				cout << "Stack Underflow" << endl;
		}

		int size ()
		{
			return numEle;
		}

		bool isEmpty ()
		{
			return top==NULL;
		}
};

int main()
{
	Stack<char> s;
	s.push(101);
	s.push(102);
	s.push(103);
	s.Top();
	s.pop();
	s.Top();
	cout<<"Size = " << s.size()<< endl;
	cout <<"Empty ? "<< s.isEmpty() <<endl;
	return 0;
}
