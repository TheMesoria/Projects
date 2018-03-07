#ifndef SO2_STORAGE_HPP
#define SO2_STORAGE_HPP

#include <vector>

/// @brief It stores all shared data in program.
class Storage
{
public:
	struct Fork{bool Avaiable=true;}; ///< @brief Represents a fork used by philosophers
private:
	/// @brief Represents the fork collection. <br />
	/// First fork is presented to the left side of n-th philosopher,
	/// and to the 1-st  philosophers right.
	std::vector<Fork> forkVector_;
public:
	explicit Storage(unsigned amount=5);
	Fork* getKey(unsigned id);
};

#endif //SO2_STORAGE_HPP
