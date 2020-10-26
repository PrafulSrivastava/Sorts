#pragma once
#include "Global.h"

typedef pair<pair<int, int>, pair<int, int>> start_end_pair;
template <typename T>
class Quicksort {
public:
	static start_end_pair pivot_positioning(vector<T>& v, int pivot_pos, int extent) {
		int i = pivot_pos + 1;
		int j = extent - 1;
		while (i <= j) {
			if (v[i] > v[pivot_pos]) {
				if (v[j] < v[pivot_pos]) {
					Utility<T>::swap(v[i], v[j]);
				}
				else
					j--;
			}
			else
				i++;
		}
		Utility<T>::swap(v[pivot_pos], v[j]);
		return { {pivot_pos, j},{j + 1,extent} };
	}

	static void sort(vector<T>& v) {
		stack<pair<int, int>> st;
		st.push(pair<int, int>(0, v.size()));
		while (!st.empty()) {
			auto top = st.top();
			st.pop();
			auto start_end = pivot_positioning(v, top.first, top.second);
			if (start_end.first.first < start_end.first.second) {
				st.push(start_end.first);
			}
			if (start_end.second.first < start_end.second.second) {
				st.push(start_end.second);
			}
		}
	}
};