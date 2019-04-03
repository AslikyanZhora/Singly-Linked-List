#pragma once

#include "list.hpp"

template <typename T>
class SList :public List<T>
{
public:
	SList();
	~SList();
	bool isEmpty() const override;
	size_t size() const override;
	void insert(const T& val, size_t pos) override;
	void push_front(const T& val) override;
	void erase(const size_t& pos) override;
	void pop_front() override;
	void makeEmpty() override;
	const T& get(const size_t& pos) override;
private:
	struct Node
	{
		Node(Node* ptr = nullptr, const T& val = 0) :next(ptr), value(val)
		{

		}
		Node* next;
		T value;
	};
	Node* m_head;
	size_t m_size;
};