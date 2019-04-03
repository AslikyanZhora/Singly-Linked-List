#pragma once

template <typename T>
class List
{
public:
	List(){}
	virtual ~List(){}
	virtual bool isEmpty() const = 0;
	virtual size_t size() const = 0;
	virtual void insert(const T& val, size_t pos) = 0;
	virtual void push_front(const T& val) = 0;
	virtual void erase(const size_t& pos) = 0;
	virtual void pop_front() = 0;
	virtual void makeEmpty() = 0;
	virtual const T& get(const size_t& pos) = 0;
};