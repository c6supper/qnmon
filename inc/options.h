#include <boost/program_options.hpp>
#include <iostream>

namespace opt = boost::program_options;

opt::variables_map extract_opt(int argc, char* argv[]) {
  opt::options_description desc("All options");

  opt::variables_map vm;
  int oranges_var = 0;
  desc.add_options()
      // ProgramOptions stores the option value into
      // the variable that is passed by pointer. Here value of
      // "--oranges" option will be stored into 'oranges_var'.
      ("oranges,o", opt::value<int>(&oranges_var)->required(),
       "oranges that you have")

      // 'name' option is not marked with 'required()',
      // so user may not provide it.
      ("name", opt::value<std::string>(), "your name")("help",
                                                       "produce help message")

      // 'a' is a short option name for apples. Use as '-a 10'.
      // If no value provided, then the default value is used.
      ("apples,a", opt::value<int>()->default_value(10),
       "apples that you have");

  // Parsing command line options and storing values to 'vm'
  opt::store(opt::parse_command_line(argc, argv, desc), vm);

  // We can also parse environment variables. Just use
  // 'opt::store with' 'opt::parse_environment' function.

  if (vm.count("help")) {
    std::cerr << desc << "\n";
    return vm;
  }

  // Adding missing options from "apples_oranges.cfg" config file.
  try {
    opt::store(opt::parse_config_file<char>("apples_oranges.cfg", desc), vm);
  } catch (const opt::reading_file& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  try {
    // `opt::required_option` exception is thrown if
    // one of the required options was not set.
    opt::notify(vm);

  } catch (const opt::required_option& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return vm;
  }

  if (vm.count("name")) {
    std::cerr << "Hi," << vm["name"].as<std::string>() << "!\n";
  }
  std::cerr << "Fruits count: "
            << vm["apples"].as<int>() + vm["oranges"].as<int>() << std::endl;

  return vm;

}  // end of `main`