#pragma once

#ifdef GEODE_IS_WINDOWS
#ifdef CWRKS_PROGRESSBAR_API_EXPORTING
#define CWRKS_PROGRESSBAR_API_DLL __declspec(dllexport)
#else
#define CWRKS_PROGRESSBAR_API_DLL __declspec(dllimport)
#endif
#else
#ifdef CWRKS_PROGRESSBAR_API_EXPORTING
#define CWRKS_PROGRESSBAR_API_DLL __attribute__((visibility("default")))
#else
#define CWRKS_PROGRESSBAR_API_DLL
#endif
#endif

#include <Geode/platform/cplatform.h>

#include "MapPackCell.h"
#include "PauseLayer.h"
#include "PlayLayer.h"