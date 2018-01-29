#include <vector>
#include <map>

using namespace std;

template <class T>
class min_heap
{
	struct node
	{
		T name;
		int data;

		node (T name, int data)
			: name (name), data (data){}
	};
public:
	void add (T name, int data)
	{
		node n (name, data);
		_heap.push_back (n);
		names[name] = _heap.size () - 1;
		heapify_up (_heap.size () - 1);
	}

	T extract_min ()
	{
		swap (0, _heap.size () - 1);
		T name = _heap[_heap.size () - 1].name;
		_heap.pop_back ();
		names.erase(names.find (name));
		heapify_down (0);
		return name;
	}

	bool contains (T name)
	{
		return names.find (name) != names.end ();
	}

	void decrease (T name, int new_data)
	{
		int index = names.find (name)->second;
		_heap[index].data = new_data;
		heapify_up (index);
	}

	int data (T name)
	{
		return _heap[names.find (name)->second].data;
	}

	bool empty ()
	{
		return _heap.empty ();
	}

private:
	void heapify_down (int index)
	{
		while (left_child_present (index))
		{
			int smallest_child_index = left_child_index (index);
			if (right_child_present (index)
				&& right_child (index).data < left_child (index).data)
				smallest_child_index = right_child_index (index);
			if (_heap[smallest_child_index].data < _heap[index].data)
			{
				swap (index, smallest_child_index);
				index = smallest_child_index;
			}
			else
			{
				break;
			}
		}
	}

	void heapify_up (int index)
	{
		while (parent_present (index)
			   && _heap[index].data < parent (index).data)
		{
			swap (index, parent_index (index));
			index = parent_index (index);
		}
	}

	bool parent_present (int index)
	{
		return index != 0;
	}

	bool left_child_present (int index)
	{
		return (left_child_index (index) < (int)_heap.size ());
	}

	bool right_child_present (int index)
	{
		return right_child_index (index) < (int)_heap.size ();
	}

	int parent_index (int index)
	{
		return (index - 1) / 2;
	}

	int left_child_index (int index)
	{
		return right_child_index (index) - 1;
	}

	int right_child_index (int index)
	{
		return (index + 1) * 2;
	}

	node& parent (int index)
	{
		return _heap[parent_index(index)];
	}

	node& left_child (int index)
	{
		return _heap[left_child_index(index)];
	}

	node& right_child (int index)
	{
		return _heap[right_child_index(index)];
	}

	void swap (int i, int j)
	{
		names[_heap[i].name] = j;
		names[_heap[j].name] = i;
		
		node t = _heap[i];
		_heap[i] = _heap[j];
		_heap[j] = t;
	}

	vector <node> _heap;
	map <T, int> names;
};