#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "sedan.hpp"

TEST_CASE("Test Cars")
{

    Sedan s; // car starts in reverse gear

    double step_size = 0.01;
    double start_time = 0.0;
    double end_time = 10.0;
    int n_steps = static_cast<int>((end_time - start_time) / step_size);

    REQUIRE(s.get_speed() == 0.0);

    SECTION("Forwards")
    {
        s.shift_up(); // remember to shift from -1 -> 1 gear

        for (int i = 0; i < n_steps; ++i)
        {
            s.step(step_size, 1.0);

            if (i % (n_steps / 100) == 0)
            {
                std::cout << "time: '" << i * step_size << "': "
                          << "speed of the car is:'" << s.get_speed() << "' ms/s and engine rpm is: '" << s.get_engine_rpm() << "'" << std::endl;
            }
        }

        REQUIRE(s.get_speed() == Approx(32).margin(1.0)); // car should hit ~ 32 m/s after 10 seconds
    }

    SECTION("Backwards")
    {
        for (int i = 0; i < n_steps; ++i)
        {
            s.step(step_size, 1.0);

            if (i % (n_steps / 100) == 0)
            {
                std::cout << "time: '" << i * step_size << "': "
                          << "speed of the car is:'" << s.get_speed() << "' ms/s and engine rpm is: '" << s.get_engine_rpm() << "'" << std::endl;
            }
        }

        REQUIRE(s.get_speed() == Approx(-32).margin(1.0)); // car should hit ~ -32 m/s after 10 seconds
    }
}
