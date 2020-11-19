#pragma once

#include <vector>

template<typename T>
class Deque {
public:
	Deque() {
	}

	const T& operator[](const size_t index) const {
		if (index < front.size()) {
			return front[front.size() - index - 1];
		} else {
			return back[index - front.size()];
		}
	}

	T& operator[](const size_t index) {
		if (index < front.size()) {
			return front[front.size() - index - 1];
		} else {
			return back[index - front.size()];
		}
	}

	size_t Size() const {
		return front.size() + back.size();
	}

	T& At(size_t index) {
		if (index < front.size()) {
			return front.at(front.size() - index - 1);
		} else {
			return back.at(index - front.size());
		}
	}

	const T& At(size_t index) const {
		if (index < front.size()) {
			return front.at(front.size() - index - 1);
		} else {
			return back.at(index - front.size());
		}
	}

	bool Empty() const {
		return front.empty() && back.empty();
	}

	void PushFront(const T &el) {
		front.push_back(el);
	}

	void PushBack(const T &el) {
		back.push_back(el);
	}

	const T& Front() const {
		if (front.empty()) {
			return back.front();
		} else {
			return front.back();
		}
	}

	T& Front() {
		if (front.empty()) {
			return back.front();
		} else {
			return front.back();
		}
	}

	const T& Back() const {
		if (back.empty()) {
			return front.front();
		} else {
			return back.back();
		}
	}

	T& Back() {
		if (back.empty()) {
			return front.front();
		} else {
			return back.back();
		}
	}

private:
	std::vector<T> front, back;
};
