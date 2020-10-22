// logic.hh
// This header ensures C linkage is enforced when running C++ unit tessts on C code.

#ifdef __cplusplus

extern "C" {

#include "logic.h"

}

#else

#include "logic.h"

#endif
