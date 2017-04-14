#include "daemon_sample.h"

DaemonSample::DaemonSample() : DaemonTemplate("daemon_sample") {
  syslog(LOG_INFO, "Init sample class.");
}

void DaemonSample::BeforeDaemonize() {
  syslog(LOG_INFO, "Before sample daemonize");
}

void DaemonSample::AfterDaemonize() {
  syslog(LOG_INFO, "Aftersample daemonize");
}

void DaemonSample::Processing() {
  syslog(LOG_INFO, "Processing");
}
