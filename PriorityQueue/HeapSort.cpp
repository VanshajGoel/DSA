#include <iostream>
using namespace std;

void HeapSort(int *arr, int n)
{
	for (int i = 0 ; i < n ; i++)	
	{
		int cI = i;
	    while (cI > 0)
		{
        	int pI = (cI - 1)/2;
            if (arr [cI] < arr [pI])
            {
                swap (arr [cI], arr [pI]);
                cI = pI;
            }
            else 
				break;
		}
	}
	//Removing all elements
	int size = n;
	while (size >= 1)
	{
		swap (arr [0], arr [size - 1]);
		size--;
	
		int pi = 0;
		while (true)
		{
			int lci = pi * 2 + 1;
			int rci = pi * 2 + 2;
			int mini = pi;
			
			if (lci < size && arr [lci] < arr [mini])
			{
				mini = lci;
			}
			if (rci < size && arr [rci] < arr [mini])
			{
				mini = rci;
			}
			if (pi == mini)
				break;

			swap (arr [mini], arr[pi]);
		}
	}
}

int main ()
{
	int arr[] = {3,1,10,5,7};
	HeapSort (arr, 5);
	for (int i = 0 ; i < 5; i++)
	{
		cout << arr [i] <<" ";
	}
	cout << endl;
	return 0;
}
