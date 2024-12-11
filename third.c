#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *s21_memcpy(void *dest, const void *src, size_t n) {
  const unsigned char *ptr = (const unsigned char *)src;
  unsigned char *target = (unsigned char *)dest;
  for (size_t i = 0; i < n; i++) target[i] = ptr[i];
  return NULL;
}

char *s21_strchr(const char *str, int c) {
    while (*str != '\0' && *str != c) str++;
    if (*str == c) return (char *) str;
    return NULL;
}

size_t s21_strcspn(const char *str1, const char *str2) {
    unsigned char *str = (unsigned char *)str1;
    const unsigned char *ptr = (const unsigned char *)str2;
    size_t len = 0;
    while (*ptr != '\0' && *ptr != *str) {
        if (*str != '\0') {
            str++;
            len += 1;
        } else {
            str = (unsigned char *)str1;
            ptr++;
        }
    }
    return len;
}

char existed_char(const char *str, const char *substr) {
    while (*str != *substr) substr++;
    return *substr;
}

void add_char(char *s, char c) {
    while (*s++);
    *(s - 1) = c;
    *s = '\0';
}

char *s21_strpbrk(const char *str1, const char *str2) {
    int size = 256, count = 0;
    char *str = calloc(size, 1);
    for (; *str1 != '\0'; str1++) {
        if (count % 255 == 0) {
            size += 256;
            str = realloc(str, size);
        }
        if (existed_char(str1, str2) != '\0') {
            add_char(str, existed_char(str1, str2));
        }
        count++; 
    }
    if (str != NULL) return str;
    free(str);
    return NULL;
}

int is_delim(char c, const char *delim) {
    while (*delim != '\0') {
        if (c == *delim) return 1;
        delim++;
    }
    return 0;
}


char *s21_strtok(char *str, const char *delim) {
    static char *p;
    if (!str) str = p;
    char *returnvalue;
    int flag = 0;
    if (!str) return NULL;
    while (flag == 0) {
        if (is_delim(*str, delim)) str++;
        else if (*str == '\0') return NULL;
        else flag = 1;
    }
    char *ret = str;
    flag = 0;
    while (flag == 0) {
        if (*str == '\0') {
            p = str;
            returnvalue = ret;
            flag = 1;
        }
        if (is_delim(*str, delim)) {
            *str = '\0';
            p = str + 1;
            returnvalue = ret;
            flag = 1;
        }
        str++;
    }
    return returnvalue;
}

// void test_strpbrk(int n) {
//     char str1[] = "This is a sample string";
//     char str2[] = "aeiou";
//     if (n == 0) {
//         char *pch = strpbrk (str1, str2);
//         while (pch != NULL)
//         {
//             printf ("%c " , *pch);
//             pch = strpbrk (pch+1, str2);
//         }
//         printf("\n===\n");
//     } else {
//         char *pch = strpbrk (str1, str2);
//         while (pch != NULL)
//         {
//             printf ("%c " , *pch);
//             pch = strpbrk (pch+1, str2);
//         }
//     }
// }

// void test_strtok(int n) {
//     char str1[] = "This is a sample string";
//     char str2[] = " ";
//     if (n == 0) {
//         char *token;
//         token = strtok(str1, str2);
//         while( token != NULL ) {
//             printf( " %s\n", token );
//             token = strtok(NULL, str2);
//         }
//         printf("\n===\n");
//     } else {
//         char *token;
//         token = s21_strtok(str1, str2);
//         while( token != NULL ) {
//             printf( " %s\n", token );
//             token = s21_strtok(NULL, str2);
//         }
//     }
// }

// int main()
// {
//     // test_strpbrk(0);
//     // test_strpbrk(1);
//     // test_strtok(0);
//     // test_strtok(1);
//     return 0;
// }