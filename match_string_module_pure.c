#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
   int*     result;
   int      result_length;
} matchStringResult;

int * compute_prefix_function(const char * s) {
    int m = sizeof(s);
    int * pi = malloc(sizeof(int) * m);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < m; i++) {
        k = pi[i - 1];
        while ((k > 0) && (s[i] != s[k])) {
             k = pi[k - 1];
        }
        if (s[i] == s[k]) {
            ++k;
        }
        pi[i] = k;
    }
    return pi;
}

matchStringResult * match_string(const char * sample_str, const char * text_str) {
    matchStringResult * msr = malloc(sizeof(matchStringResult));
    msr->result_length = 0;
    msr->result = malloc(sizeof(int));
    int n = strlen(text_str);
    int m = strlen(sample_str);
    int * pi = compute_prefix_function(sample_str);
    int q = 0;
    for (int i = 0; i < n; i++) {
        while ((q > 0) && (sample_str[q] != text_str[i])) {
            q = pi[q - 1];
        }
        if (sample_str[q] == text_str[i]) {
            ++q;
        }
        if (q == m) {
            msr->result_length += 1;
            msr->result = realloc(msr->result, sizeof(int) * msr->result_length);
            msr->result[msr->result_length - 1] = i - m + 1;
            q = pi[q - 1];
        }
    }
    free(pi);
    return msr;
}

int main(void) {
    matchStringResult * res;
    char * s = "ear";
    char * t = "dusfhuhhearjklfdjearjkdfl";
    res = match_string(s, t);
    printf("Results count: %d\n", res->result_length);
    for (int i = 0; i < res->result_length; i++) {
        printf("%d\n", res->result[i]);
    }
    free(res->result);
    free(res);
    return 0;
}
