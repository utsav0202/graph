#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct edge
{
	int u;
	int v;
	int weight;

	edge () {}
	edge (int u, int v, int w)
		: u(u), v(v), weight(w) {}
};

struct vertex
{
	int v;
	int weight;

	vertex (int v, int w)
		: v (v), weight (w) {}
};
struct edge_comparator
{
	bool operator () (edge e1, edge e2)
	{
		return e1.weight < e2.weight;
	}
};

class graph
{
public:
	graph (int vertices, bool weighted_p)
		: vertices (vertices), weighted_p (weighted_p), adj_list (vertices)
	{}

	void add_edge (int u, int v, int w = 0)
	{
		edges.push_back (edge (u, v, w));
		adj_list[u].push_back (vertex (v, w));
		adj_list[v].push_back (vertex (u, w));
	}

	void display ()
	{
		for (int i = 0; i < (int)adj_list.size (); ++i)
		{
			cout << i << " -> ";
			for (list<vertex>::iterator it = adj_list[i].begin ();
				it != adj_list[i].end (); ++it)
			{
				cout << it->v << ", ";
			}
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < (int)edges.size (); ++i)
		{
			cout << "(" << edges[i].u << " <-> " << edges[i].v << ") : " << edges[i].weight << endl;
		}

		cout << endl;
	}
	
	void prim_mst ();
	void kruskal_mst ();

private:
	bool weighted_p;
	int vertices;
	vector<edge> edges;
	vector<list<vertex> > adj_list;
};