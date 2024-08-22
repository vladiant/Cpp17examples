#include <cstdlib>  // for EXIT_FAILURE
#include <filesystem>
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <path> \n";
    return EXIT_FAILURE;
  }

  // p represents a filesystem path (might not exist)
  std::filesystem::path p{argv[1]};

  // Path check functions
  if (is_regular_file(p)) {  // is path p a regular file?
    std::cout << '"' << p.string() << "\" exists with " << file_size(p)
              << " bytes\n";
  } else if (is_directory(p)) {  // is path p a directory?
    std::cout << '"' << p.string() << "\" is a directory containing:\n";
    for (const auto& e : std::filesystem::directory_iterator{p}) {
      std::cout << "  \"" << e.path().string() << "\"\n";
    }
  } else if (exists(p)) {  // does path p actually exist?
    std::cout << '"' << p.string() << "\" is a special file\n";
  } else {
    std::cout << "path \"" << p.string() << "\" does not exist\n";
  }

  std::cout << '\n';

  // Path status type
  namespace fs = std::filesystem;
  switch (fs::path p{argv[1]}; status(p).type()) {
    case fs::file_type::not_found:
      std::cout << "path \"" << p.string() << "\" does not exist\n";
      break;
    case fs::file_type::regular:
      std::cout << '"' << p.string() << "\" exists with " << file_size(p)
                << " bytes\n";
      break;
    case fs::file_type::directory:
      std::cout << '"' << p.string() << "\" is a directory containing:\n";
      for (const auto& e : std::filesystem::directory_iterator{p}) {
        std::cout << "  " << e.path().string() << '\n';
      }
      break;
    default:
      std::cout << '"' << p.string() << "\" is a special file\n";
      break;
  }

  return EXIT_SUCCESS;
}
