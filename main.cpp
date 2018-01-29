#include "graph.h"

int main()
{
	graph g(9, true);
	g.add_edge (0, 1, 4);
	g.add_edge (0, 7, 8);
	g.add_edge (1, 7, 11);
	g.add_edge (1, 2, 8);
	g.add_edge (2, 8, 2);
	g.add_edge (2, 5, 4);
	g.add_edge (2, 3, 7);
	g.add_edge (3, 4, 9);
	g.add_edge (3, 5, 14);
	g.add_edge (4, 5, 10);
	g.add_edge (5, 6, 2);
	g.add_edge (6, 8, 6);
	g.add_edge (6, 7, 1);
	g.add_edge (7, 8, 7);

	g.display ();

	g.kruskal_mst ();
	g.prim_mst ();
}