#ifndef CAR_HPP
#define CAR_HPP

#include <stdexcept>

// Base class of all cars
//
// For simulation of speed see:
//  - https://x-engineer.org/automotive-engineering/chassis/vehicle-dynamics/calculate-wheel-torque-engine/
//  - http://teamghettoracing.com/tech-info/optimum-gearchange-points/
class Car
{

public:
    Car() : car_speed_ms(0.0)
    {
    }

    // Calculates the acceleration of the car and updates it speed
    void step(double step_size, double throttle)
    {
        if (throttle > 1.0 || throttle < 0)
        {
            throw std::invalid_argument("throttle must be between 0.0 and 1.0");
        }

        double torque_wheels = get_current_gear_ratio() * get_torque(get_engine_rpm(), throttle);
        double force_wheels = torque_wheels / this->get_wheel_radius();
        double acceleration = force_wheels / get_weight();

        // Forward Euler (https://en.wikipedia.org/wiki/Euler_method)
        this->car_speed_ms += step_size * acceleration;
    }

    // increase the current gear
    virtual void shift_up() = 0;

    // decrease the current gear
    virtual void shift_down() = 0;

    // Returns torque produced by the engine at a given rotation speed and a certain level of pressure on the throttle, measured in [N*m]
    // For combustion engines the torque is a function of the engines rotation speed.
    // For too low RPMs the engine does not run efficiently, for too high RPMs the influence of friction grows and it produces less torque.
    // Ideally, you should choose a gear that keeps the engine running in this sweetspot.
    virtual double get_torque(double engine_rpm, double throttle) = 0;

    // Returns the total weight of the car [kg]
    virtual double get_weight() = 0;

    // Returns the wheel radius of the car [m]
    virtual double get_wheel_radius() = 0;

    // Returns the gear ratio between the engine and the wheel realized by the currently selected gear, e.g. rpm_wheel/rpm_engine
    virtual double get_current_gear_ratio() = 0;

    // get the speed of the car measured in meters per second m/s
    double get_speed()
    {
        return car_speed_ms;
    }

    double get_engine_rpm()
    {
        double wheel_circumference = 2 * 3.14 * get_wheel_radius();
        return (this->car_speed_ms * 60 * get_current_gear_ratio()) / wheel_circumference;
    }

private:
    double car_speed_ms;
};

#endif // CAR_HPP