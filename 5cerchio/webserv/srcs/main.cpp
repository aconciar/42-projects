/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:21:03 by andrea            #+#    #+#             */
/*   Updated: 2025/03/17 16:32:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerManager.hpp"
#include "Parser.hpp"
#include "ConfigError.hpp"
#include "SignalHandler.hpp"

volatile sig_atomic_t g_terminate = 0;
volatile sig_atomic_t g_paused = 0;

void	cleanup(ServerManager &manager)
{
	std::cout << PURPLE << "[Webserv] Cleaning up before shutdown..." << RESET << std::endl;
	manager.shutdownServers();
	for (int fd = 3; fd < 104; fd++)
			close(fd);
	std::cout << YELLOW << "[Webserv] Cleanup completed. Exiting now." << RESET << std::endl;
}

void sigchld_handler(int signum)
{
    (void)signum;
    while (waitpid(-1, NULL, WNOHANG) > 0) {}
}

void sigtstp_handler(int signum)
{
    (void)signum;
    g_paused = !g_paused;  // Toggle pause state
    if (g_paused)
        std::cout << PURPLE << "\n[Webserv] PAUSED: Server is no longer accepting new connections." << RESET << std::endl;
    else
        std::cout << GREEN << "\n[Webserv] RESUMED: Server is accepting connections again." << RESET << std::endl;
}

void signal_handler(int signum)
{
	std::cout << RED << "\n[Webserv] Signal Received: " << signum 
	<< ". Termination in progress..." << RESET << std::endl;
	g_terminate = 1;
}

static void	printError(const char *msg, int counter, std::string errorType) {
	
	std::cerr  << RED
				<< "[ "
				<< errorType
				<< " ]"
				<< RESET
				<< " --> "
				<< msg;
	if (counter > 0)
	{
		std::cerr	<< ","
					<< YELLOW
					<< " line: "
					<< counter
					<< RESET
					<< std::endl;
	}
	else
		std::cerr << std::endl;
	std::cerr << "Fix the error and then launch the program again." << std::endl;
}

static int tryParseFile(const std::string &configFile, Parser &config) {
	try {
		config.parseConfigFile(configFile);
	} catch (const PortError& e) {
		printError(e.what(), e.getCounter(), PORT_ERROR);
		return (0);
	} catch (const InvalidKeywordError& e) {
		printError(e.what(), e.getCounter(), INVALID_KEYWORD_ERROR);
		return (0);
	} catch (const MethodError& e) {
		printError(e.what(), e.getCounter(), METHOD_ERROR);
		return (0);
	} catch (const ServerBlockError& e) {
		printError(e.what(), e.getCounter(), SERVER_BLOCK_ERROR);
		return (0);
	} catch (const LocationBlockError& e) {
		printError(e.what(), e.getCounter(), LOCATION_BLOCK_ERROR);
		return (0);
	} catch (const EmptyFile& e) {
		printError(e.what(), e.getCounter(), EMPTY_FILE_ERROR);
		return (0);
	} catch (const ConfigFileError& e) {
		printError(e.what(), e.getCounter(), CONFIG_FILE_ERROR);
		return (0);
	}
	return 1;
}

int	main(int ac, char **av)
{
	Parser 				config;
	ServerManager		manager;

	if (ac > 2)
		return EXIT_FAILURE;
	if (ac == 1)
	{
		if (!tryParseFile(DEFAULT_CONFIG_FILE, config))
			return 0;
		std::cout << "-- Launching web server with basic default configuration --\n";
	}
	if (ac == 2) 
	{
		if (!tryParseFile(av[ac - 1], config))
			return 0;
	}
	
	config.populateServerConfigs(manager);

	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGCHLD, sigchld_handler);
	signal(SIGTSTP, sigtstp_handler);
	signal(SIGPIPE, SIG_IGN);
	std::cout << PURPLE << "[Webserv] Started! Press CTRL+C to terminate." << RESET << std::endl;

	manager.run();
	cleanup(manager);
	return (0);
}
