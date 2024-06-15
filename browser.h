/*
* browser.h
* Written by : SENG1120 Staff (c1234567)
* Modified   : 13/03/2024
*
* This class represents a simple browser class, which uses two linked lists to store history and bookmarks.
* This file should be used in conjunction with Assignment 1 for SENG1120/SENG6120.
*/ 

#ifndef SENG1120_BROWSER_H 
#define SENG1120_BROWSER_H 

#include "linked_list.h"
#include <string>
#include <iostream>

class Browser 
{
public:
    /**
     * Initializes the browser with a homepage, defaulting to newcastle.edu.au. 
     * Sets a limit for the number of entries in the history.
     * 
     * Precondition:  None  
     * Postcondition: All required variables are initialised, with the homepage added to the history.
     */ 
    Browser(const std::string& homepage = "newcastle.edu.au", int history_limit = 10);

    /**
     * Destructor for a Browser object.
     * 
     * Precondition:    None
     * Postcondition:   The Browser is destroyed and all associated memory is freed.
     */
    ~Browser();

    /**
     * Return a reference to the current site, as a string.
     * 
     * Precondition:  None   
     * Postcondition: None
     */ 
    const std::string& get_current_site();

    /**
     * Visits url from the current page, placing it at the end of the history.
     * There should be no forward history.
     * Removes the oldest entry if > limit.
     * Ensure that the current pointer of the history list is pointing to the URL we are visiting!
     * 
     * Precondition:   url is a valid string, with no spaces.    
     * Postcondition:  The current site is updated to url, with no forward history. The oldest history element is removed if the history limit is exceeded.
     */ 
    void visit(const std::string& url);

    /**
     * Move back (toward the tail) in history by the specified number of steps. 
     * IIf you can only move backward x steps in the history and steps > x, you will move back only x steps.  
     * Forward history should be retained.
     * 
     * Precondition:  None 
     * Postcondition: The history has been moved backwards by <= x steps. Forward history is retained.
     */ 
   void back(int steps);

    /**
     * Move forward (toward the head) in history by the specified number of steps. 
     * If you can only move forward x steps in the history and steps > x, you will move forward only x steps. 
     * Backward history should be retained.
     * 
     * Precondition:    
     * Postcondition: The history has been moved forwards by <= x steps. Backward history is retained.
     */ 
    void forward(int steps);

    /**
     * Remove all history entries for the given URL. 
     * Return the number of entries that were deleted.
     * Current should point to the last (tail) element in the list.
     * 
     * Precondition:  A valid url is supplied.
     * Postcondition: All history elements for the given URL are deleted from the history. 
     * Current should point to the last (tail) element in the history. 
     * The number of elements deleted is returned.
     */ 
    int remove(std::string url);

    /**
     * Bookmark the current page. 
     * If it is already bookmarked, it should be removed from the list of bookmarks.
     * 
     * Precondition:  None  
     * Postcondition: The bookmark list is updated by adding or removing the current site, as appropriate.
     */ 
    void bookmark_current();

    /**
     * Clear all history elements and visit the homepage.
     * 
     * Precondition:   None.
     * Postcondition:  The history is cleared and the current site/history are updated to the homepage.
     */ 
    void clear_history();

    /**
     * Prints the bookmark list, in the order they were added (i.e., oldest entry first), one entry per line.
     * The current pointer of the bookmark list should be the first (head) element. If no elements are present, prints 'Bookmark list is empty.'
     * 
     * Precondition:   None
     * Postcondition:  The bookmark list pointer is modified to point to the first (head) element in the list.  
     */ 
    void print_bookmarks();

    /**
     * Return the number of elements in the history list.
     * 
     * Precondition:  None
     * Postcondition: No changes have been made to the class.
     */ 
    int count_history() const;

    /**
     * Return the number of elements in the bookmark list.
     * 
     * Precondition:   None
     * Postcondition:  No changes have been made to the class.
     */ 
    int count_bookmarks() const;

    /**
     * Visit the entry in the bookmark list at the specified index.
     * This should use the visit function.
     * If the index is not valid, it should print an error message of 'Invalid index. Current site has not been updated.'
     * 
     * Precondition:  None  
     * Postcondition: The element at the specified index in the bookmark list is visited, otherwise an error message is printed.
     */ 
    void visit_bookmark(int index);
private:
    LinkedList<std::string>* history;     // linked list of history entries, with the most recently visited site at the end (tail) of the list
    LinkedList<std::string>* bookmarks;   // linked list of bookmarks

    int history_limit;                    // the maximum number of elements in the history
    std::string homepage;                 // the homepage of the browser
};

#endif