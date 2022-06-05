
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *freadline(FILE *fp) {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;

    do {

        n = fscanf(fp, "%80[^\n]", buf);

        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            fscanf(fp, "%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }

    return res;
}

char *sumStrings(char *s1, char *s2) {
    if (s1 == NULL) {
        char *result = (char *) malloc(strlen(s2) + 1);
        memcpy(result, s2, strlen(s2) + 1);
        return result;
    }
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *result = (char *) malloc(len1 + len2 + 1);
    if (result == NULL)
        return NULL;
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;
}

char *remove_chars(char *string, int index) {
    char *out = calloc(strlen(string) - 1, sizeof(char));

    int i, j;

    for (i = j = 0; string[i] != '\0'; i++)
        if (i != index)
            out[j++] = string[i];
    out[j] = '\0';

    return out;
}

char *cut_sting(char *string, int till) {
    char *out = calloc(strlen(string) - till,sizeof(char));

    for (int i = till; i <= strlen(string); i++) {
        out[i - till] = string[i];
    }
    return out;
}