#ifndef CZ80LabelData_H
#define CZ80LabelData_H

#include <map>
#include <string>

// Label Data (used by assembler/disassemble)

class CZ80LabelData {
 public:
  typedef std::map<int,std::string> LabelValueNameMap;

 public:
  CZ80LabelData() { }

  void clearLabels();

  bool isLabelName(const std::string &name);
  bool isLabelValue(uint value);

  void setLabelValue(const std::string &name, uint value);
  bool getLabelValue(const std::string &name, uint *value);

  void setValueLabel(uint value, const std::string &name);
  bool getValueLabel(uint value, std::string &name);

 private:
  LabelValueNameMap label_value_name_map_;
};

#endif
