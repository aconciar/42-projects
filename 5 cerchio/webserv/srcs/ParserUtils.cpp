/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:55:03 by ucolla            #+#    #+#             */
/*   Updated: 2025/03/12 16:17:59 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "ConfigError.hpp"

void Parser::checkServerLine(std::string line) {
    size_t serverPos = line.find("server");
    size_t startPos = serverPos + 6;

    size_t lastBracePos = line.rfind('{');
    if (lastBracePos == std::string::npos || lastBracePos <= startPos)
        throw ConfigFileError("Missing opening bracket ", parsingCounter);

    std::string before = line.substr(0, startPos - 6);
    if (before != "")
        throw InvalidKeywordError("Invalid keyword '" + before + "'", parsingCounter);

    line = line.substr(startPos, lastBracePos - startPos);
    if (hasAlpha(line))
        throw InvalidKeywordError("Invalid keyword '" + line + "'", parsingCounter);
}

void Parser::checkEmptyFile(std::ifstream &file) {
	if (_file.get() == EOF)
		throw EmptyFile("The file is empty", 0);
	_file.seekg(0);

	std::string line;
	while (getline(file, line)) {
		if (line.find('#') == 0)
		continue;
		if (line.find('#') != std::string::npos)
		line = line.substr(0, line.find('#') - 1);
		if (hasAlpha(line))
		{
			if (line.find("server") == std::string::npos)
				throw InvalidKeywordError("Invalid keyword before server block:\n'" + line + "'", parsingCounter);
			else
				return ;
		}
		parsingCounter++;
	}
	throw EmptyFile("The file is empty", 0);
}

bool Parser::hasAlpha(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isspace(str[i]))
            return true;
    }
    return false;
}

bool Parser::checkClosingBracket(std::string &line) {
	size_t n = line.find("}");
	if (n == std::string::npos)
		return false;

	std::string before = line.substr(0, n);
	std::string after = line.substr(n + 1);

	if (hasAlpha(before) || hasAlpha(after))
		throw InvalidKeywordError(line, parsingCounter);
	return true;
}

void Parser::checkAfterBracket(std::string line, char c) {
	size_t bracket = line.find_last_of(c);
	if (hasAlpha(line.substr(bracket + 1)))
		throw InvalidKeywordError(line.substr(bracket + 1), parsingCounter);
}

void Parser::invalidKeyword(std::istringstream &stream) {
	std::string invalid;
	if (stream >> invalid)
		throw InvalidKeywordError(invalid, parsingCounter);
}

void Parser::aliasWarning(Router &location, int parsingCounter) {
	std::string path = location.getPath();
	std::string alias = location.getAlias();
	if ((path[path.size() - 1] != '/' && alias[alias.size() - 1] == '/') ||
		(path[path.size() - 1] == '/' && alias[alias.size() - 1] != '/'))
	{
		std::cout << PURPLE << "[ WARNING ]\n" << RESET << "Mismatch found in location block "
			<< YELLOW << path << RESET << " at line: " << YELLOW << parsingCounter << RESET ".\n"
			<< "Both location name and alias path should end with a trailing slash or neither of those.\n"
			<< "You should fix the problem to avoid unwanted behavior when trying to request files.\n"
			<< "The server will keep running anyway.\n";
	}
}

std::string	Parser::trimLine(const std::string &line) {
	size_t	semicolon = line.find(';');
	if (line.find('{') == std::string::npos && semicolon == std::string::npos)
		throw ConfigFileError("Unclosed directive or invalid keyword --> " + line, parsingCounter);

	std::string directive, unexpected;
	directive = line.substr(0, semicolon);
	unexpected = line.substr(semicolon + 1, line.size() - directive.size());

	if (unexpected != "" && hasAlpha(unexpected))
		throw InvalidKeywordError(unexpected, parsingCounter);

	return directive;
}

static void strToLower(std::string &str) {
	for (size_t i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
	}
}

void	Parser::parseClientMaxBodySize(std::string &client_max_body_size, ServerConfig &server) {
	std::istringstream 	stream(client_max_body_size);
	long long 			size;
	std::string 		UOM;
	
	stream >> size >> UOM;
	if (size < 0)
		throw ConfigFileError("client_max_body_size cannot be less than zero", parsingCounter); 
	if (UOM != "")
	{
		strToLower(UOM);
		if (UOM == "b")
			size *= 1;
		if (UOM == "kb" || UOM == "k")
			size *= 1e3;
		else if (UOM == "mb" || UOM == "m")
			size *= 1e6;
		else if (UOM == "gb" || UOM == "g")
			size *= 1e9;
	}
	server.setClientMaxBodySize(size);
}

void	Parser::isEmpty(std::string &print, std::string &key, std::string param) {
	if (key == param)
		throw ConfigFileError("Empty directive '" + print + "'", parsingCounter);
}
