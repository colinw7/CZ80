#include <CZ80Execute.h>

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

  if (debugData_ != NULL)
    debugData_->callInitProcs();

  if (speed_data_ != NULL)
    speed_data_->init();

  execute1(true);

  if (debugData_ != NULL)
    debugData_->callTermProcs();

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

  if (debugData_ != NULL) {
    debugData_->addBreakpoint(pc1);

    debugData_->callPreStepProcs();
  }

  execute1(false);

  if (debugData_ != NULL) {
    debugData_->callPostStepProcs();

    removeBreakpoint(getPC());
  }

  return true;
}

bool
CZ80::
cont()
{
  if (debugData_ != NULL)
    debugData_->callPreStepProcs();

  execute1(true);

  if (debugData_ != NULL)
    debugData_->callPostStepProcs();

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

    if (debugData_ != NULL) {
      if (debugData_->isBreakpoint(getPC()))
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
  if (notify && debugData_ != NULL)
    debugData_->callPreStepProcs();

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

  if (notify && debugData_ != NULL)
    debugData_->callPostStepProcs();

  return true;
}

void
CZ80::
stop()
{
  stop_ = true;
}
