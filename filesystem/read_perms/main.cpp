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

std::string asString(const std::filesystem::perms& pm) {
  using perms = std::filesystem::perms;
  std::string s;
  s.resize(9);
  s[0] = (pm & perms::owner_read) != perms::none ? 'r' : '-';
  s[1] = (pm & perms::owner_write) != perms::none ? 'w' : '-';
  s[2] = (pm & perms::owner_exec) != perms::none ? 'x' : '-';
  s[3] = (pm & perms::group_read) != perms::none ? 'r' : '-';
  s[4] = (pm & perms::group_write) != perms::none ? 'w' : '-';
  s[5] = (pm & perms::group_exec) != perms::none ? 'x' : '-';
  s[6] = (pm & perms::others_read) != perms::none ? 'r' : '-';
  s[7] = (pm & perms::others_write) != perms::none ? 'w' : '-';
  s[8] = (pm & perms::others_exec) != perms::none ? 'x' : '-';
  return s;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <path> \n";
    return EXIT_FAILURE;
  }

  // p represents a filesystem path (might not exist)
  std::filesystem::path p{argv[1]};

  std::filesystem::perms permissions = std::filesystem::status(p).permissions();

  std::cout << "Permissions: " << asString(permissions) << '\n';

  return EXIT_SUCCESS;
}
