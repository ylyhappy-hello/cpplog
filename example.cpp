#include "logger.hpp"
int main(int argc, char *argv[]) {
  LogInfo("hellowrold %s %s %s", "1", "1", "1");
  LogError("xxxxx %s %d %d", "1", 1, 1);
  LogWarn("hhelkadsf");
  return 0;
}
