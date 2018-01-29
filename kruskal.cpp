#include <iostream>
#include <algorithm>
#include "graph.h"
#include "disjoint_sets.h"


void graph::kruskal_mst ()
{
	disjoint_sets<int> ds;
	graph mst (vertices, true);
	int mst_weight = 0;

	for (int i = 0; i < vertices; ++i)
	  ds.make_set (i);

	sort(edges.begin (), edges.end (), edge_comparator ());

	for (int i = 0; i < (int)edges.size (); ++i)
	{
		int s1 = ds.find_set (edges[i].u);
		int s2 = ds.find_set (edges[i].v);

		if (s1 != s2)
		{
			mst.add_edge (edges[i].u, edges[i].v, edges[i].weight);
			mst_weight += edges[i].weight;
			ds.union_set (edges[i].u, edges[i].v);
		}
	}

	mst.display ();
	cout << "Total weight : " << mst_weight << endl << endl;
}