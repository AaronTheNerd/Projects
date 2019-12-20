// Written by Aaron Barge
// Copyright 2019


#ifndef _BIGINT_BITS2STR_HPP_
#define _BIGINT_BITS2STR_HPP_
#include "BigInt.hpp"
#include <algorithm>
#include <bitset>
#include <string>


// =========================== Global Variables ============================ //
const size_t BITS = 1024;


// ========================= Forward Declarations ========================== //
std::string bits2str(std::bitset<BITS>);
void plus_eq(std::string&, std::string);
void double_str(std::string&);
int char2int(char);
char int2char(int);

// ============================ Implementation ============================= //
std::string bits2str(std::bitset<BITS> bits) {
  std::string ret("0");
  std::string bit("1");
  for (size_t i = 0; i < BITS; ++i) {
    if (bits[i])
      plus_eq(ret, bit);
    double_str(bit);
  }
  return ret;
}


void plus_eq(std::string& s, std::string add) {
  int carry = 0;
  int s_curr, add_curr;
  size_t length = std::max(s.size(), add.size());
  while (s.size() < length)
    s = '0' + s;
  while (add.size() < length)
    add = '0' + add;
  auto i_s = s.rbegin(), i_add = add.rbegin();
  for (size_t i = 0; i < length; ++i, ++i_s, ++i_add) {
    s_curr = char2int(*i_s);
    add_curr = char2int(*i_add);
    int new_curr = s_curr + add_curr + carry;
    if (new_curr > 9) {
      carry = 1;
      new_curr -= 10;
    } else {
      carry = 0;
    }
    *i_s = int2char(new_curr);
  }
  if (carry == 1)
    s = '1' + s;
}


void double_str(std::string& s) {
  int carry = 0;
  int curr;
  for (auto i = s.rbegin(); i != s.rend(); ++i) {
    curr = char2int(*i);
    int new_curr = 2 * curr + carry;
    if (new_curr > 9) {
      carry = 1;
      new_curr -= 10;
    } else {
      carry = 0;
    }
    *i = int2char(new_curr);
  }
  if (carry == 1)
    s = '1' + s;
}


int char2int(char c) {
  return int(c) - int('0');
}

char int2char(int i) {
  return char(i + int('0'));
}


#endif // _BIGINT_BITS2STR_HPP_