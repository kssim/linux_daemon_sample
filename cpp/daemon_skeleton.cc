#include "daemon_skeleton.h"

DaemonSkeleton::DaemonSkeleton() {
  pid_file_ = "/var/run/"+DAEMON_NAME+".pid";

  InitSyslog();
}

DaemonSkeleton::~DaemonSkeleton() {
  RemovePidFile();
}

void DaemonSkeleton::Daemonize() {
  pid_t pid, sid;

  pid = fork();
  if (pid < 0) { exit(EXIT_FAILURE); }

  if (pid > 0) { exit(EXIT_SUCCESS); }

  umask(0);

  sid = setsid();
  if (sid < 0) { exit(EXIT_FAILURE); }

  if (chdir("/") < 0) { exit(EXIT_FAILURE); }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
}

void DaemonSkeleton::InitSyslog() {
  setlogmask(LOG_UPTO(LOG_INFO));
  openlog(DAEMON_NAME.c_str(), LOG_PID|LOG_CONS|LOG_NDELAY|LOG_PERROR, LOG_USER);
}

void DaemonSkeleton::CreatePidFile(pid_t pid) {
  std::ofstream pid_file(pid_file_);
  pid_file << pid << std::endl;
  pid_file.close();
}

void DaemonSkeleton::RemovePidFile() {
  if (remove(pid_file_.c_str()) != 0) {
    syslog(LOG_INFO, "The pid file was not deleted.");
  }
}

void DaemonSkeleton::Run() {
  syslog(LOG_INFO, "Before setting for daemonize");
  BeforeDaemonize();

  syslog(LOG_INFO, "Start daemonize");
  Daemonize();

  CreatePidFile(getpid());

  syslog(LOG_INFO, "After setting for daemonize");
  AfterDaemonize();

  syslog(LOG_INFO, "Start processing");
  while (true) {
      Processing();
  }

  RemovePidFile();
}
