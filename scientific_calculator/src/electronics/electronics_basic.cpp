#include "include/electronics/electronics_basic.h"

namespace electronics {

double series_resistance(double r1, double r2) {
    return r1 + r2;
}

double parallel_resistance(double r1, double r2) {
    if (r1 == 0 || r2 == 0) return 0.0;
    return 1.0 / (1.0 / r1 + 1.0 / r2);
}

} // namespace electronics
