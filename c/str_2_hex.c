*
 translate hex string to hex
*/
int str_2_hex(char* str, char* hex, int* len)
{
    int slen, i, j, offset;
    char tmp[3] = {0};
    
    slen = strlen_my(str);
    if (slen <= 0) return RET_FAIL;

    // if hex string start with '0x'
    if ((str[0] == '0') && (str[1] == 'x')) {
        *len = slen/2 + slen%2 - 1;
        offset = 2;
    }
    else {
        *len = slen/2 + slen%2;
        offset = 0;
    }

    // check if the hex string is right char
    for (i = offset; i < slen; i++) {
        if ((str[i] >= '0' && str[i] <= '9') ||
           (str[i] >= 'a' && str[i] <= 'f') ||
           (str[i] >= 'A' && str[i] <= 'F')) {
        }
        else {
            printf("Unsupported hex char.\n");
            return RET_FAIL;
        }
    }

    if (slen%2) {
        tmp[0] = '0';
        tmp[1] = str[offset];
        hex[0] = strtoul(tmp, NULL, 16);
        for (i = offset + 1, j = 1; i < slen; i += 2, j++) {
            tmp[0] = str[i];
            tmp[1] = str[i+1];
            hex[j] = strtoul(tmp, NULL, 16);
        }
    }
    else {
        for (i = offset, j = 0; i < slen; i += 2, j++) {
            tmp[0] = str[i];
            tmp[1] = str[i+1];
            hex[j] = strtoul(tmp, NULL, 16);
        }
    }

    return RET_SUCCESS;
}
