#include <std_c++.h>
#include <CZ80TclLib/CZ80TclLib.h>

int
main(int argc, char **argv)
{
  CZ80TclLib app(argc, argv);

  app.addStdRstData();

  app.setDebug(true);

  app.init();
}
