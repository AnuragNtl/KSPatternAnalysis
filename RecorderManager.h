#ifndef RECORDER_MANAGER_H
#define RECORDER_MANAGER_H
#include "Recorder.h"
#ifdef WINDOWS
#include "LRecorder.h"
typedef LRecorder DefaultRecorder;
#else
#include "WRecorder.h"
typedef WRecorder DefaultRecorder;
#endif
extern Recorder getDefaultRecorder();
#endif
