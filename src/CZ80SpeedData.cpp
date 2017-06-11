#include <CZ80SpeedData.h>

void
CZ80SpeedData::
init()
{
  static bool initialized = false;

  if (! initialized) {
    COSTime::getHRTime(&secs_, &usecs_);

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

  COSTime::getHRTime(&secs, &usecs);

  COSTime::diffHRTime(secs_, usecs_, secs, usecs, &dsecs, &dusecs);

  long dusecs1 = dusecs + 1000000*dsecs;

  if (dusecs1 < itime) {
    COSTimer::msleep(itime - dusecs1);

    COSTime::getHRTime(&secs, &usecs);

    COSTime::diffHRTime(secs_, usecs_, secs, usecs, &dsecs, &dusecs);

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
