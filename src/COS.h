namespace COS {
  void getHRTime(int *secs, int *usecs);

  void diffHRTime(int secs1, int usecs1, int secs2, int usecs2, int *decs, int *dusecs);

  uint msleep(uint msecs);
}
