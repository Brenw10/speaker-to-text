#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "audio.c"

int main() {
    mkdir("sounds");
    start_system_record("sounds/output.wav");
    sleep(3);
    stop_system_record();
    return 0;
}