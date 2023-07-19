#include <string>

class Player
{
	private:
		std::string name{};
	public:
		void setName(const std::string& n);
		std::string	getName();
};