/*
 * Node.hpp
 * Written by : SENG1120 Staff (c1234567)
 * Modified   : 03/08/2023
 *
 * This class represents the template implementation for a Node class.
 * This file should be used in conjunction with Assignment 1 for SENG1120.
 */

/**
 * @brief Construct a new Node< T>:: Node object
 *
 * @tparam T
 */
template <typename T>
Node<T>::Node()
{
    next = nullptr; // set to null to avoid dangling pointers
    prev = nullptr; // same as above
}

/**
 * @brief Construct a new Node< T>:: Node object
 *
 * @tparam T
 * @param new_data
 * Precondition:    None
 * Postcondition:   A new Node is created with the supplied data, next and prev are initialised.
 */

template <typename T>
Node<T>::Node(const T &new_data)
{
    data = new_data;

    next = nullptr; // set to null to avoid dangling pointers
    prev = nullptr; // same as above
}

/*
 * destructor
 * Precondition:    None
 * Postcondition:   The Node is destroyed and all associated memory is freed.
 */
template <typename T>
Node<T>::~Node()
{
    next = nullptr; // set to null to avoid dangling pointers
    prev = nullptr; // same as above
}

// ---- Mutators --------

/*
 * Precondition:    The supplied data is valid.
 * Postcondition:   The data variable has been set to the supplied value.
 */
template <typename T>
void Node<T>::set_data(T &new_data)
{
    data = new_data;
}

/*
 * Precondition:    The supplied Node is valid.
 * Postcondition:   The next pointer has been set to the supplied Node.
 */
template <typename T>
void Node<T>::set_next(Node<T> *const new_next)
{
    next = new_next;
}

/*
 * Precondition:    The supplied Node is valid.
 * Postcondition:   The prev pointer has been set to the supplied Node.
 */
template <typename T>
void Node<T>::set_prev(Node<T> *const new_prev)
{
    prev = new_prev;
}

// ---- Accessors --------

/*
 * Precondition:    The next pointer has been initialised.
 * Postcondition:   The value of the next pointer is returned.
 */
template <typename T>
Node<T> *Node<T>::get_next()
{
    return (next);
}

/*
 * Precondition:    The prev pointer has been initialised.
 * Postcondition:   The value of the prev pointer is returned.
 */
template <typename T>
Node<T> *Node<T>::get_prev()
{
    return (prev);
}

/*
 * Precondition:    The data item has been initialised.
 * Postcondition:   A reference to the data item is returned.
 */
template <typename T>
T &Node<T>::get_data()
{
    return (data);
}

/*
 * Precondition:    The next pointer has been initialised.
 * Postcondition:   The value of the next pointer is returned, as const.
 */
template <typename T>
const Node<T> *Node<T>::get_next() const
{
    return (next);
}

/*
 * Precondition:    The prev pointer has been initialised.
 * Postcondition:   The value of the prev pointer is returned, as const.
 */
template <typename T>
const Node<T> *Node<T>::get_prev() const
{
    return (prev);
}

/*
 * Precondition:    The data item has been initialised.
 * Postcondition:   A const reference to the data item is returned.
 */
template <typename T>
const T &Node<T>::get_data() const
{
    return (data);
}