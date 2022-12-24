  #include <iostream>
  #include <vector>
  #include <cstdlib>
  using namespace std;

  void print (vector <vector <int>> v, int st, vector <bool>& visited)
  {
      cout << st << endl;
      visited [st] = true;
      for (int i = 0; i < v.size(); i++)
      {   
          if (v [st][i] == 1 && visited [i] == false)
          {
              print (v, i, visited);
          }
      }   
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
      vector <bool> visited (n, false);
      print (matrix, 0, visited);
      return 0;
  }
