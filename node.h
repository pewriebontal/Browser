/*
* node.h
* Written by : SENG1120 Staff (c1234567)
* Modified   : 03/08/2023
*
* This class represents the header for a templated Node class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 


#ifndef SENG1120_NODE_H
#define SENG1120_NODE_H

template <typename T>
class Node
{
public:
	
	/*
    * Precondition:    None
    * Postcondition:   A new Node is created with default data, next and prev are initialised.
    */
	Node();

	/*
    * Precondition:    None
    * Postcondition:   A new Node is created with the supplied data, next and prev are initialised.
    */
	Node(const T& new_data);

	/*
    * Precondition:    None
    * Postcondition:   The Node is destroyed and all associated memory is freed.
    */
	~Node();
	
	/*
    * Precondition:    The supplied Node is valid.
    * Postcondition:   The next pointer has been set to the supplied Node.
    */
	void set_next(Node<T>* const node);

	/*
    * Precondition:    The supplied Node is valid.
    * Postcondition:   The prev pointer has been set to the supplied Node.
    */
	void set_prev(Node<T>* const node);

	/*
    * Precondition:    The supplied data is valid.
    * Postcondition:   The data variable has been set to the supplied value.
    */
	void set_data(T& new_data); 

	/*
    * Precondition:    The next pointer has been initialised.
    * Postcondition:   The value of the next pointer is returned.
    */
	Node<T>* get_next();

	/*
    * Precondition:    The prev pointer has been initialised.
    * Postcondition:   The value of the prev pointer is returned.
    */
	Node<T>* get_prev();

	/*
    * Precondition:    The data item has been initialised.
    * Postcondition:   A reference to the data item is returned.
    */
	T& get_data();

	
	/*
    * Precondition:    The next pointer has been initialised.
    * Postcondition:   The value of the next pointer is returned, as const.
    */
	const Node<T>* get_next() const;

	/*
    * Precondition:    The prev pointer has been initialised.
    * Postcondition:   The value of the prev pointer is returned, as const.
    */
	const Node<T>* get_prev() const;

	/*
    * Precondition:    The data item has been initialised.
    * Postcondition:   A const reference to the data item is returned.
    */
	const T& get_data() const;
	
private: 
	T data;          // Data stored in the node
	Node<T>* next;   // The pointer to the next node in the linked list
	Node<T>* prev;   // The pointer to the previous node in the linked list
};

#include "node.hpp"

#endif
