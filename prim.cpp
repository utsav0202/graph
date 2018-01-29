#include <iostream>
#include <climits>
#include <algorithm>
#include <map>
#include "graph.h"
#include "min_heap.h"

void graph::prim_mst ()
{
	min_heap <int> mh;
	map<int, edge> from_edge;
	graph mst (vertices, true);
	int mst_weight = 0;

	mh.add (0, 0);
	for (int i = 1; i < vertices; ++i)
		mh.add (i, INT_MAX);

	while (!mh.empty ())
	{
		int v = mh.extract_min ();
		if (from_edge.find (v) != from_edge.end ())
		{
			mst.add_edge (from_edge[v].u, from_edge[v].v, from_edge[v].weight);
			mst_weight += from_edge[v].weight;
		}

		for (list<vertex>::iterator it = adj_list[v].begin ();
			it != adj_list[v].end (); ++it)
		{
			if (mh.contains (it->v) && mh.data (it->v) > it->weight)
			{
				mh.decrease (it->v, it->weight);

				/*pair<map<int, edge>::iterator, bool> ret = 
					from_edge.insert (pair<int, edge>(it->v, edge (v, it->v, it->weight)));
				ret.first->second.u = v;
				ret.first->second.v = it->v;
				ret.first->second.weight = it->weight;*/

				from_edge[it->v] = edge (v, it->v, it->weight);
			}
		}
	}

	mst.display ();
	cout << "Total weight : " << mst_weight << endl << endl;
}