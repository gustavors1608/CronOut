#ifndef CronOut_h
#define CronOut_h

#include <Arduino.h>

class CronOut {
  public:
    CronOut(unsigned long duration, void (*callback)());
    void start();
    void restart();
    void cancel();
    bool hasTimedOut();
    bool isActive();

  private:
    unsigned long _duration;
    unsigned long _startTime;
    bool _active;
    bool _hasCallback;
    void (*_callback)();
    void _checkTimeout();
};

#endif
