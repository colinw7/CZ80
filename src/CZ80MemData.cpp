#include <CZ80MemData.h>

bool
CZ80MemData::
memRead(uchar *, ushort, ushort)
{
  return false;
}

void
CZ80MemData::
memPreWrite(const uchar *, ushort, ushort)
{
}

void
CZ80MemData::
memPostWrite(const uchar *, ushort, ushort)
{
}

bool
CZ80MemData::
memTrigger(const uchar *, ushort, ushort)
{
  return false;
}
