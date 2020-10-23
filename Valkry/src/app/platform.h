#ifdef _WIN32
  #ifdef _WIN64
    #define VALKRY_PLATFORM_STRING "Windows"
    #define VALKRY_PLATFORM_WINDOWS
  #else
    #error "Valkry does not natively support x86 (32-bit) builds."
  #endif
#elif defined(__APPLE__) || defined (__MACH__)
  #include <TargetConditionals.h>
  #if TARGET_IPHONE_SIMULATOR == 1
    #define VALKRY_PLATFORM_STRING "iOS Simulator"
    #define VALRKY_PLATFORM_IOSSIM
  #elif TARGET_OS_IPHONE == 1
    #define VALKRY_PLATFORM_STRING "iPhone"
    #define VALKRY_PLATFORM_IOS
  #elif TARGET_OS_MAC == 1
    #define VALKRY_PLATFORM_STRING "MacOS"
    #define VALKRY_PLATFORM_MACOS
  #else
    #define VALKRY_PLATFORM_STRING "Unknown Apple system"
    #define VALKRY_PLATFORM_MAC_UNKNOWN
  #endif
#elif defined (__ANDROID__)
  #define VALKRY_PLATFORM_STRING "Android"
  #define VALKRY_PLATFORM_ANDROID
#elif defined (__linux__)
  #define VALKRY_PLATFORM_STRING "Linux"
  #define VALKRY_PLATFORM_LINUX
#else
  #define VALKRY_PLATFORM_STRING "Platform unknown"
  #define VALKRY_PLATFORM_UNKNOWN
#endif
