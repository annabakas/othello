// computer.hh
// This header ensures C linkage is enforced when running C++ unit tessts on C code.

#ifdef __cplusplus

extern "C" {

#include "computer.h"

}

#else

#include "computer.h"

#endif
