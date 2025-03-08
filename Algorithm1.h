#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <stdexcept>

//Include priority queue and make priority queue object, allow it to be used as a stack and queue
//Use priority queue class and make a new class that handles stacks and queues.
//Make object for priority queue class that's prebuilt, automatically does max_heap.
//
using namespace std;

enum class Mode { PRIORITY, STACK, QUEUE };

template <class T>

class PriorityQueue
{
private:
	Mode mode;
	std::priority_queue<std::tuple<int, int, T>> maxHeap;
	std::stack<T> stack;
	std::queue<T> queue;
	int order;

public:

	PriorityQueue(Mode mode) : mode(mode), order(0) {}

	void push(const T& item, int priority = 0)
	{
		if (mode == Mode::PRIORITY)
		{
			maxHeap.push({priority, order++, item });
		}
		else if (mode == Mode::STACK)
		{
			stack.push(item);
		}
		else if (mode == Mode::QUEUE)
		{
			queue.push(item);
		}
	}

	//Pop functions w/ Edge Case Handling
	T pop()
	{
		if (is_empty())
		{
			throw std::range_error("Queue is empty.");
		}

		if (mode == Mode::PRIORITY)
		{
			T item = std::get<2>(maxHeap.top());
			maxHeap.pop();
			return item;
		}

		else if (mode == Mode::STACK)
		{
			T item = stack.top();
			stack.pop();
			return item;
		}

		else if (mode == Mode::QUEUE)
		{
			T item = queue.front();
			queue.pop();
			return item;
		}
	}

	//If_empty() to show if the queue is empty
	bool is_empty() const
	{
		if (mode == Mode::PRIORITY)
		{
			return maxHeap.empty();
		}

		else if (mode == Mode::STACK)
		{
			return stack.empty();
		}

		else if (mode == Mode::QUEUE)
		{
			return queue.empty();
		}

		return true;
	}
};
