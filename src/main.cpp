#include "deque.h"
#include "test_runner.h"

void TestDeque() {
	Deque<int> d;
	ASSERT(d.Empty());
	d.PushBack(5);
	ASSERT_EQUAL(d.Size(), 1u);
	ASSERT_EQUAL(d[0u], 5);
	bool catched_out_of_range = false;
	try {
		d.At(2);
	} catch (const std::out_of_range &e) {
		catched_out_of_range = true;
	}
	ASSERT(catched_out_of_range);
	d.PushFront(6);
	ASSERT_EQUAL(d[0u], 6);
	ASSERT_EQUAL(d.At(0u), 6);
	ASSERT_EQUAL(d.At(1u), 5);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestDeque);
	return 0;
}
