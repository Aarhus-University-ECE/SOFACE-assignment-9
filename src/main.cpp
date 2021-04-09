// File for sandboxing and trying out code

#include <iostream>
#include <vector>
#include <cmath>

#include "sedan.hpp"

int main(int argc, char **argv)
{
    Sedan s;

    double step_size = 0.01;
    double start_time = 0.0;
    double end_time = 20.0;
    int n_steps = static_cast<int>((end_time - start_time) / step_size);

    s.shift_up();
    s.shift_up();
    s.shift_up();
    s.shift_up();

    for (int i = 0; i < n_steps; ++i)
    {
        s.step(step_size, 1.0);

        if (i % (n_steps / 10) == 0)
        {
            std::cout << "speed of the car is:'" << s.get_speed() * 3.6 << "' km/h and engine rpm is: '" << s.get_engine_rpm() << "'" << std::endl;
        }
    }
}