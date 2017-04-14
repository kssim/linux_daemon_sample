#ifndef DAEMON_TEMPLATE_
#define DAEMON_TEMPLATE_

#include <sys/stat.h>
#include <unistd.h>
#include <syslog.h>
#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>

class DaemonTemplate {
 public:
  DaemonTemplate(const std::string &daemon_name);
  virtual ~DaemonTemplate();
  void Run();

 protected:
  virtual void BeforeDaemonize() {};
  virtual void AfterDaemonize() {};
  virtual void Processing() {};

 private:
  std::string pid_file_;
  std::string _daemon_name;
  void InitSyslog();
  void Daemonize();
  void CreatePidFile(pid_t pid);
  void RemovePidFile();
};

#endif	// DAEMON_TEMPLATE_
