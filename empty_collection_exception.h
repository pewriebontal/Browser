/*
* empty_collection_exception.h
* Written by : SENG1120 Staff (c1234567)
* Modified : 04/04/2024
*
* This class represents a custom exception that should be thrown when a collection is empty.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/

#ifndef SENG1120_EMPTY_COLLECTION_H
#define SENG1120_EMPTY_COLLECTION_H

#include <exception>
#include <string>

class empty_collection_exception : public std::exception
{
public:
    const char* what() const noexcept override 
    { 
        return "Collection is empty."; 
    }
};

#endif