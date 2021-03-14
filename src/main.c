#include <unistd.h>

#include "audio.c"
#include "string.c"

int main() {
    char record_path[] = "records/";
    char sounds_path[] = "sounds/";
    char extension[] = ".wav";

    mkdir(record_path);
    mkdir(sounds_path);

    char* index_str = convert_int_to_string(1);
    char record_filepath[strlen(record_path) + strlen(index_str) + strlen(extension)];
    strcpy(record_filepath, record_path);
    strcat(record_filepath, index_str);
    strcat(record_filepath, extension);

    start_system_record(record_filepath);
    sleep(3);
    stop_system_record();

    system("py src/scripts/wavconverter.py records/1.wav sounds/1.wav");
    
    return 0;
}