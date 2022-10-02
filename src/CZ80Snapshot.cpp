#include <CZ80Snapshot.h>

bool
CZ80::
saveSnapshot(const std::string &filename)
{
  CFile file(filename);

  file.write(memory_, 0xFFFF);

  file.write(reinterpret_cast<uchar *>(&registers_), sizeof(registers_));

  return true;
}

bool
CZ80::
loadSnapshot(const std::string &filename)
{
  CFile file(filename);

  return loadSnapshot(&file);
}

bool
CZ80::
loadSnapshot(CFile *file)
{
  file->read(memory_, 0xFFFF);

  file->read(reinterpret_cast<uchar *>(&registers_), sizeof(registers_));

  return true;
}
