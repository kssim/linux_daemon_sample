#ifndef DAEMON_SKELETON_
#define DAEMON_SKELETON_

#include <sys/stat.h>
#include <unistd.h>
#include <syslog.h>
#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>

const std::string DAEMON_NAME("skeleton");

class DaemonSkeleton {
 public:
  DaemonSkeleton();
  virtual ~DaemonSkeleton();
  void Run();

 protected:
  std::string pid_file_;
  virtual void BeforeDaemonize() {};
  virtual void AfterDaemonize() {};
  virtual void Processing() {};

 private:
  void InitSyslog();
  void Daemonize();
  void CreatePidFile(pid_t pid);
  void RemovePidFile();
};

#endif	// DAEMON_SKELETON_
