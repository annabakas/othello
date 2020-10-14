// gameboard.hh
// This header ensures C linkage is enforced when running C++ unit tessts on C code.

#ifdef __cplusplus

extern "C" {

#include "gameboard.h"

}

#else

#include "gameboard.h"

#endif
