#include <iostream>
using namespace std;

template <typename V>
class MapNode
{
    string key;
    V value;
    MapNode* next;

    public:

        MapNode (string key, V value)
        {
            this -> key = key;
            this -> value = value;
            next = NULL;
        }

        ~MapNode ()
        {
            delete next;
        }
        template <typename U>
        friend class myMap; 
};

template <typename U>
class myMap
{
    MapNode <U>* *buckets;
    int count;
    int bucketSize;

    int HashFunction (string s)
    {   
        int base = 1;
        int hashCode = 0;
        for (int i = s.size() -1; i >= 0; i--)
        {
            hashCode += s[i] * base;
            base *= 37;
            hashCode = hashCode % bucketSize;
            base = base % bucketSize;
        }
        return hashCode % bucketSize;
    }
  
    void reHash()
    {
        int oldSize = bucketSize;
        bucketSize *= 2;
        MapNode<U>* *temp = buckets;
        buckets = new MapNode<U>* [bucketSize];
        for (int i = 0 ; i < bucketSize; i++)
        {
            buckets[i] = NULL;
        }
        count = 0;
        for (int i = 0 ; i < oldSize; i++)
        {
            MapNode<U>* head = temp [i];
            while (head)
            {
                string key = head -> key;
                U value = head -> value;
                insert (key, value);
                head = head -> next;
            }
        }
        for (int i = 0 ; i < oldSize; i++)
        {
            delete temp[i];
        }
        delete []temp;
    }
  
    public:

        myMap ()
        {
            bucketSize = 5;
            count = 0;
            buckets = new MapNode<U>* [bucketSize];
            for (int i = 0 ; i < bucketSize; i++)
            {
                buckets[i] = NULL;
            }
        }

        ~myMap ()
        {
            for (int i = 0 ; i < bucketSize; i++)
            {
                delete buckets [i];
            }
            delete [] buckets;
        }

        int size ()
        {
            return count;
        }
  
        void insert (string key, U value)
        {
            int bucketIdx = HashFunction (key);
            MapNode<U>* head = buckets[bucketIdx];
            while (head)
            {
                if (head -> key == key)
                {
                        head -> value = value;
                        return;
                }
                head = head -> next;
            }
            MapNode<U>* node = new MapNode<U>(key, value);
            node -> next = buckets[bucketIdx];
            buckets[bucketIdx] = node;
            count ++;
            if (getLoadFactor() > 0.7)
                reHash();
        }

        U find (string key)
        {
            int bucketIdx = HashFunction (key);
            MapNode<U>* head = buckets [bucketIdx];
            while (head)
            {
                if (head -> key == key)
                {
                    return head -> value;
                }
                head = head -> next;
            }
            return 0;
        }
  
        U remove (string key)
        {
            int bucketIdx = HashFunction (key);
            MapNode<U>* head = buckets [bucketIdx];
            MapNode<U>* prev = NULL;
            while (head)
            {
                if (head -> key == key)
                {
                    if (prev == NULL)
                    {
                        buckets [bucketIdx] = head -> next;
                    }
                    else
                    {
                        prev -> next = head -> next;
                    }
                    U value = head -> value;
                    head -> next = NULL;
                    delete head;
                    count--;
                    return value;
                }
                prev = head;
                head = head -> next;
            }
            return 0;
        }
        double getLoadFactor()
        {
            return (1.0 *count)/bucketSize;
        }

};

int main ()
{
    myMap<int> mp;
    for (int i = 0 ; i < 10 ; i ++)
    {
        char c= '0' + i;
        string key = "abc";
        key = key + c;
        int value = i +1;
        mp.insert(key, value);
        cout << mp.getLoadFactor() << endl;
    }
    cout << mp.size() << endl;
    return 0;
}
