#pragma once

#include <fstream>
#include "OutputController.hpp"

class FileOutput:
	public OutputController
{
	std::string path_;
public:
	void update() override;
	
	explicit FileOutput(std::string path="run.log");
	~FileOutput() final;
};


