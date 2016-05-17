string removeSpace(char *s, int len) {
    int i = 0;
    int j = 0;
    while(i < len)    {
        if(s[i] == ' ') {
            i++;
            continue;            
        }            
        s[j++] = s[i++];
    }
    if(j < i)
        s[j] = '\0';
    return s;
}
