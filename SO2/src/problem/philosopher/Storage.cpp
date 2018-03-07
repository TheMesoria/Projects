#include "Storage.hpp"

/// @brief Creates storage with certain amount of forks.
/// @param amount - forks which should be added
Storage::Storage(unsigned int amount){ forkVector_ = std::vector<Fork>(amount); }
/// @brief Fetch fork ptr from vector
/// @param id Fork id to be fetched
/// @return Fork ptr
Storage::Fork *Storage::getKey(unsigned id){ return &forkVector_[id]; }
