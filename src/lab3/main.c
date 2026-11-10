#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define ARR_LIB "libarr.dll"
#define MAT_LIB "libmat.dll"
#else
#include <dlfcn.h>
#define ARR_LIB "./libarr.so"
#define MAT_LIB "./libmat.so"
#endif

typedef void (*run_fn)(void);

static void load_and_run(const char *libname, const char *funcname)
{
#ifdef _WIN32
    HMODULE lib = LoadLibrary(libname);
    run_fn fun;
    if (!lib)
    {
        printf("cannot open library '%s'\n", libname);
        return;
    }
    fun = (run_fn)GetProcAddress(lib, funcname);
    if (fun == NULL)
        printf("cannot find function '%s'\n", funcname);
    else
        fun();
    FreeLibrary(lib);
#else
    void *lib = dlopen(libname, RTLD_LAZY);
    run_fn fun;
    if (!lib)
    {
        printf("cannot open library '%s'\n", libname);
        return;
    }
    fun = (run_fn)dlsym(lib, funcname);
    if (fun == NULL)
        printf("cannot find function '%s'\n", funcname);
    else
        fun();
    dlclose(lib);
#endif
}

int main(void)
{
    int choice = 0;
    srand((unsigned)time(NULL));
    
    printf("Choose:\n1 - array\n2 - matrix\n3 - quit\n");
    while (scanf("%d", &choice) == 1 && choice != 3)
    {
        if (choice == 1)
            load_and_run(ARR_LIB, "run_array");
        else if (choice == 2)
            load_and_run(MAT_LIB, "run_matrix");
        else
            printf("Unknown choice\n");
        printf("Choose:\n1 - array\n2 - matrix\n3 - quit\n");
    }
    return 0;
}