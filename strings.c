int strStr(char* haystack, char* needle) {
    int i;
    int j = 0;
    if(strlen(haystack) == 0 && (strlen(needle)) == 0)
        return 0;
    for(i = 0;i<strlen(haystack);i++)
    {
        if(haystack[i] == needle[j])
        {
            j++;
        }
        else
            j=0;


        if(j == strlen(needle))
            break;

    }

    return i-j+1;
}
