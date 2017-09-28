int removeSpace(char *s, int len) {
    int i = 0;
    int j = 0;
    bool is_word = false;
    int word = 0;
    while(i < len)    {
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
            is_word = 1;
        }
        else if(is_word) {
            word++;
            is_word = 0;
        }
        i++;
    }
    return word;
}
