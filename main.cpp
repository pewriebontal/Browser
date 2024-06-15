/*
* main.cpp
* Written by : SENG1120 Staff (c1234567)
* Modified   : 03/08/2023
*
* This class represents the main driver for a playlist program.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>

#include "browser.h"

/*
* Display a welcome message.
*/
static void show_welcome() 
{
    std::cout
    << "===========================[ Browser ]=========================" << std::endl 
    << "                 Welcome to the SENG1120 Browser!              " << std::endl 
    << "                 Enter ? for a list of commands.               " << std::endl 
    << "===============================================================" << std::endl
    << std::endl;
}

/*
* Display a the help menu.
*/
void show_help()
{
    std::cout
    << "============================================[ Commands ]============================================" << std::endl 
    << "  v [url]" << std::endl 
    << "      Visit the specified URL." << std::endl 
    << "  < [steps]" << std::endl 
    << "      Move backward the specified number of steps." << std::endl 
    << "  > [steps]" << std::endl 
    << "      Move forward the specified number of steps." << std::endl 
    << "  r [url]" << std::endl 
    << "      Remove all history entries for the given URL." << std::endl 
    << "  b" << std::endl 
    << "      Bookmark/unbookmark the current URL. " << std::endl 
    << "  c" << std::endl 
    << "      Clear the history, resetting to the homepage." << std::endl 
    << "  p" << std::endl 
    << "      Prints the bookmark list." << std::endl 
    << "  H" << std::endl 
    << "      Counts the number of elements in the history list." << std::endl 
    << "  B" << std::endl 
    << "      Counts the number of elements in the bookmark list." << std::endl 
    << "  V [index]" << std::endl 
    << "      Visits the bookmark with specified index, if it exists." << std::endl 
    << "  q" << std::endl 
    << "      Quit." << std::endl 
    << "  ?" << std::endl 
    << "      Show this help menu." << std::endl 
    << "=====================================================================================================" << std::endl ;
}

/*
* Present the user with a prompt, returning the user's input command
*/
std::string prompt() 
{
    std::string command;
    std::cout << "Enter command: ";
    //read entire line from cin, not just next token
    std::getline(std::cin, command);

    return command;
}

/*
* Break a command into a vector of tokens (i.e., split by space)
*/
std::vector<std::string> parse_command(const std::string& command)
{
    std::vector<std::string> tokens;

    std::istringstream iss(command);
    std::string s;

    while (std::getline(iss, s, ' ')) 
    {
        tokens.push_back(s);
    }

    return tokens;
}

/*
* Return the integer for a command of the form <command> <integer>.
*/
int parse_int_command(const std::string& command)
{
    std::vector<std::string> tokens = parse_command(command);
    if (tokens.size() != 2) 
    {
        throw std::invalid_argument("Invalid command. Command must have only 2 tokens, you provided: " + tokens.size());
    }

    try
    {
        //tokens[0] is the command, which we can ignore
        int value = std::stoi(tokens[1]);
        return value;
    }
    catch(std::exception& e)
    {
        throw std::invalid_argument("Error parsing integer in command.");
    }
    
}

/*
* Return the integer for a command of the form <command> <integer>.
*/
std::string parse_string_command(const std::string& command)
{
    std::vector<std::string> tokens = parse_command(command);
    if (tokens.size() != 2) 
    {
        throw std::invalid_argument("Invalid command. Command must have only 2 tokens, you provided: " + tokens.size());
    }

    //tokens[0] is the command, which we can ignore
    return tokens[1];    
}

/*
* Helper method to determine the method to execute based on the command.
* The return value determines whether to continue execution.
*/
bool execute_command(Browser& browser, const std::string& command)
{
    char cmd = command[0]; //the first character is the command code

    switch (cmd)
    {
    case 'v':
        try
        {
            std::string url = parse_string_command(command);
            browser.visit(url);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case '<':
        try
        {
            int steps = parse_int_command(command);
            browser.back(steps);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case '>':
        try
        {
            int steps = parse_int_command(command);
            browser.forward(steps);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 'r':
        try
        {
            std::string url = parse_string_command(command);
            browser.remove(url);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 'b':
        browser.bookmark_current();
        break;
    case 'c':
        browser.clear_history();
        break;
    case 'p':
        browser.print_bookmarks();
        break;
    case 'H':
        std::cout << "Number of elements in history: " << browser.count_history() << std::endl;
        break;
    case 'B':
        std::cout << "Number of elements in bookmarks: " << browser.count_bookmarks() << std::endl;
        break;
    case 'V':
        try
        {
            int index = parse_int_command(command);
            browser.visit_bookmark(index);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 'q':
        return false; //used to flag that we want to exit
        break;
    case '?':
        show_help();
        break;
    default:
        std::cout << "Unknown command: " << command << std::endl;
        break;
    }

    return true;
}

/*
* Run the program in prompt (interactive) mode, where the commands are supplied by the user.
*/
void run_prompt_mode()
{
    show_welcome();

    Browser browser;

    bool do_continue = true;
    // Here, we have a valid reason for a do-while loop
    // This is because we want to always display the prompt at least once
    // and continue only if we didn't use quit!
    do
    {
        //write the current site, prompt, execute, write newline
        std::cout << "Current site: " << browser.get_current_site() << std::endl;
        std::string command = prompt();
        do_continue = execute_command(browser, command);
        std::cout << std::endl;
    } while(do_continue);
}

/*
* Run the program in file mode, where the input commands are read from a file.
*/
void run_file_mode(char* file_name)
{
    Browser browser;

    std::ifstream infile(file_name);
    std::string command;

    bool do_continue = true;
    //exit if we run out of lines, or encounter the quit command
    while(std::getline(infile, command) && do_continue)
    {
        std::cout << "Current site: " << browser.get_current_site() << std::endl;
        //remove the newline character
        command = command.substr(0, command.length() - 1);
        std::cout << "Executing command: " << command << std::endl;
        do_continue = execute_command(browser, command);
        std::cout << std::endl;
    }

    std::cout << "Current site: " << browser.get_current_site() << std::endl;
}

/*
* The main method. When no arguments are supplied, run in interactive mode. 
* When one argument is supplied, it is assumed to be a valid file of commands, one per line.
*/
int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        std::cout << "Using file " << argv[1] << " as input." << std::endl << std::endl;
        run_file_mode(argv[1]);
    }
    else
    {
        run_prompt_mode();
    }

    std::cout << "Goodbye!" << std::endl;
    
    return 0;
}