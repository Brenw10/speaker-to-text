char* convert_int_to_string(int value) {
    int length = floor(log10(value)) + 1;
    char* count = (char*)malloc(length);
    itoa(value, count, 10);
    return count;
}