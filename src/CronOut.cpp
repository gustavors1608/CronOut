#include "CronOut.h"


CronOut::CronOut(unsigned long duration, CallbackFunction callback = nullptr) {
    if (callback != nullptr) {
        _callback = callback;
        _hasCallback = true;
    } else {
        _callback = nullptr;
        _hasCallback = true;
    }
    _duration = duration;
    _active = false;
}

void CronOut::start() {
    _startTime = millis();
    _active = true;
}

void CronOut::restart() {
    start();
}

void CronOut::cancel() {
    _active = false;
}

bool CronOut::hasTimedOut() {
    _checkTimeout();
    return !_active;
}

bool CronOut::isActive() {
    return _active;
}

void CronOut::_checkTimeout() {
    if (_active && (millis() - _startTime >= _duration)) {
        _active = false;
        if(_hasCallback == true){
            _callback();
        }
    }
}