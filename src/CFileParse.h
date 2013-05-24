class CFileParse {
 public:
  CFileParse(CFile *file);

  bool skipSpace();

  bool skipChar(uint n=1);

  bool readInteger(uint *integer);
  bool readBaseInteger(uint base, uint *integer);

  bool isIdentifier();
  bool readIdentifier(std::string &identifier);

  bool isDigit();

  bool isChar(char c);
  bool isString(const std::string &str);

  bool eol();
  bool eof();

  char readChar();

  void loadLine();

  void unread(const std::string &str);

  void dumpBuffer(std::ostream &os=std::cout);

  std::string getBuffer();

  bool rewind();
};
