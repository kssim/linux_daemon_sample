#include <stdio.h>
#include "daemon_sample.h"

int main(int argc, char** argv) {
    DaemonSample test = DaemonSample();
    test.Run();

    return 0;
}
