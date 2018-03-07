#ifndef SO2_PHILOSOPHER_HPP
#define SO2_PHILOSOPHER_HPP

#include <string>
#include "Controller.hpp"

/// @brief Instance of philosopher. It will simulate behaviour of human in app.
class Philosopher
{
	unsigned id_; ///< @brief Philosopher identifier.
	std::string name_; ///< @brief Philosopher name [optional]
	Controller* controller_; ///< @brief Controller which is used by philosopher.
public:
	Philosopher(
			Controller *controller,
			unsigned int id,
			const std::string &name=""
			   );
	
	void DoYourThing();
};

#endif //SO2_PHILOSOPHER_HPP
