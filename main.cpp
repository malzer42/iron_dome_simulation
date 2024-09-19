/** 
 * File: main.cpp
 * Author(s): Pierre Abraham Mulamba
 * Date creation (modification): 20240919 (20240919) 
 * Description: Program to Simulate the Irom Dome of Israel Defense force
 */ 

#include <iostream>
#include <random>
#include <chrono>
#include <memory>
#include <bitset>
#include <random>
#include <ctime>

int main(int argc, char const *argv[])
{
    std::cout << "This section deals with the Bitwise Operations\n";
    std::cout << "-------------   AIR DEFENSE SYSTEM   -------------------\n";
    std::cout << "---------------IRON DOME SIMULATION---------------------\n";
    const unsigned int FIRST_FLAG = 0b1;   // Binary representation of the integer 1
    const unsigned int SECOND_FLAG = 0b10; // Binary representation of the integer 2
    const unsigned int THIRD_FLAG = 0b11;  // Binary representation of the integer 3

    unsigned int flags = FIRST_FLAG | SECOND_FLAG | THIRD_FLAG;
    std::cout << flags;
    // std::cout << std::bitset<32>(flags) << '\n';
    unsigned int trigger = 0b1;
    std::random_device rd;                        // obtain a random number from hardware
    std::mt19937 gen(rd());                       // seed the generator
    std::uniform_int_distribution<> distr(0, 32); // define the range
    unsigned int ironDomeInterceptors = 0b0;
    unsigned int ironDomePosition = 0b0;
    unsigned int ironDomeMissiles = 0b0;
    unsigned int terroristRockets = 0b0;

    for (unsigned int i = 0; i < 32; i++)
    {

        switch (i)
        {
        case 0b1:
            terroristRockets = (trigger << i);
            std::cout << "\nTerrorist Rocket------->: " << std::bitset<32>(terroristRockets) << '\n';

            ironDomePosition = (trigger << distr(gen));
            std::cout << "Iron Dome Position-----x: " << std::bitset<32>(ironDomePosition) << '\n';

            ironDomeInterceptors = (~ironDomePosition) & terroristRockets;
            std::cout << "Iron Dome Interceptors-<: " << std::bitset<32>(ironDomeInterceptors) << '\n';

            if (terroristRockets ^ ironDomeInterceptors)
            {
                std::cout << "\nIron Dome Launcher destroyed\n";
            }
            else
            {
                std::cout << "\nOptimal Position for the Iron Dome Launcher\n";
            }

        case 0b10:
            terroristRockets = i;
            std::cout << "\nTerrorist Rocket------->: " << std::bitset<32>(terroristRockets) << '\n';

            ironDomePosition = (trigger << distr(gen));
            std::cout << "Iron Dome Position-----x: " << std::bitset<32>(ironDomePosition) << '\n';

            ironDomeInterceptors = (~ironDomePosition) & terroristRockets;
            std::cout << "Iron Dome Interceptors-<: " << std::bitset<32>(ironDomeInterceptors) << '\n';

            if (terroristRockets ^ ironDomeInterceptors)
            {
                std::cout << "\nIron Dome Launcher destroyed\n";
            }
            else
            {
                std::cout << "\nOptimal Position for the Iron Dome Launcher\n";
            }

        case 0b11:
            terroristRockets = (!trigger << 0b11);
            std::cout << "\nTerrorist Rocket------->: " << std::bitset<32>(terroristRockets) << '\n';

            ironDomePosition = (trigger << distr(gen));
            std::cout << "Iron Dome Position-----x: " << std::bitset<32>(ironDomePosition) << '\n';

            ironDomeInterceptors = (~ironDomePosition) & terroristRockets;
            std::cout << "Iron Dome Interceptors-<: " << std::bitset<32>(ironDomeInterceptors) << '\n';

            if (terroristRockets ^ ironDomeInterceptors)
            {
                std::cout << "\nIron Dome Launcher destroyed\n";
            }
            else
            {
                std::cout << "\nOptimal Position for the Iron Dome Launcher\n";
            }

        default:
            terroristRockets = (~trigger << i);
            std::cout << "\nTerrorist Rocket------->: " << std::bitset<32>(terroristRockets) << '\n';

            ironDomePosition = (trigger << distr(gen));
            std::cout << "Iron Dome Position-----x: " << std::bitset<32>(ironDomePosition) << '\n';

            ironDomeInterceptors = (~ironDomePosition) & terroristRockets;
            std::cout << "Iron Dome Interceptors-<: " << std::bitset<32>(ironDomeInterceptors) << '\n';

            ironDomeMissiles = ironDomeInterceptors; // (~trigger >> distr(gen));
            std::cout << "Iron Dome Missiles>>>>>>: " << std::bitset<32>(ironDomeMissiles) << '\n';

            if (terroristRockets ^ ironDomeInterceptors)
            {
                std::cout << "\nIron Dome Launcher destroyed\n";
            }
            else
            {
                std::cout << "\nOptimal Position for the Iron Dome Launcher\n";
            }
        }
    }
    return 0;
}