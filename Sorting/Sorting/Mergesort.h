#pragma once
#include "Global.h"

template <typename T>
class Mergesort {
public:
	static vector<T> merge_vectors(vector<T>& v1, vector<T>& v2) {
		vector<T> v_mergerd;
		int i = 0;
		int j = 0;
		while (i < v1.size()) {
			if ((j > v2.size()) || (v1[i] < v2[j])) {
				v_mergerd.push_back(v1[i]);
				i++;
			}
			else {
				v_mergerd.push_back(v2[j]);
				j++;
			}
		}
		if (v_mergerd.size() < v1.size() + v2.size()) {
			while (j < v2.size()) {
				v_mergerd.push_back(v2[j]);
				j++;
			}
		}
		return v_mergerd;
	}
	
	static void sort_iterative(vector<T>& v) {
		
	}
	static vector<T> sort_recursive(vector<T>& v) {
		if (v.size() > 1) {
			vector<T> v1(v.begin(), v.begin() + (v.size() / 2));
			vector<T> v2(v.begin() + (v.size() / 2), v.end());
			auto x = sort_recursive(v1);
			auto y = sort_recursive(v2);

			return Mergesort::merge_vectors(x, y);
		}
		else {
			return v;
		}
	}
};