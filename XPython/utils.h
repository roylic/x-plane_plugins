#ifndef UTILS__H
#define UTILS__H

#define My_DOCSTR(name,method,parms,str) static const char name[] = method"($module, /, "parms")\n--\n\n"str
extern const char *objRefName;
extern const char *commandRefName;
extern const char *widgetRefName;
extern const char *windowIDRef;
extern PyObject *widgetIDCapsules;
extern PyObject *windowIDCapsules;
extern PyObject *xppythonDicts;
extern PyObject *xppythonCapsules;
extern FILE *pythonLogFile;
extern int pythonDebugs;
extern int pythonWarnings;

void dbg(const char *msg);
float getFloatFromTuple(PyObject *seq, Py_ssize_t i);
long getLongFromTuple(PyObject *seq, Py_ssize_t i);
void pythonLogException(void);

PyObject *getPtrRef(void *ptr, PyObject *dict, const char *refName);
PyObject *getPtrRefOneshot(void *ptr, const char *refName);
void *refToPtr(PyObject *ref, const char *refName);
void removePtrRef(void *ptr, PyObject *dict);
char *get_moduleName();
PyObject *get_pluginSelf();
char *objToStr(PyObject *item);
char *objDebug(PyObject *item);
void pythonLogWarning(const char *msg);
void pythonDebug(const char *fmt, ...);

extern const char *pythonPluginsPath;
extern const char *pythonInternalPluginsPath;

#endif
