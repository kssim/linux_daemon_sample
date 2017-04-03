#ifndef SAMPLE_
#define SAMPLE_

#include <syslog.h>

#include "daemon_skeleton.h"

class SampleClass : public DaemonSkeleton {
  public:
    SampleClass();

  protected:
    virtual void BeforeDaemonize();
    virtual void AfterDaemonize();
    virtual void Processing();
};

#endif  // SAMPLE_
