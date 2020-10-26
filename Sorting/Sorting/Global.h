#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
template <typename T>
class Utility {
public :
	static void swap(T& a, T& b) {
		if (a == b) {
			return;
		}
		T c = a;
		a = b;
		b = c;
	}

	template <typename T>
	static void display(const vector<T>& v) {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
	template <typename T>
	static void populate(vector<T>& v) {
		/*v.push_back(1);
		v.push_back(7);
		v.push_back(4);
		v.push_back(3);
		v.push_back(6);
		v.push_back(9);
		v.push_back(8);
		v.push_back(2);
		v.push_back(2);*/
		v.push_back('d');
		v.push_back('a');
		v.push_back('b');
		v.push_back('d');
		v.push_back('f');
		v.push_back('j');
		v.push_back('z');
		v.push_back('e');
		v.push_back('r');
		v.push_back('c');
	}
};