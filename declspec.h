#if defined(__CYGWIN__) || defined(__MINGW32__)
  #ifdef _USRDLL
    #ifdef OPENGL_MATH_EXPORTS
      #define OPENGL_MATH_API __declspec(dllexport)
      #define EXTERN_OPENGL_MATH_API extern __declspec(dllexport)
    #else
      #define OPENGL_MATH_API __declspec(dllimport)
      #define EXTERN_OPENGL_MATH_API extern __declspec(dllimport)
    #endif
  #else
    #define OPENGL_MATH_API extern
  #endif

  #include <stdint.h>
  #ifndef GLAPIENTRY
  #  define GLAPIENTRY __stdcall
  #endif
  #ifndef OPENGL_MATH_APIENTRY
  #  define OPENGL_MATH_APIENTRY __stdcall
  #endif

  #define GLAPI extern

#elif (defined WIN32) || (defined _WIN32) || (defined __WIN32__)
  #ifdef _USRDLL
    #ifdef OPENGL_MATH_EXPORTS
      #define OPENGL_MATH_API __declspec(dllexport)
      #define EXTERN_OPENGL_MATH_API extern __declspec(dllexport)
    #else
      #define OPENGL_MATH_API __declspec(dllimport)
      #define EXTERN_OPENGL_MATH_API extern __declspec(dllimport)
    #endif
  #elif defined(_USRSTATIC)
    #define OPENGL_MATH_API
    #define EXTERN_OPENGL_MATH_API extern
  #else
    #define OPENGL_MATH_API
    #define EXTERN_OPENGL_MATH_API extern __declspec(dllimport)
  #endif

  #include <stdint.h>
  #ifndef GLAPIENTRY
  #  define GLAPIENTRY __stdcall
  #endif
  #ifndef OPENGL_MATH_APIENTRY
  #  define OPENGL_MATH_APIENTRY __stdcall
  #endif

  #define GLAPI __declspec(dllimport)

#elif (defined __gnu_linux__) || (defined __linux__)
  #define OPENGL_MATH_API
  #define EXTERN_OPENGL_MATH_API extern __attribute__ ((visibility("default")))

  #include <stddef.h>
  #include <stdint.h>
  #define APIENTRY
  #ifndef GLAPIENTRY
  #  define GLAPIENTRY
  #endif
  #ifndef OPENGL_MATH_APIENTRY
  #  define OPENGL_MATH_APIENTRY
  #endif

  #define GLAPI

#endif
