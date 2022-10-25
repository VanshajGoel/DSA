//Implementation of minimum priority queue

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class priority_queue
{
    vector <T> queue;
    public:
        priority_queue()
        {

        }

        void insert(T element)
        {
            queue.push_back (element);
            int cI = queue.size () - 1;
            while (cI > 0)
            {
                int pI = (cI - 1)/2;
                if (queue [cI] < queue [pI])
                {
                    swap (queue [cI], queue [pI]);
                    cI = pI;
                }
                else
                    break;
            }
        }

        int pop()
        {

            if (isEmpty ())
            {
                cout <<"Queue is empty"<<endl;
                return -1;
            }
            int ans = queue [0];
            int endIdx = queue.size() - 1;
            swap (queue[0], queue[endIdx]);
            queue.pop_back();

            int pi = 0;
            while (true)
            {
                int lci = pi * 2 + 1;
                int rci = pi * 2 + 2;
                int mini = pi;

                if (lci < queue.size() && queue [lci] < queue [mini])
                {
                    mini = lci;
                }
                if (rci < queue.size() && queue [rci] < queue [mini])
                {
                    mini = rci;
                }
                if (pi == mini)
                {
                    break;
                }
                swap (queue [pi], queue [mini]);
            }
            return ans;
        }
  
        T top()
        {
            if (isEmpty)
            {
                cout <<"Queue is empty"<<endl;
                return 0;
            }
            return queue[0];
        }

        int getSize ()
        {
            return queue.size();
        }

        bool isEmpty()
        {
            return queue.size() == 0;
        }
  
        void print ()
        {
            for (int i = 0; i< queue.size(); i++)
            {
                cout << queue [i] <<" ";
            }
            cout << endl;
        }
};

int main ()
{
    priority_queue<int> pq;
    pq.insert(100);
    pq.insert(10);
    pq.insert(15);
    pq.insert(4);
    pq.insert(17);
    pq.insert(21);
    pq.insert(67);
    pq.print();
    cout <<endl;
    while (!pq.isEmpty())
    {
        cout <<pq.pop()<<endl;
    }
    return 0;
}
