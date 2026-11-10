#ifndef DYNLIB_H
#define DYNLIB_H

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

EXPORT void run_array(void);
EXPORT void run_matrix(void);

#endif