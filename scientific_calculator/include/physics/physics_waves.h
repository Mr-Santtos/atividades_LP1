#ifndef PHYSICS_WAVES_H
#define PHYSICS_WAVES_H

namespace physics {
double wave_speed(double frequency, double wavelength);
double decibel_from_intensity(double I, double I0 = 1e-12);
} // namespace physics

#endif // PHYSICS_WAVES_H
