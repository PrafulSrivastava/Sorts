#include <iostream>
#include <vector>
#include <map>
using namespace std;

static int cnt = 0;
static map<int, int> mp;
int recursive_nth_fibonaci_element(int n) {
	cnt++;
	if ((n == 1) || (n == 2))
		return 1;
	if (n <= 0) {
		return 0;
	}
	return recursive_nth_fibonaci_element(n - 1) + recursive_nth_fibonaci_element(n - 2);
}

int optimised_recursive_nth_fibonaci_element(int n) {
	int a, b;
	cnt++;
	if ((n == 1) || (n == 2))
		return 1;
	if (n <= 0) {
		return 0;
	}
	if (mp.find(n - 1) != mp.end()) {
		a = mp.find(n - 1)->second;
	}
	else {
		a = optimised_recursive_nth_fibonaci_element(n - 1);
		mp[n - 1] = a;
	}
	if (mp.find(n - 2) != mp.end()) {
		b = mp.find(n - 2)->second;
	}
	else {
		b = optimised_recursive_nth_fibonaci_element(n - 2);
		mp[n - 2] = b;
	}
	mp[n] = a + b;
	return a + b;
}

int main() {
	int n = 40;
	cout<<"Recursion : " << recursive_nth_fibonaci_element(n) << endl;
	cout << "No. of recursive calls : " << cnt << endl;
	cnt = 0;
	cout<<"Memoizaton : " << optimised_recursive_nth_fibonaci_element(n) << endl;
	cout << "No. of recursive calls : " << cnt << endl;
	return 0;
}
