/* ----------------------------------------------------------------
  Copyright (c) Coding Nerd
  Licensed under the Apache License, Version 2.0
  See LICENSE in the project root for license information.
---------------------------------------------------------------- */

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>

static inline void init_logger() {
  static const std::string COMMON_FMT("[%TimeStamp%][%Severity%]:  %Message%");

  boost::log::register_simple_formatter_factory<
      boost::log::trivial::severity_level, char>("Severity");

  // Output message to console
  boost::log::add_console_log(std::cout,
                              boost::log::keywords::format = COMMON_FMT,
                              boost::log::keywords::auto_flush = true);

#ifndef DEBUG
  // Output message to file, rotates when file reached 1mb or at midnight every
  // day. Each log file is capped at 1mb and total is 20mb
  boost::log::add_file_log(
      boost::log::keywords::file_name = "u_%3N.log",
      boost::log::keywords::rotation_size = 1 * 1024 * 1024,
      boost::log::keywords::max_size = 20 * 1024 * 1024,
      boost::log::keywords::time_based_rotation =
          boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
      boost::log::keywords::format = COMMON_FMT,
      boost::log::keywords::auto_flush = true);
#endif

  boost::log::add_common_attributes();

  // Only output message with INFO or higher severity in Release
#ifndef DEBUG
  boost::log::core::get()->set_filter(boost::log::trivial::severity >=
                                      boost::log::trivial::info);
#endif
}