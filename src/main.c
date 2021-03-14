#include <stdio.h>
#include <unistd.h>

#include "audio.c"
#include "string.c"

int main() {
    char record_path[] = "records/";
    char sounds_path[] = "sounds/";
    char extension[] = ".wav";
    char wav_converter[] = "py src/scripts/wavconverter.py";
    char recognition[] = "py src/scripts/recognition.py";

    mkdir(record_path);
    mkdir(sounds_path);

    int i = 0;
    for (;;) {
        char* index_str = convert_int_to_string(++i);
        char* records_filepath = concat_string((char*[]){record_path, index_str, extension}, 3);
        char* sounds_filepath = concat_string((char*[]){sounds_path, index_str, extension}, 3);
        char* converter_cmd = concat_string((char*[]){wav_converter, " ", records_filepath, " ", sounds_filepath}, 5);
        char* recognition_cmd = concat_string((char*[]){recognition, " ", sounds_filepath}, 3);

        start_system_record(records_filepath);
        sleep(3);
        stop_system_record();

        system(converter_cmd);
        system(recognition_cmd);

        remove(records_filepath);
        remove(sounds_filepath);
    }

    return 0;
}