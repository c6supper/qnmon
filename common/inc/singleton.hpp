/* ----------------------------------------------------------------
  Copyright (c) Coding Nerd
  Licensed under the Apache License, Version 2.0
  See LICENSE in the project root for license information.
---------------------------------------------------------------- */

#pragma once

#include <memory>

namespace netpune {
namespace profiler {
namespace unmon {
template <typename T>
class Singleton {
 public:
  // Very fast inlined operator accessors
  std::shared_ptr<T> operator->() { return instance_; }
  std::shared_ptr<T> operator->() const { return instance_; }
  T& operator*() { return *instance_; }
  const T& operator*() const { return *instance_; }

  static std::shared_ptr<T> getInstance() {
    if (nullptr == instance_) {
      instance_.reset(new T());
    }
    return instance_;
  }

 private:
  static std::shared_ptr<T> instance_;
};

template <typename T>
std::shared_ptr<T> Singleton<T>::instance_ = nullptr;
}  // namespace unmon
}  // namespace profiler
}  // namespace netpune