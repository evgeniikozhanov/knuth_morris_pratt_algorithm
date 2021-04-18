#include <Python.h>

typedef struct {
   int*     result;
   int      result_length;
} matchStringResult;

int * compute_prefix_function(const char * s) {
    int m = sizeof(s);
    int * pi = malloc(sizeof(int) * m);
    pi[0] = 0;
    int k = -1;
    for (int i = 1; i < m - 1; i++) {
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
    int n = sizeof(text_str);
    int m = sizeof(sample_str);
    int * pi = compute_prefix_function(sample_str);
    int q = 0;
    for (int i = 0; i < n; i++) {
        while ((q > 0) && (sample_str[q + 1] != text_str[i])) {
            q = pi[q];
        }
        if (sample_str[q + 1] == text_str[i]) {
            ++q;
        }
        if (q == m) {
            msr->result_length += 1;
            msr->result = realloc(msr->result, sizeof(int) * msr->result_length);
            msr->result[msr->result_length - 1] = i - m + 1;
            q = pi[q];
        }
    }
    free(pi);
    return msr;
}

static PyObject * method_match_string(PyObject *self, PyObject *args) {
    char *sample_str, *text_str = NULL;

    if(!PyArg_ParseTuple(args, "ss", &sample_str, &text_str)) {
        return NULL;
    }

    matchStringResult * result = match_string(sample_str, text_str);

    PyObject *t;
    t = PyTuple_New(result->result_length);
    for (int i=0; i<result->result_length; i++) {
        PyTuple_SetItem(t, i, PyLong_FromLong(result->result[i]));
    }
    free(result->result);
    free(result);

    return t;
}

static PyMethodDef MatchStringMethods[] = {
    {"match_string", method_match_string, METH_VARARGS, "Python interface for match_string C library function"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef knuth_morris_pratt_algorithm_module = {
    PyModuleDef_HEAD_INIT,
    "knuth_morris_pratt_algorithm",
    "Python interface for the match_string C library function",
    -1,
    MatchStringMethods
};

PyMODINIT_FUNC PyInit_knuth_morris_pratt_algorithm(void) {
    return PyModule_Create(&knuth_morris_pratt_algorithm_module);
}
