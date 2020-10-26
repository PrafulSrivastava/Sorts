#include <iostream>
#include <vector>
#include <stack>
#include "QuickSort.h"





int main() {
	vector<char> v;
	Utility<char>::populate(v);
	Utility<char>::display(v);
	Quicksort<char>::sort(v);
	Utility<char>::display(v);

}