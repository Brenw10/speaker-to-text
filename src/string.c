char* convert_int_to_string(int value) {
    int length = floor(log10(abs(value))) + 1;
    char* count = (char*)malloc(length);
    itoa(value, count, 10);
    return count;
}

char* concat_string(char* values[], int length) {
    int length_string = 0;
    for (int i = 0; i < length; i++) length_string += strlen(values[i]);
    char* string = (char*)malloc(length_string);
    strcpy(string, values[0]);
    for (int i = 1; i < length; i++) strcat(string, values[i]);
    return string;
}