#ifndef SEDAN_HPP
#define SEDAN_HPP
#include "car.hpp"
class Sedan : public Car
{

public:
    Sedan();

    virtual void shift_up() override;

    virtual void shift_down() override;

    virtual double get_torque(double engine_rpm, double throttle) override;

    virtual double get_weight() override;

    virtual double get_wheel_radius() override;

    virtual double get_current_gear_ratio() override;

private:
    int current_gear;
};

#endif // SEDAN_HPP