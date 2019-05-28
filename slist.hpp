#pragma once

#include "slist.h"
#include <assert.h>

template <typename T>
SList<T>::SList() :m_head(nullptr), m_size(0)
{

}

template <typename T>
SList<T>::~SList()
{
	makeEmpty();
}

template <typename T>
bool SList<T>::isEmpty() const 
{
	return m_head == nullptr;
}

template <typename T>
size_t SList<T>::size() const
{
	return m_size;
}

template <typename T>
void SList<T>::insert(const T& val, size_t pos)
{
	assert(pos > 0 && (pos - 1) <= m_size);
	if (pos == 1)
	{
		push_front(val);
	}
	else
	{
		Node* temp = new Node(nullptr, val);
		Node* current = m_head;
		Node* prev = nullptr;
		for(size_t i = 0; i < (pos - 1); ++i)
		{
			prev = current;
			current = current->next;
			if (current == nullptr)
				break;
		}
		temp->next = current;
		prev->next = temp;
		++m_size;
	}
}

template <typename T>
void SList<T>::push_front(const T& val)
{
	Node* temp = new Node(nullptr,val);
	if (isEmpty())
	{
		m_head = temp;
		++m_size;
	}
	else
	{
		temp->next = m_head;
		m_head = temp;
		++m_size;
	}
}

template <typename T>
void SList<T>::erase(const size_t& pos)
{
	assert(!isEmpty());
	assert(pos > 0 && (pos - 1) <= m_size);
	if (pos == 1)
	{
		pop_front();
	}
	else
	{
		Node* current = m_head;
		Node* prev = nullptr;
		for (size_t i = 0; current != nullptr && i < (pos - 1); ++i)
		{
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
		delete current;
		current = nullptr;
		--m_size;
	}
}

template <typename T>
void SList<T>::pop_front()
{
	assert(!isEmpty());
	Node* temp = m_head;
	m_head = m_head->next;
	delete temp;
	temp = nullptr;
	--m_size;
}

template <typename T>
void SList<T>::makeEmpty()
{
	while (!isEmpty())
	{
		pop_front();
	}
}

template <typename T>
const T& SList<T>::get(const size_t& pos)
{
	assert(!isEmpty());
	assert(pos > 0 && pos <= m_size);
	Node* current = m_head;
	for (size_t i = 0; i < (pos - 1); ++i)
	{
		current = current->next;
	}
	return current->value;
}
