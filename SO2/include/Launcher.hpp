#ifndef SO2_LAUNCHER_HPP
#define SO2_LAUNCHER_HPP

#include "Controller.hpp"
#include "Philosopher.hpp"

/// @brief Servers as the application entry point. Later, works as exit point.
class Launcher
{
	Controller controller_;
	std::vector<Philosopher> philosopherVector_;
public:
	void Start(); ///< @brief Starts the application.
private:
	void spawnPhilosophers(); ///< @brief Initialise philosophers
};


#endif //SO2_LAUNCHER_HPP
