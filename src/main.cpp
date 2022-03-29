/* ----------------------------------------------------------------
  Copyright (c) Coding Nerd
  Licensed under the Apache License, Version 2.0
  See LICENSE in the project root for license information.
---------------------------------------------------------------- */

#include "boost/version.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Using Boost "     
          << BOOST_VERSION / 100000     << "."  // maj. version
          << BOOST_VERSION / 100 % 1000 << "."  // min. version
          << BOOST_VERSION % 100                // patch version
          << std::endl;
}