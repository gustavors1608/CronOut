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
    typedef void (*CallbackFunction)();
    unsigned long _duration;
    unsigned long _startTime;
    bool _hasCallback;
    bool _active;
    void (*_callback)();
    void _checkTimeout();
};

#endif
