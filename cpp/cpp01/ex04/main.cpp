/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:32:35 by yback             #+#    #+#             */
/*   Updated: 2023/05/10 17:27:17 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void replace(std::string inFileName, std::string s1, std::string s2) {
	if (s1 == "") {
		std::cerr << "Error: Invalid Argument!" << std::endl;
		exit(1);
	}
	std::string line;
	std::ifstream inputstream(inFileName.c_str());
	if (!inputstream) {
		std::cerr << "Input file Missing!" << std::endl;
		exit(1);
	}
	std::string outFileName = inFileName.append(".replace");
	std::ofstream outputstream(outFileName.c_str());
	if (!outputstream) {
		std::cerr << "Output file Missing!" << std::endl;
		exit(1);
	}
	int j = 0;
	while (true) {
		bool res = std::getline(inputstream, line, '\n');
		if (!res ) {
			break;
		} else if (j != 0) {
			outputstream << std::endl;
		}
		std::string result;
		std::string::size_type curPos = 0;
		j++;

		while (curPos < line.length()) {
			std::string::size_type nextPos = line.find(s1, curPos);
			if (nextPos == static_cast<std::string::size_type>(-1)) {
				result.append(line.substr(curPos));
				break;
			} else {
				result.append(line.substr(curPos, nextPos - curPos));
				result.append(s2);
				curPos = nextPos + s1.length();
			}
		}
		outputstream << result;
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