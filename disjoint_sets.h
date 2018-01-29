#include <map>
#include <memory>

using namespace std;

template <class T>
class disjoint_sets
{
	struct node
	{
		T data;
		node* parent;
		int rank;
	};

public:
	~disjoint_sets ()
	{
	}
	void make_set (T& val)
	{
		node* set = new node();
		set->data = val;
		set->parent = set;
		set->rank = 0;

		sets[val] = set;
	}

	bool union_set (T& val_1, T& val_2)
	{
		node* par_1 = find_set (sets[val_1]);
		node* par_2 = find_set (sets[val_2]);

		if (par_1 == par_2)
			return false;

		if (par_1->rank >= par_2->rank)
		{
			par_2->parent = par_1;
			par_1->rank = (par_1->rank == par_2->rank)
						   ? par_1->rank + 1
						   : par_1->rank;
		}
		else
		{
			par_1->parent = par_2;
		}

		return true;
	}

	T find_set (T& val)
	{
		node* parent = find_set (sets[val]);
		return parent->data;

	}

private:
	node* find_set (node* set)
	{
		if (set != set->parent)
			set->parent = find_set (set->parent);
		return set->parent;
	}

	map <T, node*> sets;
	//shared_ptr<int> foo;
};