/* ----------------------------------------------------------------
  Copyright (c) Coding Nerd
  Licensed under the Apache License, Version 2.0
  See LICENSE in the project root for license information.
---------------------------------------------------------------- */

#include <stdlib.h>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include "boost/version.hpp"
#include "logger.hpp"
#include "options.hpp"
#include "property_manager.hpp"

namespace unmon = netpune::profiler::unmon;

static boost::program_options::variables_map vm;

int main(int argc, char* argv[]) {
  init_logger();
  vm = extract_opt(argc, argv);
  unmon::PropertyManager::get_const_instance();
  boost::filesystem::path app = argv[0];
  BOOST_LOG_TRIVIAL(info) << app.stem().string() << " built with "
                          << "Boost Version " << BOOST_VERSION / 100000
                          << "."                                // maj. version
                          << BOOST_VERSION / 100 % 1000 << "."  // min. version
                          << BOOST_VERSION % 100;               // patch version

  return EXIT_SUCCESS;
}