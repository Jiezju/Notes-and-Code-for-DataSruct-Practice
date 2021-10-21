/*
V E
6 8

edge

0 1
0 2
0 5
1 2
1 3
1 4
3 4
3 5


*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

template <typename graph>
class ReadGraph
{
public:
	ReadGraph(graph g, string& filename)
	{
		ifstream file(filename);
		string line;
		int V, E;
		
		assert(file.is_open());
		
		assert(getline(file, line));
		stringstream ss(line);
		ss>>V>>E;
		
		assert(V == g.V());
		
		for (int i=0; i<E; ++i)
		{
			assert(getline(file, line));
			stringstream ss(line);
			int a,b;
			ss>>a>>b;
			g.addEdge(a, b);
		}
	}
	
};