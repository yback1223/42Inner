//
// Created by Yong Min Back on 2023/04/26.
//

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
		std::string::size_type cur_pos = 0;

		while (cur_pos < line.length()) {
			std::string::size_type next_pos = line.find(s1, cur_pos);

			if (next_pos == std::string::npos) {
				result += line.substr(cur_pos);
				break;
			} else {
				result += line.substr(cur_pos, next_pos - cur_pos);
				result += s2;
				cur_pos = next_pos + s1.length();
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