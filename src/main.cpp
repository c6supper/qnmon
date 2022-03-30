/* ----------------------------------------------------------------
  Copyright (c) Coding Nerd
  Licensed under the Apache License, Version 2.0
  See LICENSE in the project root for license information.
---------------------------------------------------------------- */

#include "boost/version.hpp"
#include "logger.h"
#include <stdlib.h>
#include <boost/program_options.hpp>

int main(int argc, char* argv[]) {
  init_logger();
  BOOST_LOG_TRIVIAL(info) << "Boost Version "     
          << BOOST_VERSION / 100000     << "."  // maj. version
          << BOOST_VERSION / 100 % 1000 << "."  // min. version
          << BOOST_VERSION % 100;                // patch version

  return EXIT_SUCCESS;
}