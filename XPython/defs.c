//Python comes first!
#include <Python.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdbool.h>
#include <XPLM/XPLMDefs.h>

static PyObject *cleanup(PyObject *self, PyObject *args)
{
  (void) self;
  (void) args;
  Py_RETURN_NONE;
}

static PyMethodDef XPLMDefsMethods[] = {
  {"_cleanup", cleanup, METH_VARARGS, ""},
  {NULL, NULL, 0, NULL}
};



static struct PyModuleDef XPLMDefsModule = {
  PyModuleDef_HEAD_INIT,
  "XPLMDefs",
  "Laminar documentation: \n"
  "   https://developer.x-plane.com/sdk/XPLMDefs/\n"
  "XPPython3 documentation: \n"
  "   https://xppython3.rtfd.io/en/stable/development/modules/defs.html",
  -1,
  XPLMDefsMethods,
  NULL,
  NULL,
  NULL,
  NULL
};

PyMODINIT_FUNC
PyInit_XPLMDefs(void)
{
  PyObject *mod = PyModule_Create(&XPLMDefsModule);
  if(mod != NULL){
    PyModule_AddStringConstant(mod, "__author__", "Peter Buckner (xppython3@avnwx.com)");
    PyModule_AddIntConstant(mod, "XPLM_NO_PLUGIN_ID", XPLM_NO_PLUGIN_ID);
    PyModule_AddIntConstant(mod, "XPLM_PLUGIN_XPLANE", XPLM_PLUGIN_XPLANE);
    PyModule_AddIntConstant(mod, "kXPLM_Version", kXPLM_Version);
    PyModule_AddIntConstant(mod, "NO_PLUGIN_ID", XPLM_NO_PLUGIN_ID);
    PyModule_AddIntConstant(mod, "PLUGIN_XPLANE", XPLM_PLUGIN_XPLANE);
    PyModule_AddIntConstant(mod, "kVersion", kXPLM_Version);

    PyModule_AddIntConstant(mod, "xplm_ShiftFlag", xplm_ShiftFlag);
    PyModule_AddIntConstant(mod, "xplm_OptionAltFlag", xplm_OptionAltFlag);
    PyModule_AddIntConstant(mod, "xplm_ControlFlag", xplm_ControlFlag);
    PyModule_AddIntConstant(mod, "xplm_DownFlag", xplm_DownFlag);
    PyModule_AddIntConstant(mod, "xplm_UpFlag", xplm_UpFlag);

    PyModule_AddIntConstant(mod, "ShiftFlag", xplm_ShiftFlag);
    PyModule_AddIntConstant(mod, "OptionAltFlag", xplm_OptionAltFlag);
    PyModule_AddIntConstant(mod, "ControlFlag", xplm_ControlFlag);
    PyModule_AddIntConstant(mod, "DownFlag", xplm_DownFlag);
    PyModule_AddIntConstant(mod, "UpFlag", xplm_UpFlag);

    PyModule_AddIntConstant(mod, "XPLM_KEY_RETURN", XPLM_KEY_RETURN);
    PyModule_AddIntConstant(mod, "XPLM_KEY_ESCAPE", XPLM_KEY_ESCAPE);
    PyModule_AddIntConstant(mod, "XPLM_KEY_TAB", XPLM_KEY_TAB);
    PyModule_AddIntConstant(mod, "XPLM_KEY_DELETE", XPLM_KEY_DELETE);
    PyModule_AddIntConstant(mod, "XPLM_KEY_LEFT", XPLM_KEY_LEFT);
    PyModule_AddIntConstant(mod, "XPLM_KEY_RIGHT", XPLM_KEY_RIGHT);
    PyModule_AddIntConstant(mod, "XPLM_KEY_UP", XPLM_KEY_UP);
    PyModule_AddIntConstant(mod, "XPLM_KEY_DOWN", XPLM_KEY_DOWN);
    PyModule_AddIntConstant(mod, "XPLM_KEY_0", XPLM_KEY_0);
    PyModule_AddIntConstant(mod, "XPLM_KEY_1", XPLM_KEY_1);
    PyModule_AddIntConstant(mod, "XPLM_KEY_2", XPLM_KEY_2);
    PyModule_AddIntConstant(mod, "XPLM_KEY_3", XPLM_KEY_3);
    PyModule_AddIntConstant(mod, "XPLM_KEY_4", XPLM_KEY_4);
    PyModule_AddIntConstant(mod, "XPLM_KEY_5", XPLM_KEY_5);
    PyModule_AddIntConstant(mod, "XPLM_KEY_6", XPLM_KEY_6);
    PyModule_AddIntConstant(mod, "XPLM_KEY_7", XPLM_KEY_7);
    PyModule_AddIntConstant(mod, "XPLM_KEY_8", XPLM_KEY_8);
    PyModule_AddIntConstant(mod, "XPLM_KEY_9", XPLM_KEY_9);
    PyModule_AddIntConstant(mod, "XPLM_KEY_DECIMAL", XPLM_KEY_DECIMAL);

    PyModule_AddIntConstant(mod, "KEY_RETURN", XPLM_KEY_RETURN);
    PyModule_AddIntConstant(mod, "KEY_ESCAPE", XPLM_KEY_ESCAPE);
    PyModule_AddIntConstant(mod, "KEY_TAB", XPLM_KEY_TAB);
    PyModule_AddIntConstant(mod, "KEY_DELETE", XPLM_KEY_DELETE);
    PyModule_AddIntConstant(mod, "KEY_LEFT", XPLM_KEY_LEFT);
    PyModule_AddIntConstant(mod, "KEY_RIGHT", XPLM_KEY_RIGHT);
    PyModule_AddIntConstant(mod, "KEY_UP", XPLM_KEY_UP);
    PyModule_AddIntConstant(mod, "KEY_DOWN", XPLM_KEY_DOWN);
    PyModule_AddIntConstant(mod, "KEY_0", XPLM_KEY_0);
    PyModule_AddIntConstant(mod, "KEY_1", XPLM_KEY_1);
    PyModule_AddIntConstant(mod, "KEY_2", XPLM_KEY_2);
    PyModule_AddIntConstant(mod, "KEY_3", XPLM_KEY_3);
    PyModule_AddIntConstant(mod, "KEY_4", XPLM_KEY_4);
    PyModule_AddIntConstant(mod, "KEY_5", XPLM_KEY_5);
    PyModule_AddIntConstant(mod, "KEY_6", XPLM_KEY_6);
    PyModule_AddIntConstant(mod, "KEY_7", XPLM_KEY_7);
    PyModule_AddIntConstant(mod, "KEY_8", XPLM_KEY_8);
    PyModule_AddIntConstant(mod, "KEY_9", XPLM_KEY_9);
    PyModule_AddIntConstant(mod, "KEY_DECIMAL", XPLM_KEY_DECIMAL);

    PyModule_AddIntConstant(mod, "XPLM_VK_BACK", XPLM_VK_BACK);
    PyModule_AddIntConstant(mod, "XPLM_VK_TAB", XPLM_VK_TAB);
    PyModule_AddIntConstant(mod, "XPLM_VK_CLEAR", XPLM_VK_CLEAR);
    PyModule_AddIntConstant(mod, "XPLM_VK_RETURN", XPLM_VK_RETURN);
    PyModule_AddIntConstant(mod, "XPLM_VK_ESCAPE", XPLM_VK_ESCAPE);
    PyModule_AddIntConstant(mod, "XPLM_VK_SPACE", XPLM_VK_SPACE);
    PyModule_AddIntConstant(mod, "XPLM_VK_PRIOR", XPLM_VK_PRIOR);
    PyModule_AddIntConstant(mod, "XPLM_VK_NEXT", XPLM_VK_NEXT);
    PyModule_AddIntConstant(mod, "XPLM_VK_END", XPLM_VK_END);
    PyModule_AddIntConstant(mod, "XPLM_VK_HOME", XPLM_VK_HOME);
    PyModule_AddIntConstant(mod, "XPLM_VK_LEFT", XPLM_VK_LEFT);
    PyModule_AddIntConstant(mod, "XPLM_VK_UP", XPLM_VK_UP);
    PyModule_AddIntConstant(mod, "XPLM_VK_RIGHT", XPLM_VK_RIGHT);
    PyModule_AddIntConstant(mod, "XPLM_VK_DOWN", XPLM_VK_DOWN);
    PyModule_AddIntConstant(mod, "XPLM_VK_SELECT", XPLM_VK_SELECT);
    PyModule_AddIntConstant(mod, "XPLM_VK_PRINT", XPLM_VK_PRINT);
    PyModule_AddIntConstant(mod, "XPLM_VK_EXECUTE", XPLM_VK_EXECUTE);
    PyModule_AddIntConstant(mod, "XPLM_VK_SNAPSHOT", XPLM_VK_SNAPSHOT);
    PyModule_AddIntConstant(mod, "XPLM_VK_INSERT", XPLM_VK_INSERT);
    PyModule_AddIntConstant(mod, "XPLM_VK_DELETE", XPLM_VK_DELETE);
    PyModule_AddIntConstant(mod, "XPLM_VK_HELP", XPLM_VK_HELP);
/* XPLM_VK_0 thru XPLM_VK_9 are the same as ASCII '0' thru '9' (0x30 - 0x39)   */
    PyModule_AddIntConstant(mod, "XPLM_VK_0", XPLM_VK_0);
    PyModule_AddIntConstant(mod, "XPLM_VK_1", XPLM_VK_1);
    PyModule_AddIntConstant(mod, "XPLM_VK_2", XPLM_VK_2);
    PyModule_AddIntConstant(mod, "XPLM_VK_3", XPLM_VK_3);
    PyModule_AddIntConstant(mod, "XPLM_VK_4", XPLM_VK_4);
    PyModule_AddIntConstant(mod, "XPLM_VK_5", XPLM_VK_5);
    PyModule_AddIntConstant(mod, "XPLM_VK_6", XPLM_VK_6);
    PyModule_AddIntConstant(mod, "XPLM_VK_7", XPLM_VK_7);
    PyModule_AddIntConstant(mod, "XPLM_VK_8", XPLM_VK_8);
    PyModule_AddIntConstant(mod, "XPLM_VK_9", XPLM_VK_9);
/* XPLM_VK_A thru XPLM_VK_Z are the same as ASCII 'A' thru 'Z' (0x41 - 0x5A)   */
    PyModule_AddIntConstant(mod, "XPLM_VK_A", XPLM_VK_A);
    PyModule_AddIntConstant(mod, "XPLM_VK_B", XPLM_VK_B);
    PyModule_AddIntConstant(mod, "XPLM_VK_C", XPLM_VK_C);
    PyModule_AddIntConstant(mod, "XPLM_VK_D", XPLM_VK_D);
    PyModule_AddIntConstant(mod, "XPLM_VK_E", XPLM_VK_E);
    PyModule_AddIntConstant(mod, "XPLM_VK_F", XPLM_VK_F);
    PyModule_AddIntConstant(mod, "XPLM_VK_G", XPLM_VK_G);
    PyModule_AddIntConstant(mod, "XPLM_VK_H", XPLM_VK_H);
    PyModule_AddIntConstant(mod, "XPLM_VK_I", XPLM_VK_I);
    PyModule_AddIntConstant(mod, "XPLM_VK_J", XPLM_VK_J);
    PyModule_AddIntConstant(mod, "XPLM_VK_K", XPLM_VK_K);
    PyModule_AddIntConstant(mod, "XPLM_VK_L", XPLM_VK_L);
    PyModule_AddIntConstant(mod, "XPLM_VK_M", XPLM_VK_M);
    PyModule_AddIntConstant(mod, "XPLM_VK_N", XPLM_VK_N);
    PyModule_AddIntConstant(mod, "XPLM_VK_O", XPLM_VK_O);
    PyModule_AddIntConstant(mod, "XPLM_VK_P", XPLM_VK_P);
    PyModule_AddIntConstant(mod, "XPLM_VK_Q", XPLM_VK_Q);
    PyModule_AddIntConstant(mod, "XPLM_VK_R", XPLM_VK_R);
    PyModule_AddIntConstant(mod, "XPLM_VK_S", XPLM_VK_S);
    PyModule_AddIntConstant(mod, "XPLM_VK_T", XPLM_VK_T);
    PyModule_AddIntConstant(mod, "XPLM_VK_U", XPLM_VK_U);
    PyModule_AddIntConstant(mod, "XPLM_VK_V", XPLM_VK_V);
    PyModule_AddIntConstant(mod, "XPLM_VK_W", XPLM_VK_W);
    PyModule_AddIntConstant(mod, "XPLM_VK_X", XPLM_VK_X);
    PyModule_AddIntConstant(mod, "XPLM_VK_Y", XPLM_VK_Y);
    PyModule_AddIntConstant(mod, "XPLM_VK_Z", XPLM_VK_Z);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD0", XPLM_VK_NUMPAD0);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD1", XPLM_VK_NUMPAD1);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD2", XPLM_VK_NUMPAD2);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD3", XPLM_VK_NUMPAD3);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD4", XPLM_VK_NUMPAD4);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD5", XPLM_VK_NUMPAD5);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD6", XPLM_VK_NUMPAD6);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD7", XPLM_VK_NUMPAD7);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD8", XPLM_VK_NUMPAD8);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD9", XPLM_VK_NUMPAD9);
    PyModule_AddIntConstant(mod, "XPLM_VK_MULTIPLY", XPLM_VK_MULTIPLY);
    PyModule_AddIntConstant(mod, "XPLM_VK_ADD", XPLM_VK_ADD);
    PyModule_AddIntConstant(mod, "XPLM_VK_SEPARATOR", XPLM_VK_SEPARATOR);
    PyModule_AddIntConstant(mod, "XPLM_VK_SUBTRACT", XPLM_VK_SUBTRACT);
    PyModule_AddIntConstant(mod, "XPLM_VK_DECIMAL", XPLM_VK_DECIMAL);
    PyModule_AddIntConstant(mod, "XPLM_VK_DIVIDE", XPLM_VK_DIVIDE);
    PyModule_AddIntConstant(mod, "XPLM_VK_F1", XPLM_VK_F1);
    PyModule_AddIntConstant(mod, "XPLM_VK_F2", XPLM_VK_F2);
    PyModule_AddIntConstant(mod, "XPLM_VK_F3", XPLM_VK_F3);
    PyModule_AddIntConstant(mod, "XPLM_VK_F4", XPLM_VK_F4);
    PyModule_AddIntConstant(mod, "XPLM_VK_F5", XPLM_VK_F5);
    PyModule_AddIntConstant(mod, "XPLM_VK_F6", XPLM_VK_F6);
    PyModule_AddIntConstant(mod, "XPLM_VK_F7", XPLM_VK_F7);
    PyModule_AddIntConstant(mod, "XPLM_VK_F8", XPLM_VK_F8);
    PyModule_AddIntConstant(mod, "XPLM_VK_F9", XPLM_VK_F9);
    PyModule_AddIntConstant(mod, "XPLM_VK_F10", XPLM_VK_F10);
    PyModule_AddIntConstant(mod, "XPLM_VK_F11", XPLM_VK_F11);
    PyModule_AddIntConstant(mod, "XPLM_VK_F12", XPLM_VK_F12);
    PyModule_AddIntConstant(mod, "XPLM_VK_F13", XPLM_VK_F13);
    PyModule_AddIntConstant(mod, "XPLM_VK_F14", XPLM_VK_F14);
    PyModule_AddIntConstant(mod, "XPLM_VK_F15", XPLM_VK_F15);
    PyModule_AddIntConstant(mod, "XPLM_VK_F16", XPLM_VK_F16);
    PyModule_AddIntConstant(mod, "XPLM_VK_F17", XPLM_VK_F17);
    PyModule_AddIntConstant(mod, "XPLM_VK_F18", XPLM_VK_F18);
    PyModule_AddIntConstant(mod, "XPLM_VK_F19", XPLM_VK_F19);
    PyModule_AddIntConstant(mod, "XPLM_VK_F20", XPLM_VK_F20);
    PyModule_AddIntConstant(mod, "XPLM_VK_F21", XPLM_VK_F21);
    PyModule_AddIntConstant(mod, "XPLM_VK_F22", XPLM_VK_F22);
    PyModule_AddIntConstant(mod, "XPLM_VK_F23", XPLM_VK_F23);
    PyModule_AddIntConstant(mod, "XPLM_VK_F24", XPLM_VK_F24);
/* The following definitions are extended and are not based on the Microsoft   *
 * key set.                                                                    */
    PyModule_AddIntConstant(mod, "XPLM_VK_EQUAL", XPLM_VK_EQUAL);
    PyModule_AddIntConstant(mod, "XPLM_VK_MINUS", XPLM_VK_MINUS);
    PyModule_AddIntConstant(mod, "XPLM_VK_RBRACE", XPLM_VK_RBRACE);
    PyModule_AddIntConstant(mod, "XPLM_VK_LBRACE", XPLM_VK_LBRACE);
    PyModule_AddIntConstant(mod, "XPLM_VK_QUOTE", XPLM_VK_QUOTE);
    PyModule_AddIntConstant(mod, "XPLM_VK_SEMICOLON", XPLM_VK_SEMICOLON);
    PyModule_AddIntConstant(mod, "XPLM_VK_BACKSLASH", XPLM_VK_BACKSLASH);
    PyModule_AddIntConstant(mod, "XPLM_VK_COMMA", XPLM_VK_COMMA);
    PyModule_AddIntConstant(mod, "XPLM_VK_SLASH", XPLM_VK_SLASH);
    PyModule_AddIntConstant(mod, "XPLM_VK_PERIOD", XPLM_VK_PERIOD);
    PyModule_AddIntConstant(mod, "XPLM_VK_BACKQUOTE", XPLM_VK_BACKQUOTE);
    PyModule_AddIntConstant(mod, "XPLM_VK_ENTER", XPLM_VK_ENTER);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD_ENT", XPLM_VK_NUMPAD_ENT);
    PyModule_AddIntConstant(mod, "XPLM_VK_NUMPAD_EQ", XPLM_VK_NUMPAD_EQ);

    PyModule_AddIntConstant(mod, "VK_BACK", XPLM_VK_BACK);
    PyModule_AddIntConstant(mod, "VK_TAB", XPLM_VK_TAB);
    PyModule_AddIntConstant(mod, "VK_CLEAR", XPLM_VK_CLEAR);
    PyModule_AddIntConstant(mod, "VK_RETURN", XPLM_VK_RETURN);
    PyModule_AddIntConstant(mod, "VK_ESCAPE", XPLM_VK_ESCAPE);
    PyModule_AddIntConstant(mod, "VK_SPACE", XPLM_VK_SPACE);
    PyModule_AddIntConstant(mod, "VK_PRIOR", XPLM_VK_PRIOR);
    PyModule_AddIntConstant(mod, "VK_NEXT", XPLM_VK_NEXT);
    PyModule_AddIntConstant(mod, "VK_END", XPLM_VK_END);
    PyModule_AddIntConstant(mod, "VK_HOME", XPLM_VK_HOME);
    PyModule_AddIntConstant(mod, "VK_LEFT", XPLM_VK_LEFT);
    PyModule_AddIntConstant(mod, "VK_UP", XPLM_VK_UP);
    PyModule_AddIntConstant(mod, "VK_RIGHT", XPLM_VK_RIGHT);
    PyModule_AddIntConstant(mod, "VK_DOWN", XPLM_VK_DOWN);
    PyModule_AddIntConstant(mod, "VK_SELECT", XPLM_VK_SELECT);
    PyModule_AddIntConstant(mod, "VK_PRINT", XPLM_VK_PRINT);
    PyModule_AddIntConstant(mod, "VK_EXECUTE", XPLM_VK_EXECUTE);
    PyModule_AddIntConstant(mod, "VK_SNAPSHOT", XPLM_VK_SNAPSHOT);
    PyModule_AddIntConstant(mod, "VK_INSERT", XPLM_VK_INSERT);
    PyModule_AddIntConstant(mod, "VK_DELETE", XPLM_VK_DELETE);
    PyModule_AddIntConstant(mod, "VK_HELP", XPLM_VK_HELP);
/* VK_0 thru XPLM_VK_9 are the same as ASCII '0' thru '9' (0x30 - 0x39)   */
    PyModule_AddIntConstant(mod, "VK_0", XPLM_VK_0);
    PyModule_AddIntConstant(mod, "VK_1", XPLM_VK_1);
    PyModule_AddIntConstant(mod, "VK_2", XPLM_VK_2);
    PyModule_AddIntConstant(mod, "VK_3", XPLM_VK_3);
    PyModule_AddIntConstant(mod, "VK_4", XPLM_VK_4);
    PyModule_AddIntConstant(mod, "VK_5", XPLM_VK_5);
    PyModule_AddIntConstant(mod, "VK_6", XPLM_VK_6);
    PyModule_AddIntConstant(mod, "VK_7", XPLM_VK_7);
    PyModule_AddIntConstant(mod, "VK_8", XPLM_VK_8);
    PyModule_AddIntConstant(mod, "VK_9", XPLM_VK_9);
/* VK_A thru XPLM_VK_Z are the same as ASCII 'A' thru 'Z' (0x41 - 0x5A)   */
    PyModule_AddIntConstant(mod, "VK_A", XPLM_VK_A);
    PyModule_AddIntConstant(mod, "VK_B", XPLM_VK_B);
    PyModule_AddIntConstant(mod, "VK_C", XPLM_VK_C);
    PyModule_AddIntConstant(mod, "VK_D", XPLM_VK_D);
    PyModule_AddIntConstant(mod, "VK_E", XPLM_VK_E);
    PyModule_AddIntConstant(mod, "VK_F", XPLM_VK_F);
    PyModule_AddIntConstant(mod, "VK_G", XPLM_VK_G);
    PyModule_AddIntConstant(mod, "VK_H", XPLM_VK_H);
    PyModule_AddIntConstant(mod, "VK_I", XPLM_VK_I);
    PyModule_AddIntConstant(mod, "VK_J", XPLM_VK_J);
    PyModule_AddIntConstant(mod, "VK_K", XPLM_VK_K);
    PyModule_AddIntConstant(mod, "VK_L", XPLM_VK_L);
    PyModule_AddIntConstant(mod, "VK_M", XPLM_VK_M);
    PyModule_AddIntConstant(mod, "VK_N", XPLM_VK_N);
    PyModule_AddIntConstant(mod, "VK_O", XPLM_VK_O);
    PyModule_AddIntConstant(mod, "VK_P", XPLM_VK_P);
    PyModule_AddIntConstant(mod, "VK_Q", XPLM_VK_Q);
    PyModule_AddIntConstant(mod, "VK_R", XPLM_VK_R);
    PyModule_AddIntConstant(mod, "VK_S", XPLM_VK_S);
    PyModule_AddIntConstant(mod, "VK_T", XPLM_VK_T);
    PyModule_AddIntConstant(mod, "VK_U", XPLM_VK_U);
    PyModule_AddIntConstant(mod, "VK_V", XPLM_VK_V);
    PyModule_AddIntConstant(mod, "VK_W", XPLM_VK_W);
    PyModule_AddIntConstant(mod, "VK_X", XPLM_VK_X);
    PyModule_AddIntConstant(mod, "VK_Y", XPLM_VK_Y);
    PyModule_AddIntConstant(mod, "VK_Z", XPLM_VK_Z);
    PyModule_AddIntConstant(mod, "VK_NUMPAD0", XPLM_VK_NUMPAD0);
    PyModule_AddIntConstant(mod, "VK_NUMPAD1", XPLM_VK_NUMPAD1);
    PyModule_AddIntConstant(mod, "VK_NUMPAD2", XPLM_VK_NUMPAD2);
    PyModule_AddIntConstant(mod, "VK_NUMPAD3", XPLM_VK_NUMPAD3);
    PyModule_AddIntConstant(mod, "VK_NUMPAD4", XPLM_VK_NUMPAD4);
    PyModule_AddIntConstant(mod, "VK_NUMPAD5", XPLM_VK_NUMPAD5);
    PyModule_AddIntConstant(mod, "VK_NUMPAD6", XPLM_VK_NUMPAD6);
    PyModule_AddIntConstant(mod, "VK_NUMPAD7", XPLM_VK_NUMPAD7);
    PyModule_AddIntConstant(mod, "VK_NUMPAD8", XPLM_VK_NUMPAD8);
    PyModule_AddIntConstant(mod, "VK_NUMPAD9", XPLM_VK_NUMPAD9);
    PyModule_AddIntConstant(mod, "VK_MULTIPLY", XPLM_VK_MULTIPLY);
    PyModule_AddIntConstant(mod, "VK_ADD", XPLM_VK_ADD);
    PyModule_AddIntConstant(mod, "VK_SEPARATOR", XPLM_VK_SEPARATOR);
    PyModule_AddIntConstant(mod, "VK_SUBTRACT", XPLM_VK_SUBTRACT);
    PyModule_AddIntConstant(mod, "VK_DECIMAL", XPLM_VK_DECIMAL);
    PyModule_AddIntConstant(mod, "VK_DIVIDE", XPLM_VK_DIVIDE);
    PyModule_AddIntConstant(mod, "VK_F1", XPLM_VK_F1);
    PyModule_AddIntConstant(mod, "VK_F2", XPLM_VK_F2);
    PyModule_AddIntConstant(mod, "VK_F3", XPLM_VK_F3);
    PyModule_AddIntConstant(mod, "VK_F4", XPLM_VK_F4);
    PyModule_AddIntConstant(mod, "VK_F5", XPLM_VK_F5);
    PyModule_AddIntConstant(mod, "VK_F6", XPLM_VK_F6);
    PyModule_AddIntConstant(mod, "VK_F7", XPLM_VK_F7);
    PyModule_AddIntConstant(mod, "VK_F8", XPLM_VK_F8);
    PyModule_AddIntConstant(mod, "VK_F9", XPLM_VK_F9);
    PyModule_AddIntConstant(mod, "VK_F10", XPLM_VK_F10);
    PyModule_AddIntConstant(mod, "VK_F11", XPLM_VK_F11);
    PyModule_AddIntConstant(mod, "VK_F12", XPLM_VK_F12);
    PyModule_AddIntConstant(mod, "VK_F13", XPLM_VK_F13);
    PyModule_AddIntConstant(mod, "VK_F14", XPLM_VK_F14);
    PyModule_AddIntConstant(mod, "VK_F15", XPLM_VK_F15);
    PyModule_AddIntConstant(mod, "VK_F16", XPLM_VK_F16);
    PyModule_AddIntConstant(mod, "VK_F17", XPLM_VK_F17);
    PyModule_AddIntConstant(mod, "VK_F18", XPLM_VK_F18);
    PyModule_AddIntConstant(mod, "VK_F19", XPLM_VK_F19);
    PyModule_AddIntConstant(mod, "VK_F20", XPLM_VK_F20);
    PyModule_AddIntConstant(mod, "VK_F21", XPLM_VK_F21);
    PyModule_AddIntConstant(mod, "VK_F22", XPLM_VK_F22);
    PyModule_AddIntConstant(mod, "VK_F23", XPLM_VK_F23);
    PyModule_AddIntConstant(mod, "VK_F24", XPLM_VK_F24);
/* The following definitions are extended and are not based on the Microsoft   *
 * key set.                                                                    */
    PyModule_AddIntConstant(mod, "VK_EQUAL", XPLM_VK_EQUAL);
    PyModule_AddIntConstant(mod, "VK_MINUS", XPLM_VK_MINUS);
    PyModule_AddIntConstant(mod, "VK_RBRACE", XPLM_VK_RBRACE);
    PyModule_AddIntConstant(mod, "VK_LBRACE", XPLM_VK_LBRACE);
    PyModule_AddIntConstant(mod, "VK_QUOTE", XPLM_VK_QUOTE);
    PyModule_AddIntConstant(mod, "VK_SEMICOLON", XPLM_VK_SEMICOLON);
    PyModule_AddIntConstant(mod, "VK_BACKSLASH", XPLM_VK_BACKSLASH);
    PyModule_AddIntConstant(mod, "VK_COMMA", XPLM_VK_COMMA);
    PyModule_AddIntConstant(mod, "VK_SLASH", XPLM_VK_SLASH);
    PyModule_AddIntConstant(mod, "VK_PERIOD", XPLM_VK_PERIOD);
    PyModule_AddIntConstant(mod, "VK_BACKQUOTE", XPLM_VK_BACKQUOTE);
    PyModule_AddIntConstant(mod, "VK_ENTER", XPLM_VK_ENTER);
    PyModule_AddIntConstant(mod, "VK_NUMPAD_ENT", XPLM_VK_NUMPAD_ENT);
    PyModule_AddIntConstant(mod, "VK_NUMPAD_EQ", XPLM_VK_NUMPAD_EQ);
  }
  return mod;
}




