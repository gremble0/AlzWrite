#include <fstream>
#include <ios>
#include <string>
#include <vector>

#include "File.hpp"

std::vector<std::string> File::readLines() const {
  std::vector<std::string> lines;
  std::ifstream file(this->path);

  while (!file.eof()) {
    std::string buf;
    std::getline(file, buf);
    lines.push_back(buf);
  }

  return lines;
}

void File::write(std::vector<std::string> lines) const {
  std::ofstream file(this->path, std::ios::out | std::ios::trunc);

  for (const auto &line : lines)
    // TODO: shifting with std::endl every time flushes the buffer every iteration which is not
    // effective
    file << line << std::endl;
}
