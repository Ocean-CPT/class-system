#include <hv/iniparser.h>

#include "server.h"

auto main() -> int {
  IniParser ini;
  ini.LoadFromFile("class-system-server.ini");
  const unsigned short port       = ini.Get("port", "", 7989);
  const int            thread_num = ini.Get("thread_num", "", 1);

  // init server with configurations
  Server srv{port, thread_num};

  // unload iniparser after initializing server
  ini.Unload();

  srv.start();

  // main-thread loop
  while (true) hv_msleep(200);

  return 0;
}
