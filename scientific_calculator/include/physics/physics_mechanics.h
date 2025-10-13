#ifndef PHYSICS_MECHANICS_H
#define PHYSICS_MECHANICS_H

namespace physics {
double kinetic_energy(double mass, double velocity);
double potential_energy(double mass, double height, double g = 9.80665);
} // namespace physics

#endif // PHYSICS_MECHANICS_H
