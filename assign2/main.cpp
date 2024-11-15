/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
#include <sstream>

#include "utils.h"

std::string kYourName = "Joe David"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename)
{
    // STUDENT TODO: Implement this function.
    std::ifstream ifs(filename);
    std::unordered_set<std::string> applicant_name_set;

    if (ifs.is_open())
    {
        std::string line;
        while (std::getline(ifs, line))
        {
            applicant_name_set.insert(line);
        }
    }

    return applicant_name_set;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string *> find_matches(std::string name, std::unordered_set<std::string> &students)
{
    // // STUDENT TODO: Implement this function.
    std::queue<const std::string *> applicants_pointer;
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        const auto &elem = *it;

        if (has_same_initial_letter(name, elem))
        {
            applicants_pointer.push(&elem);
        }
    }

    return applicants_pointer;
}

/**
 *
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string *> &matches)
{
    // STUDENT TODO: Implement this function.
    std::string marriage_pact;
    if (matches.empty())
    {
        marriage_pact = "NO MATCHES FOUND.";
    }
    else
    {
        // size_t num = 100 + std::rand() % 200;
        // while (num && !matches.empty())
        // {
        //     matches.pop();
        //     num--;
        // }

        const std::string *marriage_pointer = matches.back();
        marriage_pact = *marriage_pointer;
    }

    return marriage_pact;
}

bool has_same_initial_letter(std::string kYourName, std::string applicant_name)
{
    bool flag = false;
    std::vector<std::string> applicant_name_vec = split(applicant_name, ' ');
    std::vector<std::string> kYourName_vec = split(kYourName, ' ');

    auto it1 = kYourName_vec.begin();
    auto it2 = applicant_name_vec.begin();
    for (; it1 != applicant_name_vec.end(), it2 != applicant_name_vec.end(); ++it1, ++it2)
    {
        const auto& appli = *it1;
        const auto& kyour = *it2;
        if (appli.substr(0, 1) != kyour.substr(0, 1))
        {
            return false;
        }
    }

    return true;
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> return_vec;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delim))
    {
        return_vec.push_back(token);
    }
    return return_vec;
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
