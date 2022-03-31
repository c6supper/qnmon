/* ----------------------------------------------------------------
  Copyright (c) Coding Nerd
  Licensed under the Apache License, Version 2.0
  See LICENSE in the project root for license information.
---------------------------------------------------------------- */

#include <stdlib.h>

#include <boost/program_options.hpp>

#include "boost/version.hpp"
#include "logger.h"
#include "options.h"

static boost::program_options::variables_map vm;

int main(int argc, char* argv[]) {
  init_logger();
  vm = extract_opt(argc, argv);
  BOOST_LOG_TRIVIAL(info) << "Boost Version " << BOOST_VERSION / 100000
                          << "."                                // maj. version
                          << BOOST_VERSION / 100 % 1000 << "."  // min. version
                          << BOOST_VERSION % 100;               // patch version

  return EXIT_SUCCESS;
}