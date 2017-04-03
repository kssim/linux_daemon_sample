#include "sample.h"

SampleClass::SampleClass() {
  syslog(LOG_INFO, "Init sample class.");
}

void SampleClass::BeforeDaemonize() {
  syslog(LOG_INFO, "Before sample daemonize");
}

void SampleClass::AfterDaemonize() {
  syslog(LOG_INFO, "Aftersample daemonize");
}

void SampleClass::Processing() {
  syslog(LOG_INFO, "Processing");
}
