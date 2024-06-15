/*
 * browser.cpp
 * Written by : Min Thu Khaing (c3489993)
 * Modified   : 16/06/2024
 *
 * This class represents the implementation for a simple web browser. It uses a LinkedList to store the history and bookmarks.
 * This file should be used in conjunction with Assignment 1 for SENG1120.
 */

#include "browser.h"

/**
 * @brief      Initializes the browser with a homepage, defaulting to newcastle.edu.au.
 * Sets a limit for the number of entries in the history.
 *
 * @param homepage  The homepage of the browser
 * @param history_limit  The maximum number of history entries to store
 * Precondition:  None
 * Postcondition: All required variables are initialised, with the homepage added to the history.
 */
Browser::Browser(const std::string &homepage, int history_limit) : history_limit(history_limit), homepage(homepage) // I don't know if this is allowed or not,
// coz we are not allowed to change the constructor signature
// but I have to initialize the variables
// and cannot use this->homepage = homepage; in the constructor body
{
    history = new LinkedList<std::string>();
    bookmarks = new LinkedList<std::string>();

    history->push_back(homepage);
    history->end(); // Not necessary, but just to be sure
}

/**
 * @brief Destroy the Browser:: Browser object
 *
 * Precondition:    None
 * Postcondition:   The Browser is destroyed and all associated memory is freed.
 */
Browser::~Browser()
{
    // free memory
    delete history;
    delete bookmarks;

    // set pointers to null
    // to avoid dangling pointers
    history = nullptr;
    bookmarks = nullptr;
}

/**
 * @brief Return a reference to the current site, as a string.
 *
 * @return const std::string&   The current site
 * Precondition:    None
 * Postcondition:   None
 */
const std::string &Browser::get_current_site()
{
    return (history->get_current());
}

/**
 * @brief Visits url from the current page, placing it at the end of the history.
 * There should be no forward history.
 * Removes the oldest entry if > limit.
 * Ensure that the current pointer of the history list is pointing to the URL we are visiting!
 *
 * @param url   The URL to visit
 * Precondition:   url is a valid string, with no spaces. 
 * Postcondition:  The current site is updated to url, with no forward history. The oldest history element is removed if the history limit is exceeded.
 */
void Browser::visit(const std::string &url)
{
    // Remove the oldest entry if limit exceeded
    if (history->size() >= history_limit)
        history->pop_front();
    history->push_back(url);
    history->end(); // Not necessary, but just to be sure
}

/**
 * @brief Move back (toward the tail) in history by the specified number of steps.
 * If you can only move backward x steps in the history and steps > x, you will move back only x steps.
 * Forward history should be retained.
 *
 * @param steps  The number of steps to move back in history.
 * Precondition:    None
 * Postcondition:   The history has been moved backwards by <= x steps. Forward history is retained.
 */
void Browser::back(int steps)
{
    // go back steps times
    // if previous site is the first site in history, stop

    for (int i = 0; i < steps; ++i)
    {
        if (history->get_current() == history->front())
            break;
        history->backward();
    }
}

/**
 * @brief Move forward (toward the head) in history by the specified number of steps.
 * If you can only move forward x steps in the history and steps > x, you will move forward only x steps.
 * Backward history should be retained.
 *
 * @param steps The number of steps to move forward in history.
 * Precondition:    None
 * Postcondition:   The history has been moved forwards by <= x steps. Backward history is retained.
 */
void Browser::forward(int steps)
{
    // go forward steps times
    // if next site is the last site in history, stop

    for (int i = 0; i < steps; ++i)
    {
        if (history->get_current() == history->back())
            break;
        history->forward();
    }
}

/**
 * @brief Remove all history entries for the given URL.
 * Return the number of entries that were deleted.
 * Current should point to the last (tail) element in the list.
 *
 * @param url   The URL to remove from history.
 * @return int  The number of elements deleted.
 * Precondition:    A valid url is supplied.
 * Postcondition:   All history elements for the given URL are deleted from the history. Current should point to the last (tail) element in the history. The number of elements deleted is returned.
 */
int Browser::remove(std::string url)
{
    int count = 0;
    history->begin();
    while (history->search(url))
    {
        history->remove();
        count++;
    }
    if (history->empty())
        visit(homepage); // if history is empty, visit homepage
    else
        history->end(); // else, visit the last site in history
    return (count);
}

/**
 * @brief Bookmark the current page.
 * If it is already bookmarked, it should be removed from the list of bookmarks.
 *
 * Precondition:    None
 * Postcondition:   The bookmark list is updated by adding or removing the current site, as appropriate.
 */
void Browser::bookmark_current()
{
    std::string current_site = get_current_site();
    if (bookmarks->search(current_site))
    {
        bookmarks->remove();
        std::cout << get_current_site() << " was removed from Bookmarks." << std::endl;
    }
    else
    {
        bookmarks->push_back(current_site);
        std::cout << get_current_site() << " was added to Bookmarks." << std::endl;
    }
}

/**
 * @brief Clear all history elements and visit the homepage.
 *
 * Precondition:    None
 * Postcondition:   The history is cleared and the current site/history are updated to the homepage.
 */
void Browser::clear_history()
{
    if (history->empty())
    {
        std::cout << "History is empty." << std::endl;
        return;
    }
    history->clear();
    visit(homepage);
}

/**
 * @brief Prints the bookmark list, in the order they were added (i.e., oldest entry first), one entry per line.
 * The current pointer of the bookmark list should be the first (head) element. If no elements are present, prints 'Bookmark list is empty.'
 *
 * Precondition:    None
 * Postcondition:   The bookmark list pointer is modified to point to the first (head) element in the list.
 */
void Browser::print_bookmarks()
{
    if (bookmarks->empty())
        std::cout << "Bookmark list is empty." << std::endl;
    else
    {
        bookmarks->begin();
        for (int i = 0; i < bookmarks->size(); ++i)
        {
            std::cout << bookmarks->get_current() << std::endl;
            bookmarks->forward();
        }
    }
}

/**
 * @brief Return the number of elements in the history list.
 *
 * @return int  The number of elements in the history list.
 * Precondition:    None
 * Postcondition:   No changes have been made to the class.
 */
int Browser::count_history() const
{
    return (history->size());
}

/**
 * @brief Return the number of elements in the bookmark list.
 *
 * @return int The number of elements in the bookmark list.
 * Precondition:    None
 * Postcondition:   No changes have been made to the class.
 */
int Browser::count_bookmarks() const
{
    return (bookmarks->size());
}

/**
 * @brief Visit the entry in the bookmark list at the specified index.
 * This should use the visit function.
 * If the index is not valid, it should print an error message of 'Invalid index. Current site has not been updated.'
 *
 * @param index The index of the bookmark to visit.
 * Precondition:    None
 * Postcondition:   The element at the specified index in the bookmark list is visited, otherwise an error message is printed.
 */
void Browser::visit_bookmark(int index)
{
    // remove the comment below if u want non-programmer friendly index
    //    index--; // Convert to 0-based index
    if (index < 0 || index >= bookmarks->size())
    {
        std::cout << "Invalid index. Current site has not been updated." << std::endl;
        return;
    }
    bookmarks->begin();
    for (int i = 0; i < index; ++i)
        bookmarks->forward();
    visit(bookmarks->get_current());
}