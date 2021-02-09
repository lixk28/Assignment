int myStrlen(char a[]) {
    int count = 0;
    for(int i = 0; a[i] != '\0'; i++)
        count++;
    return count;
}

int myStrcmp(char a[], char b[]) {
    for(int i = 0, j = 0; i < myStrlen(a) && j < myStrlen(b); i++, j++)
    {
        if(a[i] == b[i])
            continue;
        else if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return -1;
    }
}

void myStrcpy(char des[], char src[]) {
    int i = 0;
    while(src[i] != '\0')
    {
        des[i] = src[i];
        i++;
    }
    while(des[i] != '\0')
    {
        des[i] = '\0';
        i++;
    }
}