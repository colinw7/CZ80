#include <CZ80Load.h>

bool
CZ80::
load(const std::string &str)
{
  CFile file(str);

  return load(&file);
}

bool
CZ80::
load(CFile *file)
{
  ushort load_len;

  if (! load(file, &load_pos_, &load_len))
    return false;

  load_len_ = load_len;

  return true;
}

bool
CZ80::
loadBin(const std::string &str)
{
  CFile file(str);

  return loadBin(&file);
}

bool
CZ80::
loadBin(CFile *file)
{
  ushort load_len;

  if (! loadBin(file, &load_pos_, &load_len))
    return false;

  load_len_ = load_len;

  return true;
}

bool
CZ80::
load(CFile *file, ushort *pos, ushort *len)
{
  bool pos_set = false;

  uint addr, value;

  std::string line;

  while (file->readLine(line)) {
    std::vector<std::string> words;

    CStrUtil::toWords(line, words);

    if (words.size() < 2)
      continue;

    if (! CStrUtil::decodeHexString(words[0], &addr))
      continue;

    setPC(ushort(addr));

    if (! pos_set) {
      *pos = getPC();

      pos_set = true;
    }

    for (ushort i = 1; i < words.size(); ++i) {
      if (! CStrUtil::decodeHexString(words[i], &value))
        continue;

      setByte(uchar(value));

      incPC();
    }
  }

  *len = getPC() - *pos;

  setPC(*pos);

  return true;
}

bool
CZ80::
loadBin(CFile *file, ushort *pos, ushort *len)
{
  uchar b;

  ushort pos1 = *pos;
  ushort pos2 = *pos;

  setPC(pos1);

  while (! file->eof()) {
    file->read(static_cast<uchar *>(&b), 1);

    setByte(b);

    incPC();
  }

  pos2 = getPC();

  *pos = pos1;
  *len = pos2 - pos1;

  setPC(pos1);

  return true;
}

void
CZ80::
loadBin(const uchar *data, size_t len)
{
  setPC(0);

  for (size_t i = 0; i < len; ++i) {
    setByte(data[i]);

    incPC();
  }
}
