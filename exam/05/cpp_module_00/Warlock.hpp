#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>

class Warlock {
	private:
		Warlock();
		Warlock(const Warlock& ref);
		Warlock& operator=(const Warlock& ref);
		std::string name;
		std::string title;
	public:
		Warlock(const std::string& ref_name, const std::string& ref_title);
		~Warlock();
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string ref_title);
		void introduce() const;
};

#endif