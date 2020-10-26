#include <iostream>
#include <vector>
#include <map>
using namespace std;
static map<int, int> mp;
static map<int, int> mem;
static int cnt = 0;
void take_prices() {
	mp.insert(pair<int, int>(1, 1));
	mp.insert(pair<int, int>(2, 5));
	mp.insert(pair<int, int>(3, 8));
	mp.insert(pair<int, int>(4, 9));
	mp.insert(pair<int, int>(5, 10));
	mp.insert(pair<int, int>(6, 14));
	mp.insert(pair<int, int>(7, 17));
	mp.insert(pair<int, int>(8, 20));
	mp.insert(pair<int, int>(9, 24));
	mp.insert(pair<int, int>(10, 30));
}

//recursion
int cal_max_cost(int len) {
	cnt++;
	int max =mp[len];
	int cur = 0;
	if (len == 0)
		return 0;
	for (int i = 1; i < len; i++) {
		cur = cal_max_cost(i) + cal_max_cost(len - i);
		if (max < cur) {
			max = cur;
		}
	}
	return max;

}

//memoized approach
int cal_max_cost_memoized(int len) {
	cnt++;
	int max = mp[len];
	int cur = 0;
	if (len == 0) {
		mem[len] = 0;
		return 0;
	}
	auto x = mem.find(len);
	if (x != mem.end()) {
		return mem[len];
	}
	for (int i = 1; i < len; i++) {		
		cur = cal_max_cost_memoized(i)+ cal_max_cost_memoized(len - i);
		if (max < cur) {
			max = cur;
		}
	}
	mem[len] = max;
	return max;
}

//dynamic approach
int cal_max_cost_dp(int len) {
	cnt++;
	mem[0] = 0;
	for (int i = 1; i <= len; i++) {
		int max = mp[i];
		int cur = 0;
		for (int j = 1; j < i; j++) {
			cur = mem[j] + mem[i - j];
			if (max < cur)
				max = cur;
		}
		mem[i] = max;
	}
	return mem[len];
}

int main(){
	take_prices();
	int l = 6;
	cout << "Best Cost Recursive: " << cal_max_cost(l) << " in ";
	cout << cnt << " runs" << endl;
	cnt = 0;
	cout << "Best Cost Memoized: " << cal_max_cost_memoized(l) << " in ";
	cout << cnt << " runs" << endl;
	mem.clear();
	cnt = 0;
	cout << "Best Cost Dynamic Programming: " << cal_max_cost_dp(l) << " in ";
	cout << cnt << " runs" << endl;

}