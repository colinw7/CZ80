#ifndef CFile_H
#define CFile_H

#include <CFileBase.h>

class CFile : public CFileBase {
 public:
  CFile(const std::string &filename);
};

#endif
