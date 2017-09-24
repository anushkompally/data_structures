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

size_t strlen(char* str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

char* strcat (char* destination, const char* source)
{
    char *ptr = destination;
    while(*ptr != '\0')
    ptr++;

    while(*source != '\0')
    {
        *ptr++ = *source++;
    }
    *ptr = '\0';
    return destination;
}

char* strncat(char* destination, const char* source, size_t num)
{
    char *ptr = destination;
    while(*ptr != '\0')
    ptr++;
    
    while((*source != '\0') && num != 0)
    {
        *ptr++ = *source++;
        num--;
    }
    *ptr = '\0';
    return destination;
}

char* strcpy(char* destination, const char* source)
{
    char* ptr = destination;
    while(*source != '\0')
        *ptr++ = *source++;

    *ptr = '\0';
    return destination;
}

char* strncpy(char* destination, const char* source, size_t num)
{
    char* ptr = destination;

    while(*ptr != '\0')
        ptr++;

    while(num != 0 && *source != '\0')
        *ptr++ = *source++;
    *ptr = '\0';
    return destination;
}

char* strstr(const char* haystack, char* needle)
{
    // char* ptr1 = haystack;
    char* ptr2 = needle;
    int match = 0;
    while(*haystack != '\0' && *ptr2 != '\0')
    {
        if(*haystack == *ptr2)
        {   
            ptr2++;
            match = 1;
        }

        else
        {
            if(match == 1)
            {
                match = 0;   
                ptr2 = needle;
            }
        }
        haystack++;        
    }

    if(match == 1)
        return haystack - strlen(ptr2);
    else
        return -1;
}

