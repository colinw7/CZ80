#ifndef CZ80AssembleData_H
#define CZ80AssembleData_H

// Data only used by assembler

class CZ80AssembleData {
 public:
  CZ80AssembleData();

  void init();

  void initPass();

  bool isStream() const { return stream_; }

  void setStream(bool stream) { stream_ = stream; }

  void nextLine(CFileParse *parse);

  uint getCurrentLineNum() const { return current_line_num_; }

  const std::string &getCurrentLine() const { return current_line_; }

  void addValue(ushort pc, uchar c);

  void setLastLabel(const std::string &str);

  const std::string &getLastLabel() const { return last_label_; }

  void setNameValue(const std::string &name, uint value);

  void dumpValues(CFileBase *ofile);

  void dumpSymbols() const;

 private:
  typedef std::map<std::string,uint> NameValueMap;
  typedef std::map<ushort,uchar>     PCValueMap;

  bool         stream_;
  ushort       values_pc_min_, values_pc_max_;
  bool         values_pc_set_;
  PCValueMap   values_;
  std::string  current_line_;
  uint         current_line_num_;
  std::string  last_label_;
  NameValueMap name_values_;
};

#endif
