#ifndef COStreamFile_H
#define COStreamFile_H

#include <CFileBase.h>
#include <iostream>

class COStreamFile : public CFileBase {
 public:
  COStreamFile(std::ostream &os);
};

#endif
