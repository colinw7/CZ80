#include <CZ80LabelData.h>
#include <CZ80.h>
#include <CZ80Op.h>
#include <CStrUtil.h>

#ifdef CL_PARSER
#include <CCeilP.h>
#endif

void
CZ80LabelData::
clearLabels()
{
#ifdef CL_PARSER
  ClParserInst->deleteAllVariables();
#endif

  label_value_name_map_.clear();
}

bool
CZ80LabelData::
isLabelName(const std::string &name)
{
#ifdef CL_PARSER
  return ClParserInst->isVariable(name);
#else
  assert(name.size());

  return false;
#endif
}

bool
CZ80LabelData::
isLabelValue(uint value)
{
  return (label_value_name_map_.find(value) != label_value_name_map_.end());
}

void
CZ80LabelData::
setLabelValue(const std::string &name, uint value)
{
#ifdef CL_PARSER
  ClParserVarPtr var = ClParserInst->getVariable(name, true);

  var->setValue(ClParserValueMgrInst->createValue(long(value)));
#endif

  label_value_name_map_[value] = name;
}

bool
CZ80LabelData::
getLabelValue(const std::string &name, uint *value)
{
#ifdef CL_PARSER
  ClParserValuePtr pvalue = ClParserInst->getVariableValue(name);

  if (! pvalue.isValid())
    return false;

  long value1;

  if (! pvalue->integerValue(&value1))
    return false;

  *value = uint(value1);

  return true;
#else
  assert(name.size());

  *value = 0;

  return false;
#endif
}

void
CZ80LabelData::
setValueLabel(uint value, const std::string &name)
{
  setLabelValue(name, value);
}

bool
CZ80LabelData::
getValueLabel(uint value, std::string &name)
{
  auto p = label_value_name_map_.find(value);

  if (p == label_value_name_map_.end())
    return false;

  name = (*p).second;

  return true;
}
