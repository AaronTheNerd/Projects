// Written by Aaron Barge
// Copyright 2019


// This file contains the code to turn bits to strings and vice versa.



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
std::string decimal2binary(std::string&);
bool is_even(const std::string&);
void half_str(std::string&);
std::string hex2binary(const std::string&);

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


std::string decimal2binary(std::string str) {
  std::string ret("");
  do {
    ret = (is_even(str) ? "0" : "1") + ret;
    half_str(str);
  } while (str != std::string("0"));
  return ret;
}


bool is_even(const std::string& str) {
  auto i = str.rbegin();
  return *i == '0' || *i == '2' || *i == '4' || *i == '6' || *i == '8';
}


void half_str(std::string& str) {
  int curr, carry = 0;
  for (auto i = str.begin(); i != str.end(); ++i) {
    assert(int(*i) >= int('0') && int(*i) <= int('9'));
    curr = carry + char2int(*i);
    if (curr % 2 == 1)
      carry = 10;
    else
     carry = 0;
    curr >>= 1;
    *i = int2char(curr);
  }
  if (str[0] == '0' && str.size() > 1)
    str.erase(str.begin());
}


std::string hex2binary(const std::string& str) {
  assert(str.size() <= BITS / 4);
  std::string ret("");
  for (auto i = str.begin(); i < str.end(); ++i) {
    if (*i == '0') ret += "0000";
    else if (*i == '1') ret += "0001";
    else if (*i == '2') ret += "0010";
    else if (*i == '3') ret += "0011";
    else if (*i == '4') ret += "0100";
    else if (*i == '5') ret += "0101";
    else if (*i == '6') ret += "0110";
    else if (*i == '7') ret += "0111";
    else if (*i == '8') ret += "1000";
    else if (*i == '9') ret += "1001";
    else if (*i == 'a' || *i == 'A') ret += "1010";
    else if (*i == 'b' || *i == 'B') ret += "1011";
    else if (*i == 'c' || *i == 'C') ret += "1100";
    else if (*i == 'd' || *i == 'D') ret += "1101";
    else if (*i == 'e' || *i == 'E') ret += "1110";
    else if (*i == 'f' || *i == 'F') ret += "1111";
    else throw;
  }
  return ret;
}


#endif // _BIGINT_BITS2STR_HPP_