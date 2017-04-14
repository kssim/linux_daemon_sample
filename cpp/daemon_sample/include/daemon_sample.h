#ifndef DAEMON_SAMPLE_
#define DAEMON_SAMPLE_

#include <syslog.h>

#include <daemon_template.h>

class DaemonSample : public DaemonTemplate {
  public:
    DaemonSample();

  protected:
    virtual void BeforeDaemonize();
    virtual void AfterDaemonize();
    virtual void Processing();
};

#endif  // DAEMON_SAMPLE_
