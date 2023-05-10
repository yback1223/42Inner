/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:32:35 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:32:37 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void replace(std::string inFileName, std::string s1, std::string s2) {
	std::string line;
	std::string outFileName = std::string() + inFileName + ".replace";
	std::ifstream inputstream(inFileName.c_str());
	std::ofstream outputstream(outFileName.c_str());

	if (!inputstream || !outputstream) {
		std::cerr << "File Missing!" << std::endl;
		exit(1);
	}

	while (std::getline(inputstream, line)) {
		std::string result;
		std::string::size_type curPos = 0;

		while (curPos < line.length()) {
			std::string::size_type nextPos = line.find(s1, curPos);
			if (nextPos == std::string::npos) {
				result += line.substr(curPos);
				break;
			} else {
				result += line.substr(curPos, nextPos - curPos);
				result += s2;
				curPos = nextPos + s1.length();
			}
		}
		outputstream << result << std::endl;
	}
	inputstream.close();
	outputstream.close();
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Error: Wrong Arguments!" << std::endl;
		return (1);
	}
	replace(av[1], av[2], av[3]);
}