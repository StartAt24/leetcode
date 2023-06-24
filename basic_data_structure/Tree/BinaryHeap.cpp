#pragma once
#include <iostream>
#include <array>

using namespace std;

// Max Heap
template<typename T, int count>
class BinaryHeap {
public:
	BinaryHeap() {
		_cap = count;
	};

	~BinaryHeap() = default;

	// build from another array;
	BinaryHeap(array<T, count> o) {
		_container = o;
		_size = _container.size - 1;
		_cap = _container.max_size() - 1;
		ReBuild();
	}

	T Pop() {
		if (_size == 0)
			throw std::exception("empty heap");
		
		// index starts from 1.
		T ret = _container[1];

		// move last one to top and Sink to form a heap again.
		_container[1] = _container[_size];
		_size--;
		Sink(1);

		return ret;
	}

	void Push(T t) {
		if (_size == _cap - 1)
			throw std::exception("full heap");

		// add to the end
		_size++;
		_container[_size] = t;
		
		// swim up to form a heap again;
		Swim(_size);
	}

	int Size() {
		return _size;
	}

private:
	bool IsEmpty() {
		return _size == 0;
	}

	// target is index, scope is a min tree struct;
	void Swim(int idx) {
		// the parient node is idx/2. idx starting from 1, 2, 3, 4, 5,
		// int divide will ommit the rest value;
		for (int i = idx; i > 1 && _container[i] > _container[i /2]; i /= 2) {
			Swap(i, i / 2);
		}
	}

	/// sink only works when left child tree and right child tree are both heap.
	void Sink(int idx) {
		for (int i = idx, s = biggerSon(i); i <= _size && _container[idx] < _container[s]; i = s, s =biggerSon(i)) {
			Swap(i, s);
		}
	}

	void Swap(int idx1, int idx2) {
		T temp = _container[idx1];
		_container[idx1] = _container[idx2];
		_container[idx2] = temp;
		return;
	}

	// build from the last parient node;
	void ReBuild() {
		auto mini_tree_build = [this](int idx) {
			T current = _container[idx];
			T left_node = _container[idx * 2];

			if (current < left_node) {
				Swap(idx, idx * 2);
				current = left_node;
			}

			// no right child
			if (idx * 2 + 1 > size)
				return;

			const T& right_node = _container[idx * 2 + 1];
			if (current < right_node) {
				Swap(idx, idx * 2 + 1);
			}
			
		};
		for (int i = _size / 2; i > 1; i--) {
			mini_tree_build(i);
		}
	}

	int biggerSon(int idx) {
		T left = _container[idx * 2];
		if (idx * 2 + 1 > _size) {
			return idx * 2;
		}

		T right = _container[idx * 2 + 1];
		return left > right ? idx * 2 : idx * 2 + 1;
	}

private:
	array<T, count+1> _container;
	int _cap = 0;
	int _size = 0;
};