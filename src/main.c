#include <unistd.h>

#include "audio.c"

int main() {
    start_system_record("sounds/output.wav");
    sleep(3);
    stop_system_record();
    return 0;
}