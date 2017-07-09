#include <CZ80Execute.h>
#include <CZ80DebugData.h>
#include <CZ80SpeedData.h>
#include <CZ80ExecData.h>
#include <CZ80Screen.h>
#include <CZ80OpData.h>

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

  if (debugData_)
    debugData_->callInitProcs();

  if (speedData_)
    speedData_->init();

  cont();

  if (debugData_)
    debugData_->callTermProcs();

  return true;
}

bool
CZ80::
next()
{
  ushort pc = getPC();

  CZ80OpData opData;

  readOpData(pc, &opData);

  ushort pc1 = pc + opData.op->len;

  // run until pc at following instruction
  addBreakpoint(pc1);

  cont();

  removeBreakpoint(pc1);

  return true;
}

void
CZ80::
skip()
{
  ushort pc = getPC();

  CZ80OpData opData;

  readOpData(pc, &opData);

  ushort pc1 = pc + opData.op->len;

  setPC(pc1);
}

bool
CZ80::
cont()
{
  execute1(true);

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

    if (debugData_ && debugData_->isBreakpoint(getPC()))
      break;
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
  if (notify)
    callPreStepProcs();

  if (execData_)
    execData_->preStep();

  int r = 1;
  int t = 4;

  if (! getHalt()) {
    ushort pc = getPC();

    CZ80OpData opData;

    readOpData(pc, &opData);

    ushort pc1 = pc + opData.op->len;

    setPC(pc1);

    if (dump_)
      opData.dump(dump_file_);

    opData.execute();

    r = opData.op->r;
    t = opData.op->t;
  }

  incR(r);
  incT(t);

  if (execData_)
    execData_->postStep();

  if (screen_)
    screen_->screenStep(t);

  if (notify)
    callPostStepProcs();

  return true;
}

void
CZ80::
stop()
{
  setStop(true);
}
