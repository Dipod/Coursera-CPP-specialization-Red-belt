#include "test_runner.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

class RouteManager {
public:
	void AddRoute(int start, int finish) {
		reachable_lists_[start].insert(finish);
		reachable_lists_[finish].insert(start);
	}
	int FindNearestFinish(int start, int finish) const {
		int result = abs(start - finish);
		if (reachable_lists_.find(start) == reachable_lists_.end()) {
			return result;
		}
		const set<int> &reachable_stations = reachable_lists_.at(start);
		if (!reachable_stations.empty()) {
			auto lower_bound = reachable_stations.lower_bound(finish);
			if(lower_bound != reachable_stations.end()){
				result = min(result, abs(finish - *lower_bound));
			}
			if(lower_bound != reachable_stations.begin()){
				result = min(result, abs(finish - *prev(lower_bound)));
			}
		}
		return result;
	}
private:
	map<int, set<int>> reachable_lists_;
};

void TestRouteManager() {

	RouteManager routes;

	routes.AddRoute(-2, 5);
	routes.AddRoute(10, 4);
	routes.AddRoute(5, 8);

	ASSERT_EQUAL(routes.FindNearestFinish(4, 10), 0);
	ASSERT_EQUAL(routes.FindNearestFinish(4, -2), 6);
	ASSERT_EQUAL(routes.FindNearestFinish(5, 0), 2);
	ASSERT_EQUAL(routes.FindNearestFinish(5, 100), 92);
}

int main() {

	TestRunner tr;
	RUN_TEST(tr, TestRouteManager);

	RouteManager routes;

	int query_count;
	cin >> query_count;

	for (int query_id = 0; query_id < query_count; ++query_id) {
		string query_type;
		cin >> query_type;
		int start, finish;
		cin >> start >> finish;
		if (query_type == "ADD") {
			routes.AddRoute(start, finish);
		} else if (query_type == "GO") {
			cout << routes.FindNearestFinish(start, finish) << "\n";
		}
	}

	return 0;
}
