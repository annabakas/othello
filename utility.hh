// utility.hh
// This header ensures C linkage is enforced when running C++ unit tessts on C code.

#ifdef __cplusplus

extern "C" {

#include "utility.h"

}

#else

#include "utility.h"

#endif
