#include <bifrost/array.h>
#include <bifrost/common.h>
#include <bifrost/ring.h>

#ifdef __cplusplus
extern "C" {
#endif

    BFstatus BeanFarmer(BFarray *voltages, BFarray *weights, BFarray *beamformed_out, const int NACCUMULATE);

#ifdef __cplusplus
}
#endif
