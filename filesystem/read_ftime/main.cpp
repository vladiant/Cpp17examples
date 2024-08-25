//********************************************************
// The following code example is taken from the book
//  C++17 - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppstd17.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************

#include <cstdlib>  // for EXIT_FAILURE
#include <filesystem>
#include <iostream>

std::string asString(const std::filesystem::file_time_type& tp) {
  using system_clock = std::chrono::system_clock;
  auto t = system_clock::to_time_t(
      system_clock::now() +
      std::chrono::duration_cast<system_clock::duration>(
          tp - std::filesystem::file_time_type::clock::now()));

  // convert to calendar time (including skipping trailing newline):
  std::string ts = std::ctime(&t);
  ts.resize(ts.size() - 1);
  return ts;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <path> \n";
    return EXIT_FAILURE;
  }

  // p represents a filesystem path (might not exist)
  std::filesystem::path p{argv[1]};

  std::filesystem::file_time_type ftime = std::filesystem::last_write_time(p);

  std::cout << "Last write time: " << asString(ftime) << '\n';

  return EXIT_SUCCESS;
}
