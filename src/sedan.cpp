#include "sedan.hpp"
#include <array>

static const std::array<double, 7> gear_ratios = {-1, 1, 2, 3, 4, 5, 6};

Sedan::Sedan() : current_gear(0)
{
}

void Sedan::shift_up()
{
}

void Sedan::shift_down()
{
}

double Sedan::get_torque(double engine_rpm, double throttle)
{
    return 0;
}

double Sedan::get_weight()
{
    return 1;
}

double Sedan::get_wheel_radius()
{
    return 1;
}

double Sedan::get_current_gear_ratio()
{
    return 1;
}