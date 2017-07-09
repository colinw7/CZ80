#ifndef CZ80Macro_H
#define CZ80Macro_H

class CZ80Macro {
 public:
  typedef std::vector<std::string> ArgList;

 public:
  CZ80Macro(const std::string &name="", const ArgList &args=ArgList(), const std::string &body="") :
   name_(name), args_(args), body_(body) {
  }

  const ArgList     &getArgs() const { return args_; }
  const std::string &getBody() const { return body_; }

 private:
  std::string name_;
  ArgList     args_;
  std::string body_;
};

#endif
