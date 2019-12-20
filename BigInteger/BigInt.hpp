// Written by Aaron Barge
// Copyright 2019


// The Goal:
// Implement a 1024 bit / 128 byte unsigned integer class
// Additionally, the goal is to do as much as possible bitwise rather than
// through conversions


#ifndef _BIGINT_BIGINT_HPP_
#define _BIGINT_BIGINT_HPP_
#include "bits2str.hpp"
#include <bitset>
#include <iostream>
#include <string>
#include <cstddef>


// =========================== Global Variables ============================ //
extern const size_t BITS; // bits2str.hpp


// ========================= Forward Declarations ========================== //
class BigInt {
 public:
  std::bitset<BITS> bits;
  explicit BigInt();
  explicit BigInt(const unsigned long long& num);
  explicit BigInt(const std::string& str); // TODO
  explicit BigInt(const BigInt& n);
  ~BigInt();
  BigInt& operator=(const BigInt& n);
  BigInt& operator=(const unsigned long long& num);
  BigInt& operator+=(const BigInt& n);
  BigInt& operator+=(const unsigned long long& num);
  BigInt& operator-=(const BigInt& n); // TODO
  BigInt& operator-=(const unsigned long long& num); // TODO
  BigInt& operator*=(const BigInt& n);
  BigInt& operator*=(const unsigned long long& num);
  BigInt& operator/=(const BigInt& n); // TODO
  BigInt& operator/=(const unsigned long long& num); // TODO
  BigInt& operator%=(const BigInt& n); // TODO
  BigInt& operator%=(const unsigned long long& num); // TODO
  BigInt& operator&=(const BigInt& n); // Testing Required
  BigInt& operator&=(const unsigned long long& num); // Testing Required
  BigInt& operator|=(const BigInt& n); // Testing Required
  BigInt& operator|=(const unsigned long long& num); // Testing Required
  BigInt& operator^=(const BigInt& n); // Testing Required
  BigInt& operator^=(const unsigned long long& num); // Testing Required
  BigInt& operator<<=(const size_t& pos); // Testing Required
  BigInt& operator>>=(const size_t& pos); // Testing Required
  BigInt& operator+(const BigInt& n) const;
  BigInt& operator+(const unsigned long long& num) const;
  BigInt& operator-(const BigInt& n) const; // TODO
  BigInt& operator-(const unsigned long long& num) const; // TODO
  BigInt& operator*(const BigInt& n) const; // Testing Required
  BigInt& operator*(const unsigned long long& num) const; // Testing Required
  BigInt& operator/(const BigInt& n) const; // TODO
  BigInt& operator/(const unsigned long long& num) const; // TODO
  BigInt& operator%(const BigInt& n) const; // TODO
  BigInt& operator%(const unsigned long long& num) const; // TODO
  BigInt& operator&(const BigInt& n) const; // Testing Required
  BigInt& operator&(const unsigned long long& num) const; // Testing Required
  BigInt& operator|(const BigInt& n) const; // Testing Required
  BigInt& operator|(const unsigned long long& num) const; // Testing Required
  BigInt& operator^(const BigInt& n) const; // Testing Required
  BigInt& operator^(const unsigned long long& num) const; // Testing Required
  BigInt& operator<<(const size_t& pos) const; // Testing Required
  BigInt& operator>>(const size_t& pos) const; // Testing Required
  BigInt& operator++(); // Testing Required
  BigInt& operator--(); // Testing Required
  BigInt& operator~() const; // Testing Required
  bool operator==(const BigInt& n) const; // Testing Required
  bool operator==(const unsigned long long& num) const; // Testing Required
  bool operator!=(const BigInt& n) const; // Testing Required
  bool operator!=(const unsigned long long& num) const; // Testing Required
  bool operator<(const BigInt& n) const; // TODO
  bool operator<(const unsigned long long& num) const; // TODO
  bool operator>(const BigInt& n) const; // TODO
  bool operator>(const unsigned long long& num) const; // TODO
  bool operator<=(const BigInt& n) const; // TODO
  bool operator<=(const unsigned long long& num) const; // TODO
  bool operator>=(const BigInt& n) const; // TODO
  bool operator>=(const unsigned long long& num) const; // TODO
};


// ========================== Non-Class Functions ========================== //
std::ostream& operator<<(std::ostream& out, const BigInt& n) { // Testing Required
  out << bits2str(n.bits);
  return out;
}
BigInt& operator+(const unsigned long long& num, const BigInt& n) {
  return n + num;
}
BigInt& operator-(const unsigned long long& num, const BigInt& n);
BigInt& operator*(const unsigned long long& num, const BigInt& n) {
  return n * num;
}
BigInt& operator/(const unsigned long long& num, const BigInt& n);
BigInt& operator%(const unsigned long long& num, const BigInt& n);
BigInt& operator&(const unsigned long long& num, const BigInt& n) {
  return n & num;
}
BigInt& operator|(const unsigned long long& num, const BigInt& n) {
  return n | num;
}
BigInt& operator^(const unsigned long long& num, const BigInt& n) {
  return n ^ num;
}


// ========================= Class Implementation ========================== //
// ============================= Constructors ============================== //
BigInt::BigInt() {
  this->bits = std::bitset<BITS>(0);
}
BigInt::BigInt(const unsigned long long& num) {
  this->bits = std::bitset<BITS>(num);
}
BigInt::BigInt(const std::string& str) {
  if (str.size() <= 2) { // No format, therefore must be decimal or invalid
    
  } else {
    std::string format = str.substr(0, 2);
    if (format == std::string("0B") || format == std::string("0b")) {
      this->bits = std::bitset<BITS>(str.substr(2, str.size() - 2));
    } else if (format == std::string("0x") || format == std::string("0X")) {

    } else {
        
    }
  }
}
BigInt::BigInt(const BigInt& n) { // May be unnecessary
  if (this != &n)
    for (int i = 0; i < BITS; ++i)
      this->bits[i] = n.bits[i];
}
BigInt::~BigInt() { // May be unnecessary

}


// ========================= Assignment Operators ========================== //
BigInt& BigInt::operator=(const BigInt& n) {
  if (this != &n) {
    for (int i = 0; i < BITS; ++i)
      this->bits[i] = n.bits[i];
  }
  return *this;
}
BigInt& BigInt::operator=(const unsigned long long& num) {
  this->bits = std::bitset<BITS>(num);
  return *this;
}


// ============================ Add and Assign ============================= //
BigInt& BigInt::operator+=(const BigInt& n) {
  bool n1 = 0, n2 = 0, carry = 0;
  for (size_t i = 0; i < BITS; ++i) {
    n1 = this->bits[i];
    n2 = n.bits[i];
    this->bits[i] = carry ^ (n1 ^ n2);
    carry = (n1 && n2) || (n1 && carry) || (n2 && carry);
  }
  return *this;
}
BigInt& BigInt::operator+=(const unsigned long long& num) {
  BigInt n(num);
  *this += n;
  return *this;
}


// =========================== Minus and Assign ============================ //
BigInt& BigInt::operator-=(const BigInt& n) { }
BigInt& BigInt::operator-=(const unsigned long long& num) { }


// ========================== Multiply and Assign ========================== //
BigInt& BigInt::operator*=(const BigInt& n) {
  BigInt* mult = new BigInt(0);
  for (size_t i = 0; i < BITS; ++i) {
    if (this->bits[i]) {
      *mult += (n << i);
    }
  }
  this->bits = mult->bits;
  delete mult;
  return *this;
}
BigInt& BigInt::operator*=(const unsigned long long& num) {
  BigInt n(num);
  *this *= n;
  return *this;
}


// =========================== Divide and Assign =========================== //
BigInt& BigInt::operator/=(const BigInt& n) { }
BigInt& BigInt::operator/=(const unsigned long long& num) { }


// ============================ Mod and Assign ============================= //
BigInt& BigInt::operator%=(const BigInt& n) { }
BigInt& BigInt::operator%=(const unsigned long long& num) { }


// ============================ AND and Assign ============================= //
BigInt& BigInt::operator&=(const BigInt& n) {
  this->bits &= n.bits;
  return *this;
}
BigInt& BigInt::operator&=(const unsigned long long& num) {
  BigInt n(num);
  this->bits &= n.bits;
  return *this;
}


// ============================= OR and Assign ============================= //
BigInt& BigInt::operator|=(const BigInt& n) {
  this->bits |= n.bits;
  return *this;
}
BigInt& BigInt::operator|=(const unsigned long long& num) {
  BigInt n(num);
  this->bits |= n.bits;
  return *this;
}


// ============================ XOR and Assign ============================= //
BigInt& BigInt::operator^=(const BigInt& n) {
  this->bits ^= n.bits;
  return *this;
}
BigInt& BigInt::operator^=(const unsigned long long& num) {
  BigInt n(num);
  this->bits ^= n.bits;
  return *this;
}


// ========================= Left Shift and Assign ========================= //
BigInt& BigInt::operator<<=(const size_t& pos) {
  this->bits <<= pos;
  return *this;
}


// ======================== Right Shift and Assign ========================= //
BigInt& BigInt::operator>>=(const size_t& pos) {
  this->bits >>= pos;
  return *this;
}


// ================================== Add ================================== //
BigInt& BigInt::operator+(const BigInt& n) const {
  BigInt* sum = new BigInt(*this);
  *sum += n;
  return *sum;
}
BigInt& BigInt::operator+(const unsigned long long& num) const {
  return *this + BigInt(num);
}


// ================================= Minus ================================= //
BigInt& BigInt::operator-(const BigInt& n) const { }
BigInt& BigInt::operator-(const unsigned long long& num) const {
  return *this - BigInt(num);
}


// =============================== Multiply ================================ //
BigInt& BigInt::operator*(const BigInt& n) const {
  BigInt* product = new BigInt(*this);
  *product *= n;
  return *product;
}
BigInt& BigInt::operator*(const unsigned long long& num) const {
  return *this * BigInt(num);
}


// ================================ Divide ================================= //
BigInt& BigInt::operator/(const BigInt& n) const { }
BigInt& BigInt::operator/(const unsigned long long& num) const { }


// ================================== Mod ================================== //
BigInt& BigInt::operator%(const BigInt& n) const { }
BigInt& BigInt::operator%(const unsigned long long& num) const { }


// ================================== AND ================================== //
BigInt& BigInt::operator&(const BigInt& n) const {
  BigInt* n_and = new BigInt(*this);
  n_and->bits &= n.bits;
  return *n_and;
}
BigInt& BigInt::operator&(const unsigned long long& num) const {
  return *this & BigInt(num);
}


// ================================== OR =================================== //
BigInt& BigInt::operator|(const BigInt& n) const {
  BigInt* n_or = new BigInt(*this);
  n_or->bits |= n.bits;
  return *n_or;
}
BigInt& BigInt::operator|(const unsigned long long& num) const {
  return *this | BigInt(num);
}


// ================================== XOR ================================== //
BigInt& BigInt::operator^(const BigInt& n) const {
  BigInt* n_xor = new BigInt(*this);
  n_xor->bits ^= n.bits;
  return *n_xor;
}
BigInt& BigInt::operator^(const unsigned long long& num) const {
  return *this ^ BigInt(num);
}


// ============================== Left Shift =============================== //
BigInt& BigInt::operator<<(const size_t& pos) const {
  BigInt* shl = new BigInt(*this);
  shl->bits <<= pos;
  return *shl;
}


// ============================== Right Shift ============================== //
BigInt& BigInt::operator>>(const size_t& pos) const {
  BigInt* shr = new BigInt(*this);
  shr->bits >>= pos;
  return *shr;
}


// ============================ Unary Operators ============================ //
BigInt& BigInt::operator++() {
  return *this += 1;
}
BigInt& BigInt::operator--() {
  return *this -= 1;
}
BigInt& BigInt::operator~() const {
  BigInt* n = new BigInt(0);
  n->bits = ~this->bits;
  return *n;
}


// =========================== Binary Operators ============================ //
bool BigInt::operator==(const BigInt& n) const {
  return this->bits == n.bits;
}
bool BigInt::operator==(const unsigned long long& num) const {
  return this->bits == std::bitset<BITS>(num);
}
bool BigInt::operator!=(const BigInt& n) const {
  return this->bits != n.bits;
}
bool BigInt::operator!=(const unsigned long long& num) const {
  return this->bits != std::bitset<BITS>(num);
}
bool BigInt::operator<(const BigInt& n) const { }
bool BigInt::operator<(const unsigned long long& num) const { }
bool BigInt::operator>(const BigInt& n) const { }
bool BigInt::operator>(const unsigned long long& num) const { }
bool BigInt::operator<=(const BigInt& n) const { }
bool BigInt::operator<=(const unsigned long long& num) const { }
bool BigInt::operator>=(const BigInt& n) const { }
bool BigInt::operator>=(const unsigned long long& num) const { }


#endif // _BIGINT_BIGINT_HPP_