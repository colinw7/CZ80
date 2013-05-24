#include <CZ80.h>
#include <CZ80Op.h>
#include <CStrUtil.h>

bool
CZ80::
execute()
{
  return execute(load_pos_);
}

bool
CZ80::
execute(ushort pos)
{
  setPC(pos);

  if (debug_data_ != NULL)
    debug_data_->callInitProcs();

  if (speed_data_ != NULL)
    speed_data_->init();

  execute1(true);

  if (debug_data_ != NULL)
    debug_data_->callTermProcs();

  return true;
}

bool
CZ80::
next()
{
  ushort pc   = getPC();
  bool   halt = getHalt();

  CZ80OpData op_data;

  readOpData(&op_data);

  ushort pc1 = getPC();

  setPC  (pc);
  setHalt(halt);

  if (debug_data_ != NULL) {
    debug_data_->addBreakpoint(pc1);

    debug_data_->callPreStepProcs();
  }

  execute1(false);

  if (debug_data_ != NULL) {
    debug_data_->callPostStepProcs();

    removeBreakpoint(getPC());
  }

  return true;
}

bool
CZ80::
cont()
{
  if (debug_data_ != NULL)
    debug_data_->callPreStepProcs();

  execute1(true);

  if (debug_data_ != NULL)
    debug_data_->callPostStepProcs();

  return true;
}

bool
CZ80::
execute1(bool notify)
{
  while (true) {
    step1(notify);

    if (getHalt() || getStop())
      break;

    if (debug_data_ != NULL) {
      if (debug_data_->isBreakpoint(getPC()))
        break;
    }
  }

  setStop(false);

  return true;
}

bool
CZ80::
step()
{
  return step1(true);
}

bool
CZ80::
step1(bool notify)
{
  if (notify && debug_data_ != NULL)
    debug_data_->callPreStepProcs();

  if (! getHalt()) {
    CZ80OpData op_data;

    readOpData(&op_data);

    if (dump_)
      op_data.dump(dump_file_);

    op_data.execute();

    incR(op_data.op->r);
    incT(op_data.op->t);
  }
  else {
    incR(1);
    incT(4);
  }

  if (notify && debug_data_ != NULL)
    debug_data_->callPostStepProcs();

  return true;
}

void
CZ80::
stop()
{
  stop_ = true;
}
