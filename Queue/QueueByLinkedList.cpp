#include <iostream>
using namespace std;

template<typename T>
class Node
{
    public:
        T data;
        Node* next;
        Node (T data)
        {
            this -> data = data;
            next = NULL;
        }
};

template <typename T>
class Queue
{
    Node<T>* front;
    Node<T>* last;
    int size;
    public:
        Queue ()
        {
            front = NULL;
            last = NULL;
            size = 0;
        }
        void push (T data)
        {
            Node <T>* temp = new Node<int>(data);
            if (front == NULL)
            {
                front = temp;
                last = temp;
            }
            else
            {
                last -> next = temp;
                last = last -> next;
            }
            size++;
        }
        void pop ()
        {
            if (front == NULL)
            {
                cout << "Queue Empty"<<endl;
            }
            else
            {
                Node <T>* temp = front;
                front = front -> next;
                delete temp;
                size--;
            }
        }
        T getSize ()
        {
            return size;
        }
        bool isEmpty ()
        {
            return size == 0;
        }
        T frontData ()
        {
            return front -> data;
        }
};

int main ()
{
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    cout<<q.frontData()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.frontData()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    q.push(60);
    q.push(70);

    q.pop();
    q.pop();
    cout<<q.frontData()<<endl;
    cout<<q.getSize()<<endl;

    while(!q.isEmpty()){
        cout<<q.frontData()<<endl;
        q.pop();
    }
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}