#include <Python.h>

typedef struct {
   char**   result;
   int      result_length;
} matchStringResult;

matchStringResult * match_string(const char * sample_str, const char * text_str) {
    matchStringResult * msr = malloc(sizeof(matchStringResult));
    msr->result_length = 1;
    msr->result = malloc(sizeof(msr->result) * 1);
    msr->result[0] = "test string";
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
        PyTuple_SetItem(t, i, PyUnicode_FromString(result->result[i]));
    }
    free(result->result);
    free(result);

    return t;
}

static PyMethodDef MatchStringMethods[] = {
    {"knuth_morris_pratt_algorithm", method_match_string, METH_VARARGS, "Python interface for match_string C library function"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef match_string_module = {
    PyModuleDef_HEAD_INIT,
    "knuth_morris_pratt_algorithm",
    "Python interface for the match_string C library function",
    -1,
    MatchStringMethods
};

PyMODINIT_FUNC PyInit_match_string(void) {
    return PyModule_Create(&match_string_module);
}
