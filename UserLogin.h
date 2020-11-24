#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class UserLogin {
public:
    // Default constructor. Create an empty structure.
    UserLogin();

    // Add data from file to hash table.
    // Return true on success and false on faileure.
    bool ReadIn(const string& filename);

    // return the number of users
    size_t NumberOfUsers();

    // Determine whether the given user name exists.
    // Return true if the given userName exists, or false if it does not.
    bool ValidateUser(const string& userName);

    // Determine whether the given user name and password are both correct.
    // Return true if the given userName exists and its password matches
    // passWord; or false if not.
    bool AuthenticateUser(const string& userName, const string& passWord);

    // Returns the passWord of the given user.
    // If the userName does not exist, throw std::range_error.
    string GetPassword(const string& userName);

    //  Return the bucket number where the given user is located.
    // If the userName does not exist, throw std::range_error.
    size_t WordBucketId(const string& userName);

  private:

    unordered_map<string, string> table_;
};

// CONSTRUCTOR - ALREADY COMPLETE
UserLogin::UserLogin() {
}

bool UserLogin::ReadIn(const string& filename) {
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return false;
}

size_t UserLogin::NumberOfUsers() {
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0;
}

bool UserLogin::ValidateUser(const string& userName) {
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return false;
}

bool UserLogin::AuthenticateUser(const string& userName, const string& passWord) {
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return false;
}

string UserLogin::GetPassword(const string& userName) {
  throw range_error("Not implemented yet");
}

size_t UserLogin::WordBucketId(const string& userName) {
  // TODO: Implement this function, including the return statement.
  // Before submitting your assignment, delete all TODO comments
  // including this one.
  return 0;
}
