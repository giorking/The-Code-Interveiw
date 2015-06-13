void reverse(char *str) {
    char *end = str;
    if (str) {
        while (*end) {
            ++ end;
        }
        -- end;
        char temp;
        while (str < end) {
            temp = *str;
            *str++ = *end;
            *end-- = temp;
        }
    }
}