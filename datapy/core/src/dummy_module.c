/* -*- c -*- */

/*
 * This is a dummy module whose purpose is to ensure the flow is correct.
 */

#include <Python.h>

/* This declares the logit function */
static PyObject *spam_logit(PyObject *self, PyObject *args);

/*
 * This tells Python what methods this module has.
 * See the Python-C API for more information.
 */
static PyMethodDef SpamMethods[] = {
    {"logit",
     spam_logit,
     METH_VARARGS, "compute logit"},
    {NULL, NULL, 0, NULL}};

/*
 * This actually defines the logit function for
 * input args from Python.
 */
static PyObject *spam_logit(PyObject *self, PyObject *args)
{
    double p;

    /* This parses the Python argument into a double */
    if (!PyArg_ParseTuple(args, "d", &p))
    {
        return NULL;
    }

    /* THE ACTUAL LOGIT FUNCTION */
    p = p / (1 - p);
    p = log(p);

    /*This builds the answer back into a python object */
    return Py_BuildValue("d", p);
}

/* This initiates the module using the above definitions. */
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "dummy",
    NULL,
    -1,
    SpamMethods,
    NULL,
    NULL,
    NULL,
    NULL};

PyMODINIT_FUNC PyInit_dummy(void)
{
    PyObject *m;
    m = PyModule_Create(&moduledef);
    if (!m)
    {
        return NULL;
    }
    return m;
}