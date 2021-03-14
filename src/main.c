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
        char records_filepath[strlen(record_path) + strlen(index_str) + strlen(extension)];
        strcpy(records_filepath, record_path);
        strcat(records_filepath, index_str);
        strcat(records_filepath, extension);

        start_system_record(records_filepath);
        sleep(3);
        stop_system_record();

        char sounds_filepath[strlen(sounds_path) + strlen(index_str) + strlen(extension)];
        strcpy(sounds_filepath, sounds_path);
        strcat(sounds_filepath, index_str);
        strcat(sounds_filepath, extension);

        char converter_cmd[strlen(wav_converter) + 1 + strlen(records_filepath) + 1 + strlen(sounds_filepath)];
        strcpy(converter_cmd, wav_converter);
        strcat(converter_cmd, " ");
        strcat(converter_cmd, records_filepath);
        strcat(converter_cmd, " ");
        strcat(converter_cmd, sounds_filepath);

        system(converter_cmd);

        char recognition_cmd[strlen(recognition) + 1 + strlen(sounds_filepath)];
        strcpy(recognition_cmd, recognition);
        strcat(recognition_cmd, " ");
        strcat(recognition_cmd, sounds_filepath);

        system(recognition_cmd);

        remove(records_filepath);
        remove(sounds_filepath);
    }

    return 0;
}