#pragma once

#if VERSION_IS_AUTO_DEFINED
    #include "auto_defined_version.h"
    #define VERSION AUTO_DEFINED_VERSION
#else
    #define VERSION "0.0.0"
    /* there is no auto defined version info.
    a dummy version will be used instead. */
#endif
