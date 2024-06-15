/*
* Node.hpp
* Written by : SENG1120 Staff (c1234567)
* Modified   : 03/08/2023
*
* This class represents the template implementation for a Node class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

template <typename T>
Node<T>::Node() 
{ 

}

template <typename T>
Node<T>::Node(const T& new_data)
{ 

}

template <typename T>
Node<T>::~Node() 
{

}

// ---- Mutators --------
template <typename T>
void Node<T>::set_data(T& new_data) 
{
    
}

template <typename T>
void Node<T>::set_next(Node<T>* const new_next) 
{
    
}

template <typename T>
void Node<T>::set_prev(Node<T>* const new_prev) 
{
    
}

// ---- Accessors --------
template <typename T>
Node<T>* Node<T>::get_next() 
{
    return nullptr;
}

template <typename T>
Node<T>* Node<T>::get_prev() 
{
    return nullptr;
}

template <typename T>
T& Node<T>::get_data() 
{
    
}

template <typename T>
const Node<T>* Node<T>::get_next() const 
{
    return nullptr;
}

template <typename T>
const Node<T>* Node<T>::get_prev() const 
{
    return nullptr;
}

template <typename T>
const T& Node<T>::get_data() const 
{
    
}