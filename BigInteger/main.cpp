// Written by Aaron Barge
// Copyright 2019


#include <assert.h>
#include <iostream>
#include "BigInt.hpp"


struct Testing {
  bool plus_eq() {
    std::cout << "Testing Plus Equals: ";
    BigInt i(100), j(200);
    bool result = (i += j) == (100 + 200);
    if (result) {
      std::cout << "SUCCESS" << std::endl;
    } else {
      std::cout << "FAILED" << std::endl;
    }
    return result;
  }
  bool minus_eq() {
    BigInt i(200), j(100);
    std::cout << "Testing Minus Equals: ";
    bool result = (i -= j) == (200 - 100);
    if (result) {
      std::cout << "SUCCESS" << std::endl;
    } else {
      std::cout << "FAILED" << std::endl;
    }
    return result;
  }
  bool times_eq() {
    BigInt i(100), j(200);
    std::cout << "Testing Times Equals: ";
    bool result = (i *= j) == (100 * 200);
    if (result) {
      std::cout << "SUCCESS" << std::endl;
    } else {
      std::cout << "FAILED" << std::endl;
    }
    return result;
  }
  bool divide_eq() {
    BigInt i(200), j(100);
    std::cout << "Testing Divide Equals: ";
    bool result = (i /= j) == (200 / 100);
    if (result) {
      std::cout << "SUCCESS" << std::endl;
    } else {
      std::cout << "FAILED" << std::endl;
    }
    return result;
  }
  bool mod_eq() {
    BigInt i(200), j(100);
    std::cout << "Testing Mod Equals: ";
    bool result = (i %= j) == (200 % 100);
    if (result) {
      std::cout << "SUCCESS" << std::endl;
    } else {
      std::cout << "FAILED" << std::endl;
    }
    return result;
  }
  bool less_than() {
    BigInt i(100), j(200), k(100);
    std::cout << "Testing Less Than: ";
    bool result =  ((i < k) == (100 < 100)) && ((i < j) == (100 < 200));
    if (result) {
      std::cout << "SUCCESS" << std::endl;
    } else {
      std::cout << "FAILED" << std::endl;
    }
    return result;
  }
  bool greater_than() {
    BigInt i(100), j(200), k(100);
    std::cout << "Testing Greater Than: ";
    bool result =  ((i > k) == (100 > 100)) && ((j > i) == (200 > 100));
    if (result) {
      std::cout << "SUCCESS" << std::endl;
    } else {
      std::cout << "FAILED" << std::endl;
    }
    return result;
  }
  bool less_than_eqs() {
    BigInt i(100), j(200), k(100);
    std::cout << "Testing Less Than or Equal To: ";
    bool result =  ((i <= k) == (100 <= 100)) && ((i <= j) == (100 <= 200)) && ((j <= i) == (200 <= 100));
    if (result) {
      std::cout << "SUCCESS" << std::endl;
    } else {
      std::cout << "FAILED" << std::endl;
    }
    return result;
  }
  bool greater_than_eqs() {
    BigInt i(100), j(200), k(100);
    std::cout << "Testing Greater Than or Equal To: ";
    bool result =  ((i >= k) == (100 >= 100)) && ((i >= j) == (100 >= 200)) && ((j >= i) == (200 >= 100));
    if (result) {
      std::cout << "SUCCESS" << std::endl;
    } else {
      std::cout << "FAILED" << std::endl;
    }
    return result;
  }
  Testing() {
    bool result = true;
    result &= plus_eq();
    result &= minus_eq();
    result &= times_eq();
    result &= divide_eq();
    result &= mod_eq();
    result &= less_than();
    result &= greater_than();
    result &= less_than_eqs();
    result &= greater_than_eqs();
    assert(result);
  }
};


int main(int argc, char** argv) {
  Testing t;
  return 0;
}