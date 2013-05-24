#ifndef CAT_EXIT_H
#define CAT_EXIT_H

#include <vector>

struct CAtExit {
  typedef std::vector<CAtExit *> AtExitList;

  CAtExit() {
    addAtExit(this);
  }

  virtual ~CAtExit() { }

  virtual void operator()() = 0;

  static void atExitCB() {
    AtExitList *exit_procs = getExitList();

    AtExitList::iterator p1 = exit_procs->begin();
    AtExitList::iterator p2 = exit_procs->end  ();

    for ( ; p1 != p2; ++p1) {
      CAtExit *at_exit = *p1;

      (*at_exit)();
    }
  }

  static void addAtExit(CAtExit *at_exit) {
    static bool registered;

    AtExitList *exit_procs = getExitList();

    if (! registered)
      atexit(CAtExit::atExitCB);

    exit_procs->push_back(at_exit);
  }

  static AtExitList *getExitList() {
    static AtExitList exit_procs;

    return &exit_procs;
  }
};

#endif
