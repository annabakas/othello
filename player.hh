// player.hh
// This header ensures C linkage is enforced when running C++ unit tessts on C code.

#ifdef __cplusplus

extern "C" {

#include "player.h"

}

#else

#include "player.h"

#endif
