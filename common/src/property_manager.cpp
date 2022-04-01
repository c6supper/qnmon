/* ----------------------------------------------------------------
  Copyright (c) Coding Nerd
  Licensed under the Apache License, Version 2.0
  See LICENSE in the project root for license information.
---------------------------------------------------------------- */

#include "property_manager.hpp"

#include <boost/property_tree/json_parser.hpp>

using namespace netpune::profiler::unmon;
namespace pt = boost::property_tree;
namespace sl = boost::serialization;

PropertyManager::PropertyManager() : sl::singleton<PropertyManager>() {}

void PropertyManager::load(const std::string &filename) {
  // Parse the json into the property tree.
  pt::json_parser::read_json(filename, pTree_);
}
