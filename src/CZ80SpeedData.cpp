#include <CZ80.h>
#include <CZ80Op.h>
#include <CStrUtil.h>
#include <COS.h>

void
CZ80SpeedData::
init()
{
  static bool initialized = false;

  if (! initialized) {
    COS::getHRTime(&secs_, &usecs_);

    initialized = true;
  }
}

void
CZ80SpeedData::
interrupt()
{
  calcMhz();
}

void
CZ80SpeedData::
calcMhz()
{
  static int count;
  static int itime = 2000;

  int secs, usecs, dsecs, dusecs;

  init();

  COS::getHRTime(&secs, &usecs);

  COS::diffHRTime(secs_, usecs_, secs, usecs, &dsecs, &dusecs);

  long dusecs1 = dusecs + 1000000*dsecs;

  if (dusecs1 < itime) {
    COS::msleep(itime - dusecs1);

    COS::getHRTime(&secs, &usecs);

    COS::diffHRTime(secs_, usecs_, secs, usecs, &dsecs, &dusecs);

    dusecs1 = dusecs + 1000000*dsecs;
  }

  secs_  = secs;
  usecs_ = usecs;

  // calc cycles per second

  mhz_ = (1.0*z80_.getIFreq())/dusecs1;

  if (count == 50) {
    output();

    count = 0;
  }
  else
    ++count;
}

void
CZ80SpeedData::
output()
{
  std::cerr << mhz_ << "Mhz" << std::endl;
}
