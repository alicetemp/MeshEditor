#include "Application.h"


void Application::registerCommand(std::unique_ptr<Command> command)
{
	if(command != nullptr)
		commandContainer.emplace(command->getName(), command);
}

int Application::execute(int argc, char * argv[])
{
	if (argc > 1)
	{
		std::string commandName = strtok(argv[1], " ");
		std::map<std::string, std::string> args;
		char *parameterName;
		while ((parameterName = strtok(0, "=")) != nullptr)
		{
			args.emplace(parameterName, strtok(0, ","));
		}

		auto iter = commandContainer.find(commandName);
		if(iter != commandContainer.end())
			iter->second->execute(args);
	}
	return 0;
}
