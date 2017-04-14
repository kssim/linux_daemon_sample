#include "daemon_template.h"

DaemonTemplate::DaemonTemplate(const std::string &daemon_name) {
  _daemon_name = daemon_name;

  pid_file_ = "/var/run/"+_daemon_name+".pid";
  InitSyslog();
}

DaemonTemplate::~DaemonTemplate() {
  RemovePidFile();
}

void DaemonTemplate::Daemonize() {
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

void DaemonTemplate::InitSyslog() {
  setlogmask(LOG_UPTO(LOG_INFO));
  openlog(_daemon_name.c_str(), LOG_PID|LOG_CONS|LOG_NDELAY|LOG_PERROR, LOG_USER);
}

void DaemonTemplate::CreatePidFile(pid_t pid) {
  std::ofstream pid_file(pid_file_);
  pid_file << pid << std::endl;
  pid_file.close();
}

void DaemonTemplate::RemovePidFile() {
  if (remove(pid_file_.c_str()) != 0) {
    syslog(LOG_INFO, "The pid file was not deleted.");
  }
}

void DaemonTemplate::Run() {
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
