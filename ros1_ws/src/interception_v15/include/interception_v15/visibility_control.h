#ifndef INTERCEPTION_V15__VISIBILITY_CONTROL_H_
#define INTERCEPTION_V15__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define INTERCEPTION_V15_EXPORT __attribute__ ((dllexport))
    #define INTERCEPTION_V15_IMPORT __attribute__ ((dllimport))
  #else
    #define INTERCEPTION_V15_EXPORT __declspec(dllexport)
    #define INTERCEPTION_V15_IMPORT __declspec(dllimport)
  #endif
  #ifdef INTERCEPTION_V15_BUILDING_LIBRARY
    #define INTERCEPTION_V15_PUBLIC INTERCEPTION_V15_EXPORT
  #else
    #define INTERCEPTION_V15_PUBLIC INTERCEPTION_V15_IMPORT
  #endif
  #define INTERCEPTION_V15_PUBLIC_TYPE INTERCEPTION_V15_PUBLIC
  #define INTERCEPTION_V15_LOCAL
#else
  #define INTERCEPTION_V15_EXPORT __attribute__ ((visibility("default")))
  #define INTERCEPTION_V15_IMPORT
  #if __GNUC__ >= 4
    #define INTERCEPTION_V15_PUBLIC __attribute__ ((visibility("default")))
    #define INTERCEPTION_V15_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define INTERCEPTION_V15_PUBLIC
    #define INTERCEPTION_V15_LOCAL
  #endif
  #define INTERCEPTION_V15_PUBLIC_TYPE
#endif
#endif  // INTERCEPTION_V15__VISIBILITY_CONTROL_H_
// Generated 29-Oct-2022 09:19:04
// Copyright 2019-2020 The MathWorks, Inc.
