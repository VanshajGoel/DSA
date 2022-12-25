#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

void printBFS (vector <vector <int>> v, int sv, vector <bool>& visited)
{
	queue <int> q;
	q.push (sv);
	visited [sv] = true;
	while (!q.empty ())
	{
		int cv = q.front ();
		q.pop ();
		cout << cv << endl;
		for (int i = 0; i < v.size(); i++)
		{
			if (v [cv][i] == 1 && visited [i] == false)
			{
				q.push (i);
				visited [i] = true;
			}
		}
	}
}

int BFS (vector <vector<int>>v)
{
	vector <bool> visited (v.size(), false);
	int components = 0;
	for (int i = 0 ; i < v.size (); i++)
	{
		if (!visited [i])
		{
			printBFS (v, i, visited);
			components++;
		}
	}
	return components;
}

int main (int argc, char** argv)
{
	int n = atoi (argv[1]);
	int e = atoi (argv[2]);
	vector < vector <int> > matrix (n, vector <int> (n,0));
	for (int i = 0 ; i < e; i++)
	{
		int fst, scnd;
		cout << "Enter first vertex and second vertex: ";
		cin >> fst >> scnd;
		matrix [fst][scnd] = 1;
		matrix [scnd][fst] = 1;
	}
	int components =  BFS (matrix);
	cout << "No of connected components are: " << components << endl;
	return 0;
}
