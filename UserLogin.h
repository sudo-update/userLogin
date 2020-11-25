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
  // TODO: check me
  int has_anything_been_done = 0;
  ifstream input_file_stream (filename, ios::in);
  if (!input_file_stream.is_open()) { return false; }
  while (!input_file_stream.eof()) {
    pair<string, string> reader;
    string reader1, reader2;
    input_file_stream >> reader1 >> reader2;
    reader.first = reader1;
    reader.second = reader2;
    table_.insert(reader);
    has_anything_been_done++;
  }
  if (has_anything_been_done != 0) {
    return true;
  } else {
    return false;
  }
}

size_t UserLogin::NumberOfUsers() {
  // TODO: check me - should work
  return table_.size();
}

bool UserLogin::ValidateUser(const string& userName) {
  // TODO: check me - damn c++17 screwed us, contains is in c++20 table_.contains();, its really that easy...
  // so i checked the official implementation of contains(), and its literally the same logic haha
  return (table_.find(userName) != table_.end());
}

bool UserLogin::AuthenticateUser(const string& userName, const string& passWord) {
  // TODO: check me
  unordered_map<string, string>::iterator authenticator_finder;
  authenticator_finder = table_.find(userName);
  if (authenticator_finder == table_.end()) { // cannot find user
    return false;
  } else { // found user
    if ((*authenticator_finder).second == passWord) { // check password
      return true;
    } else {
      return false;
    }
  }

}

string UserLogin::GetPassword(const string& userName) {
  // TODO: check me
  unordered_map<string, string>::iterator password_finder;
  password_finder = table_.find(userName);
  if (password_finder == table_.end()) {
    throw range_error("userName does not exist");
  } else {
    return ((*password_finder).second);
  }
}

size_t UserLogin::WordBucketId(const string& userName) {
  // TODO: check me
  unordered_map<string, string>::iterator bucket_finder;
  bucket_finder = table_.find(userName);
  if (bucket_finder == table_.end()) {
    throw range_error("userName does not exist");

  } else {
    return table_.bucket(userName);
  }

}
