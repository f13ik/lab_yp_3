#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int f(vector<int> lst,int n) {
	int res = 0, sum = 0, total = 0;
	for (int i = 0; i < n; i++) {
		sum += lst[i];
	}
	total = sum;
	sum /= 2;
	vector<bool> ox(sum + 1, false);
	ox[0] = true;

	for (int i : lst) {
		for (int j = sum; j >= i; j--) {
			ox[j] = ox[j] || ox[j - i];
		}
	}
	for (int i = sum; i >= 0; i--) {
		if (ox[i]) {
			res = total - 2 * i;
			break;
		}
	}
	return res;

}
int test() {
	vector<int> lst_t1 = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	vector<int> lst_t2 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
	vector<int> lst_t3 = { 100, 200, 150 };
	int n_t1 = 31, n_t2 = 32, n_t3 = 3;
	if (f(lst_t1, n_t1) == 70) cout << "test 1 passed" << endl;
	if (f(lst_t2, n_t2) == 0) cout << "test 2 passed" << endl;
	if (f(lst_t3, n_t3) == 50) cout << "test 3 passed" << endl;
	return 0;
}
int main() {
	int n;
	scanf_s("%d", &n);
	vector<int> lst(n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &lst[i]);
	}
	cout << f(lst, n) << endl << test();
	return 0;
}