#ifdef _WIN32
  #ifdef _WIN64
    #define VALKRY_PLATFORM_STRING "Windows"
  #else
    #error "Valkry does not natively support x86 (32-bit) builds."
  #endif
#elif defined(__APPLE__) || defined (__MACH__)
  #include <TargetConditionals.h>
  #if TARGET_IPHONE_SIMULATOR == 1
    #define VALKRY_PLATFORM_STRING "iOS Simulator"
  #elif TARGET_OS_IPHONE == 1
    #define VALKRY_PLATFORM_STRING "iPhone"
  #elif TARGET_OS_MAC == 1
    #define VALKRY_PLATFORM_STRING "MacOS"
  #else
    #define VALKRY_PLATFORM_STRING "Unknown Apple system"
  #endif
#elif defined (__ANDROID__)
  #define VALKRY_PLATFORM_STRING "Android"
#elif defined (__linux__)
  #define VALKRY_PLATFORM_STRING "Linux"
#else
  #define VALKRY_PLATFORM_STRING "Platform unknown"
#endif
