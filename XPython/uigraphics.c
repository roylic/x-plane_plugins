#define _GNU_SOURCE 1
#include <Python.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdbool.h>

#include <XPLM/XPLMDefs.h>
#include <Widgets/XPWidgetDefs.h>
#include <Widgets/XPUIGraphics.h>
#include "utils.h"
#include "xppythontypes.h"

My_DOCSTR(_drawWindow__doc__, "drawWindow", "left, bottom, right, top, style=1",
          "Draw window at location");
static PyObject *XPDrawWindowFun(PyObject *self, PyObject *args, PyObject *kwargs)
{
  static char *keywords[] = {"left", "bottom", "right", "top", "style", NULL};
  (void) self;
  int inX1, inY1, inX2, inY2, inStyle=1;
  if(!PyArg_ParseTupleAndKeywords(args, kwargs, "iiii|i", keywords, &inX1, &inY1, &inX2, &inY2, &inStyle)){
    return NULL;
  }
  XPDrawWindow(inX1, inY1, inX2, inY2, inStyle);
  Py_RETURN_NONE;
}

My_DOCSTR(_getWindowDefaultDimensions__doc__, "getWindowDefaultDimensions", "style=1",
          "Default dimension for indicated style\n"
          "\n"
          "Returns (width, height)");
static PyObject *XPGetWindowDefaultDimensionsFun(PyObject *self, PyObject *args, PyObject *kwargs)
{
  static char *keywords[] = {"style", NULL};
  (void) self;
  int inStyle=1, width, height;
  if(!PyArg_ParseTupleAndKeywords(args, kwargs, "|i", keywords, &inStyle)) {
    return NULL;
  }
  XPGetWindowDefaultDimensions(inStyle, &width, &height);
  return Py_BuildValue("ii", width, height);
}

My_DOCSTR(_drawElement__doc__, "drawElement", "left, bottom, right, top, style, lit=0",
          "Draw element, possibly lit, at location.");
static PyObject *XPDrawElementFun(PyObject *self, PyObject *args, PyObject *kwargs)
{
  static char *keywords[] = {"left", "bottom", "right", "top", "style", "lit", NULL};
  (void) self;
  int inX1, inY1, inX2, inY2, inStyle, inLit=0;
  if(!PyArg_ParseTupleAndKeywords(args, kwargs, "iiiii|i", keywords, &inX1, &inY1, &inX2, &inY2, &inStyle, &inLit)){
    return NULL;
  }
  XPDrawElement(inX1, inY1, inX2, inY2, inStyle, inLit);
  Py_RETURN_NONE;
}

My_DOCSTR(_getElementDefaultDimensions__doc__, "getElementDefaultDimensions", "style",
          "Default dimension for indicated element\n"
          "\n"
          "Returns (width, height, canBeLit)");
static PyObject *XPGetElementDefaultDimensionsFun(PyObject *self, PyObject *args, PyObject *kwargs)
{
  static char *keywords[] = {"style", NULL}; 
  (void) self;
  int inStyle, width, height, canBeLit;
  if(!PyArg_ParseTupleAndKeywords(args, kwargs, "i", keywords, &inStyle)) {
    return NULL;
  }
  XPGetElementDefaultDimensions(inStyle, &width, &height, &canBeLit);
  return Py_BuildValue("iii", width, height, canBeLit);
}


My_DOCSTR(_drawTrack__doc__, "drawTrack", "left, bottom, right, top, minValue, maxValue, value, style, lit=0",
          "Draw track at location, with min/max values and current value.\n"
          "\n"
          "Track may be 'reversed' if minValue > maxValue.\n"
          "Styles are:\n"
          "  Track_Scrollbar=0\n"
          "  Track_Slider   =1\n"
          "  Track_Progress =2");
static PyObject *XPDrawTrackFun(PyObject *self, PyObject *args, PyObject *kwargs)
{
  static char *keywords[] = {"left", "bottom", "right", "top", "minValue", "maxValue", "value", "style", "lit", NULL};
  (void) self;
  int inX1, inY1, inX2, inY2, inMin, inMax, inValue, inStyle, inLit=0;
  if(!PyArg_ParseTupleAndKeywords(args, kwargs, "iiiiiiii|i", keywords, &inX1, &inY1, &inX2, &inY2, &inMin, &inMax, &inValue, &inStyle, &inLit)){
    return NULL;
  }
  XPDrawTrack(inX1, inY1, inX2, inY2, inMin, inMax, inValue, inStyle, inLit);
  Py_RETURN_NONE;
}

My_DOCSTR(_getTrackDefaultDimensions__doc__, "getTrackDefaultDimensions", "style",
          "Default dimension for indicated track style\n"
          "\n"
          "Returns (width, canBeLit)");
static PyObject *XPGetTrackDefaultDimensionsFun(PyObject *self, PyObject *args, PyObject *kwargs)
{
  static char *keywords[] = {"style", NULL};
  (void) self;
  int inStyle, width, canBeLit;
  if(!PyArg_ParseTupleAndKeywords(args, kwargs, "i", keywords, &inStyle)) {
    return NULL;
  }
  XPGetTrackDefaultDimensions(inStyle, &width, &canBeLit);
  return Py_BuildValue("ii", width, canBeLit);
}


My_DOCSTR(_getTrackMetrics__doc__, "getTrackMetrics", "left, bottom, right, top, minValue, maxValue, value, style",
          "Return object with metrics about track\n"
          "\n"
          "Object attributes are:\n"
          "  .isVertical\n"
          "  .downBtnSize\n"
          "  .downPageSize\n"
          "  .thumbSize\n"
          "  .upPageSize\n"
          "  .upBtnSize");
static PyObject *XPGetTrackMetricsFun(PyObject *self, PyObject *args, PyObject *kwargs)
{
  static char *keywords[] = {"left", "bottom", "right", "top", "minValue", "maxValue", "value", "style", NULL};
  (void) self;
  int inX1, inY1, inX2, inY2, inMin, inMax, inValue, inStyle;
  int outIsVertical, outDownBtnSize, outDownPageSize, outThumbSize, outUpPageSize, outUpBtnSize;
  if(!PyArg_ParseTupleAndKeywords(args, kwargs, "iiiiiiii", keywords, &inX1, &inY1, &inX2, &inY2, &inMin, &inMax, &inValue, &inStyle)){
    return NULL;
  }
  XPGetTrackMetrics(inX1, inY1, inX2, inY2, inMin, inMax, inValue, inStyle, &outIsVertical, &outDownBtnSize,
                    &outDownPageSize, &outThumbSize, &outUpPageSize, &outUpBtnSize);
  return PyTrackMetrics_New(outIsVertical, outDownBtnSize, outDownPageSize, outThumbSize, outUpPageSize, outUpBtnSize);
}

static PyObject *cleanup(PyObject *self, PyObject *args)
{
  (void) self;
  (void) args;
  Py_RETURN_NONE;
}

static PyMethodDef XPUIGraphicsMethods[] = {
  {"drawWindow", (PyCFunction)XPDrawWindowFun, METH_VARARGS | METH_KEYWORDS, _drawWindow__doc__},
  {"XPDrawWindow", (PyCFunction)XPDrawWindowFun, METH_VARARGS | METH_KEYWORDS, ""},
  {"getWindowDefaultDimensions", (PyCFunction)XPGetWindowDefaultDimensionsFun, METH_VARARGS | METH_KEYWORDS, _getWindowDefaultDimensions__doc__},
  {"XPGetWindowDefaultDimensions", (PyCFunction)XPGetWindowDefaultDimensionsFun, METH_VARARGS | METH_KEYWORDS, ""},
  {"drawElement", (PyCFunction)XPDrawElementFun, METH_VARARGS | METH_KEYWORDS, _drawElement__doc__},
  {"XPDrawElement", (PyCFunction)XPDrawElementFun, METH_VARARGS | METH_KEYWORDS, ""},
  {"getElementDefaultDimensions", (PyCFunction)XPGetElementDefaultDimensionsFun, METH_VARARGS | METH_KEYWORDS, _getElementDefaultDimensions__doc__},
  {"XPGetElementDefaultDimensions", (PyCFunction)XPGetElementDefaultDimensionsFun, METH_VARARGS | METH_KEYWORDS, ""},
  {"drawTrack", (PyCFunction)XPDrawTrackFun, METH_VARARGS | METH_KEYWORDS, _drawTrack__doc__},
  {"XPDrawTrack", (PyCFunction)XPDrawTrackFun, METH_VARARGS | METH_KEYWORDS, ""},
  {"getTrackDefaultDimensions", (PyCFunction)XPGetTrackDefaultDimensionsFun, METH_VARARGS | METH_KEYWORDS, _getTrackDefaultDimensions__doc__},
  {"XPGetTrackDefaultDimensions", (PyCFunction)XPGetTrackDefaultDimensionsFun, METH_VARARGS | METH_KEYWORDS, ""},
  {"getTrackMetrics", (PyCFunction)XPGetTrackMetricsFun, METH_VARARGS | METH_KEYWORDS, _getTrackMetrics__doc__},
  {"XPGetTrackMetrics", (PyCFunction)XPGetTrackMetricsFun, METH_VARARGS | METH_KEYWORDS, ""},
  {"_cleanup", cleanup, METH_VARARGS, ""},
  {NULL, NULL, 0, NULL}
};


static struct PyModuleDef XPUIGraphicsModule = {
  PyModuleDef_HEAD_INIT,
  "XPUIGraphics",
  "Laminar documentation: \n"
  "   https://developer.x-plane.com/sdk/XPUIGraphics/\n"
  "XPPython3 documentation: \n"
  "   https://xppython3.rtfd.io/en/stable/development/modules/uigraphics.html",
  -1,
  XPUIGraphicsMethods,
  NULL,
  NULL,
  NULL,
  NULL
};

PyMODINIT_FUNC
PyInit_XPUIGraphics(void)
{
  PyObject *mod = PyModule_Create(&XPUIGraphicsModule);
  if(mod){
    PyModule_AddStringConstant(mod, "__author__", "Peter Buckner (xppython3@avnwx.com)");
    PyModule_AddIntConstant(mod, "xpWindow_Help", xpWindow_Help);
    PyModule_AddIntConstant(mod, "xpWindow_MainWindow", xpWindow_MainWindow);
    PyModule_AddIntConstant(mod, "xpWindow_SubWindow", xpWindow_SubWindow);
    PyModule_AddIntConstant(mod, "xpWindow_Screen", xpWindow_Screen);
    PyModule_AddIntConstant(mod, "xpWindow_ListView", xpWindow_ListView);
    PyModule_AddIntConstant(mod, "xpElement_TextField", xpElement_TextField);
    PyModule_AddIntConstant(mod, "xpElement_CheckBox", xpElement_CheckBox);
    PyModule_AddIntConstant(mod, "xpElement_CheckBoxLit", xpElement_CheckBoxLit);
    PyModule_AddIntConstant(mod, "xpElement_WindowCloseBox", xpElement_WindowCloseBox);
    PyModule_AddIntConstant(mod, "xpElement_WindowCloseBoxPressed", xpElement_WindowCloseBoxPressed);
    PyModule_AddIntConstant(mod, "xpElement_PushButton", xpElement_PushButton);
    PyModule_AddIntConstant(mod, "xpElement_PushButtonLit", xpElement_PushButtonLit);
    PyModule_AddIntConstant(mod, "xpElement_OilPlatform", xpElement_OilPlatform);
    PyModule_AddIntConstant(mod, "xpElement_OilPlatformSmall", xpElement_OilPlatformSmall);
    PyModule_AddIntConstant(mod, "xpElement_Ship", xpElement_Ship);
    PyModule_AddIntConstant(mod, "xpElement_ILSGlideScope", xpElement_ILSGlideScope);
    PyModule_AddIntConstant(mod, "xpElement_MarkerLeft", xpElement_MarkerLeft);
    PyModule_AddIntConstant(mod, "xpElement_Airport", xpElement_Airport);
    PyModule_AddIntConstant(mod, "xpElement_Waypoint", xpElement_Waypoint);
    PyModule_AddIntConstant(mod, "xpElement_NDB", xpElement_NDB);
    PyModule_AddIntConstant(mod, "xpElement_VOR", xpElement_VOR);
    PyModule_AddIntConstant(mod, "xpElement_RadioTower", xpElement_RadioTower);
    PyModule_AddIntConstant(mod, "xpElement_AircraftCarrier", xpElement_AircraftCarrier);
    PyModule_AddIntConstant(mod, "xpElement_Fire", xpElement_Fire);
    PyModule_AddIntConstant(mod, "xpElement_MarkerRight", xpElement_MarkerRight);
    PyModule_AddIntConstant(mod, "xpElement_CustomObject", xpElement_CustomObject);
    PyModule_AddIntConstant(mod, "xpElement_CoolingTower", xpElement_CoolingTower);
    PyModule_AddIntConstant(mod, "xpElement_SmokeStack", xpElement_SmokeStack);
    PyModule_AddIntConstant(mod, "xpElement_Building", xpElement_Building);
    PyModule_AddIntConstant(mod, "xpElement_PowerLine", xpElement_PowerLine);
    PyModule_AddIntConstant(mod, "xpElement_CopyButtons", xpElement_CopyButtons);
    PyModule_AddIntConstant(mod, "xpElement_CopyButtonsWithEditingGrid", xpElement_CopyButtonsWithEditingGrid);
    PyModule_AddIntConstant(mod, "xpElement_EditingGrid", xpElement_EditingGrid);
    PyModule_AddIntConstant(mod, "xpElement_ScrollBar", xpElement_ScrollBar);
    PyModule_AddIntConstant(mod, "xpElement_VORWithCompassRose", xpElement_VORWithCompassRose);
    PyModule_AddIntConstant(mod, "xpElement_Zoomer", xpElement_Zoomer);
    PyModule_AddIntConstant(mod, "xpElement_TextFieldMiddle", xpElement_TextFieldMiddle);
    PyModule_AddIntConstant(mod, "xpElement_LittleDownArrow", xpElement_LittleDownArrow);
    PyModule_AddIntConstant(mod, "xpElement_LittleUpArrow", xpElement_LittleUpArrow);
    PyModule_AddIntConstant(mod, "xpElement_WindowDragBar", xpElement_WindowDragBar);
    PyModule_AddIntConstant(mod, "xpElement_WindowDragBarSmooth", xpElement_WindowDragBarSmooth);
    PyModule_AddIntConstant(mod, "xpTrack_ScrollBar", xpTrack_ScrollBar);
    PyModule_AddIntConstant(mod, "xpTrack_Slider", xpTrack_Slider);
    PyModule_AddIntConstant(mod, "xpTrack_Progress", xpTrack_Progress);

    PyModule_AddIntConstant(mod, "Window_Help", xpWindow_Help);
    PyModule_AddIntConstant(mod, "Window_MainWindow", xpWindow_MainWindow);
    PyModule_AddIntConstant(mod, "Window_SubWindow", xpWindow_SubWindow);
    PyModule_AddIntConstant(mod, "Window_Screen", xpWindow_Screen);
    PyModule_AddIntConstant(mod, "Window_ListView", xpWindow_ListView);
    PyModule_AddIntConstant(mod, "Element_TextField", xpElement_TextField);
    PyModule_AddIntConstant(mod, "Element_CheckBox", xpElement_CheckBox);
    PyModule_AddIntConstant(mod, "Element_CheckBoxLit", xpElement_CheckBoxLit);
    PyModule_AddIntConstant(mod, "Element_WindowCloseBox", xpElement_WindowCloseBox);
    PyModule_AddIntConstant(mod, "Element_WindowCloseBoxPressed", xpElement_WindowCloseBoxPressed);
    PyModule_AddIntConstant(mod, "Element_PushButton", xpElement_PushButton);
    PyModule_AddIntConstant(mod, "Element_PushButtonLit", xpElement_PushButtonLit);
    PyModule_AddIntConstant(mod, "Element_OilPlatform", xpElement_OilPlatform);
    PyModule_AddIntConstant(mod, "Element_OilPlatformSmall", xpElement_OilPlatformSmall);
    PyModule_AddIntConstant(mod, "Element_Ship", xpElement_Ship);
    PyModule_AddIntConstant(mod, "Element_ILSGlideScope", xpElement_ILSGlideScope);
    PyModule_AddIntConstant(mod, "Element_MarkerLeft", xpElement_MarkerLeft);
    PyModule_AddIntConstant(mod, "Element_Airport", xpElement_Airport);
    PyModule_AddIntConstant(mod, "Element_Waypoint", xpElement_Waypoint);
    PyModule_AddIntConstant(mod, "Element_NDB", xpElement_NDB);
    PyModule_AddIntConstant(mod, "Element_VOR", xpElement_VOR);
    PyModule_AddIntConstant(mod, "Element_RadioTower", xpElement_RadioTower);
    PyModule_AddIntConstant(mod, "Element_AircraftCarrier", xpElement_AircraftCarrier);
    PyModule_AddIntConstant(mod, "Element_Fire", xpElement_Fire);
    PyModule_AddIntConstant(mod, "Element_MarkerRight", xpElement_MarkerRight);
    PyModule_AddIntConstant(mod, "Element_CustomObject", xpElement_CustomObject);
    PyModule_AddIntConstant(mod, "Element_CoolingTower", xpElement_CoolingTower);
    PyModule_AddIntConstant(mod, "Element_SmokeStack", xpElement_SmokeStack);
    PyModule_AddIntConstant(mod, "Element_Building", xpElement_Building);
    PyModule_AddIntConstant(mod, "Element_PowerLine", xpElement_PowerLine);
    PyModule_AddIntConstant(mod, "Element_CopyButtons", xpElement_CopyButtons);
    PyModule_AddIntConstant(mod, "Element_CopyButtonsWithEditingGrid", xpElement_CopyButtonsWithEditingGrid);
    PyModule_AddIntConstant(mod, "Element_EditingGrid", xpElement_EditingGrid);
    PyModule_AddIntConstant(mod, "Element_ScrollBar", xpElement_ScrollBar);
    PyModule_AddIntConstant(mod, "Element_VORWithCompassRose", xpElement_VORWithCompassRose);
    PyModule_AddIntConstant(mod, "Element_Zoomer", xpElement_Zoomer);
    PyModule_AddIntConstant(mod, "Element_TextFieldMiddle", xpElement_TextFieldMiddle);
    PyModule_AddIntConstant(mod, "Element_LittleDownArrow", xpElement_LittleDownArrow);
    PyModule_AddIntConstant(mod, "Element_LittleUpArrow", xpElement_LittleUpArrow);
    PyModule_AddIntConstant(mod, "Element_WindowDragBar", xpElement_WindowDragBar);
    PyModule_AddIntConstant(mod, "Element_WindowDragBarSmooth", xpElement_WindowDragBarSmooth);
    PyModule_AddIntConstant(mod, "Track_ScrollBar", xpTrack_ScrollBar);
    PyModule_AddIntConstant(mod, "Track_Slider", xpTrack_Slider);
    PyModule_AddIntConstant(mod, "Track_Progress", xpTrack_Progress);
  }

  return mod;
}
 

