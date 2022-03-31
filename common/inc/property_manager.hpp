/* ----------------------------------------------------------------
  Copyright (c) Coding Nerd
  Licensed under the Apache License, Version 2.0
  See LICENSE in the project root for license information.
---------------------------------------------------------------- */

#pragma once

#include <boost/property_tree/ptree.hpp>

#include "singleton.hpp"

namespace netpune {
namespace profiler {
namespace unmon {
class PropertyManager : public Singleton<PropertyManager> {
 public:
  PropertyManager();
  virtual ~PropertyManager() = default;

  PropertyManager(const PropertyManager &) = default;

  PropertyManager(PropertyManager &&) = delete;
  PropertyManager &operator=(const PropertyManager &) = delete;
  PropertyManager &operator=(PropertyManager &&) = delete;

 private:
  void load(const std::string &filename);
  boost::property_tree::ptree pTree_;
};
}  // namespace unmon
}  // namespace profiler
}  // namespace netpune