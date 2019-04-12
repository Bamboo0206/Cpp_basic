/*插入set中已有的元素时，忽略插入。*/
#include <iostream>
#include <set>
using namespace std;
int main() {
	typedef set<int>::iterator IT;
	int a[5] = { 3,4,6,1,2 };
	set<int> st(a, a + 5); // st里是1 2 3 4 6
	pair< IT, bool> result;
	result = st.insert(5); // st变成1 2 3 4 5 6
	if (result.second) //插入成功则输出被插入元素
		cout << *result.first << " inserted" << endl; //输出: 5 inserted
	if (st.insert(5).second) cout << *result.first << endl;
	else
		cout << *result.first << " already exists" << endl; //输出5 already exists
	pair<IT, IT> bounds = st.equal_range(4);
	cout << *bounds.first << "," << *bounds.second; //输出：4,5
	return 0;
}