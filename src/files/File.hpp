#include <string>
#include <vector>

class File {
public:
  explicit File(const std::string &path) : path(path) {}

  std::vector<std::string> readLines();
  void write(std::vector<std::string> lines) const;

private:
  const std::string &path;
};
