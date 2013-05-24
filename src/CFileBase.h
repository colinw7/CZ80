class CFileBase {
 public:
  CFileBase() { }

  bool readLine(std::string &line);

  bool read(uchar *data, size_t size);

  bool write(const std::string &str);
  bool write(const uchar *data, size_t size);

  bool eof();
};
