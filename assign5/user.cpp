#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name) : _name(name), _friends(nullptr), _size(0), _capacity(0) {}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void User::add_friend(const std::string& name) {
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string User::get_name() const { return _name; }

/**
 * Returns the number of friends this User has.
 */
size_t User::size() const { return _size; }

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name) { _friends[index] = name; }

/**
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */

std::ostream& operator<<(std::ostream& out, const User& user) {
  out << "User(name=" << user._name << ", friends=[";
  if (user._size > 0) { // 空的情况还是得注意考虑
    out << *user._friends;
    for (int i = 1; i < user._size; i++) {
      out << ", " << user._friends[i];
    } // 循环输出friends list
  }
  out << "])";

  return out;
}

User::~User() { delete[] _friends; }

User::User(const User& user)
    : _name(user._name), _friends(new std::string[user._capacity]), _size(user._size),
      _capacity(user._capacity) {
  for (size_t i = 0; i < _size; i++) {
    _friends[i] = user._friends[i];
  }
}

User& User::operator=(const User& user) {
  if (this == &user) {
    return *this;
  }

  delete[] _friends;

  _name = user._name;
  _size = user._size;
  _capacity = user._capacity;
  _friends = new std::string[_capacity];
  for (size_t i = 0; i < _size; i++) {
    _friends[i] = user._friends[i];
  }
  return *this;
}

User& User::operator+=(User& other) {
//   if (this == &other) {
//     return *this;
//   }
 
  other.add_friend(this->_name);
  this->add_friend(other._name);
  return *this;
}

bool User::operator<(const User& other) const { return _name < other._name; }