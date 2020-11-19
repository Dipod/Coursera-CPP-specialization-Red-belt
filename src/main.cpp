#include "test_runner.h"
#include <utility>

using namespace std;

template<typename T>
class Table {
public:
	Table(const size_t &row, const size_t &col) {
		Resize(row, col);
	}

	vector<T>& operator[](const size_t &row) const {
		return table[row];
	}

	vector<T>& operator[](const size_t &row) {
		return table[row];
	}

	void Resize(const size_t &row, const size_t &col) {
		table.resize(row);
		for (auto &table_row : table) {
			table_row.resize(col);
		}
	}

	pair<size_t, size_t> Size() const {
		size_t rows = table.size(), cols = 0;
		if (rows == 0u) {
			return make_pair(rows, cols);
		}
		cols = table[0].size();
		if (cols == 0u) {
			rows = 0;
		}
		return make_pair(rows, cols);
	}

private:
	vector<vector<T>> table;
};

void TestTable() {
	Table<int> t(1, 1);
	ASSERT_EQUAL(t.Size().first, 1u);
	ASSERT_EQUAL(t.Size().second, 1u);
	t[0][0] = 42;
	ASSERT_EQUAL(t[0][0], 42);
	t.Resize(3, 4);
	ASSERT_EQUAL(t.Size().first, 3u);
	ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestTable);
	return 0;
}
