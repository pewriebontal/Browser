/*
 * LinkedList.hpp
 * Written by : SENG1120 Staff (c1234567)
 * Modified   : 03/08/2023
 *
 * This class represents the template implementation for a LinkedList class.
 * This file should be used in conjunction with Assignment 1 for SENG1120.
 */

/**
 * @brief Construct a new Linked List< T>:: Linked List object
 *
 * @tparam T
 * Precondition:    None
 * Postcondition:   A new LinkedList is created, with all variables initialised.
 */
template <typename T>
LinkedList<T>::LinkedList()
{
	head = new Node<T>();
	tail = new Node<T>();

	head->set_next(tail);
	tail->set_prev(head);

	current = head;
	count = 0;
}

/**
 * @brief Destroy the Linked List< T>:: Linked List object
 *
 * @tparam T
 * Precondition:    None
 * Postcondition:   The LinkedList is destroyed and all associated memory is freed.
 */
template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
	delete head;
	delete tail;

	head = nullptr; // set to null to avoid dangling pointers
	tail = nullptr; // same as above
}

/**
 * @brief Insert a node at the front of the list
 *
 * @tparam T
 * @param data
 * Precondition:    The supplied data is valid.
 * Postcondition:   The first data item is updated and current points to the new node.
 */
template <typename T>
void LinkedList<T>::push_front(const T &data)
{
	// [head] -> [next]
	// [head] -> [new_node] -> [next]

	current = head->get_next();
	insert(data);
}

/**
 * @brief Insert a node at the back of the list
 *
 * @tparam T
 * @param data
 * Precondition:    The supplied data is valid.
 * Postcondition:   The last data item is updated and current points to the new node.
 */
template <typename T>
void LinkedList<T>::push_back(const T &data)
{
	// [prev] -> [tail]
	// [prev] -> [new_node] -> [tail]

	current = tail;
	insert(data);
}

/**
 * @brief Insert a node before the current node
 *
 * @tparam T
 * @param data
 * Precondition:    Current points to the node after the insertion point.
 * Postcondition:   A new node has been added and current points to the new node.
 */
template <typename T>
void LinkedList<T>::insert(const T &data)
{
	Node<T> *new_node = new Node<T>(data);
	new_node->set_next(current);
	new_node->set_prev(current->get_prev());
	current->get_prev()->set_next(new_node);
	current->set_prev(new_node);
	current = new_node;
	++count;
}

/**
 * @brief Remove and return the front node's data
 *
 * @tparam T
 * @return T
 * Precondition:    The list is not empty.
 * Postcondition:   The first data element has been removed, reducing the count of Nodes by 1. Current points to head.
 */
template <typename T>
T LinkedList<T>::pop_front()
{
	if (empty())
		throw empty_collection_exception();
	current = head->get_next();
	return (remove());
}

/**
 * @brief Remove and return the last node's data
 *
 * @tparam T
 * @return T
 * Precondition:    The list is not empty.
 * Postcondition:   The last data element has been removed, reducing the count of Nodes by 1. Current points to head.
 */
template <typename T>
T LinkedList<T>::pop_back()
{
	if (empty())
		throw empty_collection_exception();
	current = tail->get_prev();
	return (remove());
}

/**
 * @brief Remove and return the current node's data
 *
 * @tparam T
 * @return T
 * Precondition:    The list is not empty and the current pointer is not pointing to a sentinel node.
 * Postcondition:   The data element pointed to by current has been removed, reducing the count of Nodes by 1. Current points to head.
 */
template <typename T>
T LinkedList<T>::remove()
{
	if (empty() || current == head || current == tail)
		throw empty_collection_exception();
	Node<T> *to_delete = current;
	T data = to_delete->get_data();
	to_delete->get_prev()->set_next(to_delete->get_next());
	to_delete->get_next()->set_prev(to_delete->get_prev());
	current = head;
	delete to_delete;
	--count;
	return (data);
}

/**
 * @brief Clear all nodes from the list
 *
 * @tparam T
 * Precondition:    None
 * Postcondition:   All data elements have been removed. Sentinels should not be removed. Count should be reset.
 */
template <typename T>
void LinkedList<T>::clear()
{
	while (head->get_next() != tail)
		pop_front();
}

/**
 * @brief Return the data from the front node
 *
 * @tparam T
 * @return T&
 * Precondition:    The list is not empty.
 * Postcondition:   A reference to the first data element is returned.
 */
template <typename T>
T &LinkedList<T>::front() const
{
	if (empty())
		throw empty_collection_exception();
	return (head->get_next()->get_data());
}

/**
 * @brief Return the data from the back node
 *
 * @tparam T
 * @return T&
 * Precondition:    The list is not empty.
 * Postcondition:   A reference to the last data element is returned.
 */
template <typename T>
T &LinkedList<T>::back() const
{
	if (empty())
		throw empty_collection_exception();
	return (tail->get_prev()->get_data());
}

/**
 * @brief Return the data from the current node
 *
 * @tparam T
 * @return T&
 * Precondition:    The list is not empty and the current pointer is not pointing to a sentinel node.
 * Postcondition:   A reference to the current data element is returned.
 */
template <typename T>
T &LinkedList<T>::get_current() const
{
	if (empty() || current == head || current == tail)
		throw empty_collection_exception();
	return (current->get_data());
}

/**
 * @brief Set current to the first node
 *
 * @tparam T
 * Precondition:    None
 * Postcondition:   The current pointer is set to the node after head.
 */
template <typename T>
void LinkedList<T>::begin()
{
	current = head->get_next();
}

/**
 * @brief Set current to the last node
 *
 * @tparam T
 * Precondition:    None
 * Postcondition:   The current pointer is set to the node before tail.
 */
template <typename T>
void LinkedList<T>::end()
{
	current = tail->get_prev();
}

/**
 * @brief Move current to the next node
 *
 * @tparam T
 * Precondition:    None
 * Postcondition:   The current pointer is set to the next node, if applicable.
 */
template <typename T>
void LinkedList<T>::forward()
{
	if (current != tail)
		current = current->get_next();
}

/**
 * @brief Move current to the previous node
 *
 * @tparam T
 * Precondition:    None
 * Postcondition:   The current pointer is set to the previous node, if applicable.
 */
template <typename T>
void LinkedList<T>::backward()
{
	if (current != head)
		current = current->get_prev();
}

/**
 * @brief Return the number of nodes in the list
 *
 * @tparam T
 * @return int
 * Precondition:    None
 * Postcondition:   The number of (true) nodes is returned.
 */
template <typename T>
int LinkedList<T>::size() const
{
	return (count);
}

/**
 * @brief Return true if the list is empty, false otherwise
 *
 * @tparam T	Type of data stored in the list
 * @return bool		True if the list is empty, false otherwise
 * Precondition:    None
 * Postcondition:   None
 */
template <typename T>
bool LinkedList<T>::empty() const
{
	return (count == 0);
}

/**
 * @brief Search for a node with the given data and set current to it
 *
 * @tparam T 		Type of data to search for
 * @param target 	Data to search for
 * @return bool     True if the data was found, false otherwise
 * Precondition:    None
 * Postcondition:   current points to the first node storing the target, and true is returned.
 */
template <typename T>
bool LinkedList<T>::search(const T &target)
{
	Node<T> *temp = head->get_next();
	while (temp != tail)
	{
		if (temp->get_data() == target)
		{
			current = temp;
			return (true);
		}
		temp = temp->get_next();
	}
	return (false);
}