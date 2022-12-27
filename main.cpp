#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<std::string, std::string> phone_book;
	char select_y_n;
	bool bContinue = true;
	std::cout << "You want to ADD data to phone;s book? (y/n):";
	std::cin >> select_y_n;
	while (select_y_n != 'y' && select_y_n != 'n') {
		std::cout << "Incorrect input! Try again!" << std::endl;
		std::cout << "You want to ADD data to phone;s book? (y/n):";
		std::cin >> select_y_n;
	}
	if (select_y_n == 'y') {
		while (bContinue) {
			std::pair<std::string, std::string> phone_Pair;
			std::cout << "Input phone and Last name:" << std::endl;
			std::cin >> phone_Pair.first >> phone_Pair.second;
			phone_book.insert(phone_Pair);

			char select_y_n_2;
			std::cout << "Do you want to continue? (y/n):";
			std::cin >> select_y_n_2;
			while (select_y_n_2 != 'y' && select_y_n_2 != 'n') {
				std::cout << "Incorrect input! Try again!" << std::endl;
				std::cout << "Do you want to continue? (y/n):";
				std::cin >> select_y_n;
			}
			if (select_y_n_2 == 'y')
				bContinue = true;
			else
				bContinue = false;
		}
	}
	int action;
	std::cout << "Select action (2 or 3):" << std::endl;
	std::cout << "Find Last Name by phone number (2) or Find Phone number by Last Name (3):";
	std::cin >> action;
	while (action != 2 && action != 3) {
		std::cout << "INCORRECT input! Try again!" << std::endl;
		std::cout << "Select action (2 or 3):" << std::endl;
		std::cout << "Find Last Name by phone number (2) or Find Phone number by Last Name (3):";
		std::cin >> action;
	}
	if (action == 2) {
		std::cout << "Input phone number for search:";
		std::string phone_search;
		std::cin >> phone_search;
		std::cout << "Result:" << std::endl;
		std::map<std::string, std::string>::iterator it_Phones = phone_book.find(phone_search);
		std::cout << it_Phones->first << " " << it_Phones->second << std::endl;
	} else {
		std::cout << "Input Last Name for search:";
		std::string lastName_search;
		std::cin >> lastName_search;
		std::cout << "Result:" << std::endl;
		for (std::map<std::string, std::string>::iterator it = phone_book.begin();
			 it != phone_book.end(); it++) {
			if (it->second == lastName_search)
			std::cout << it->first << " " << it->second << std::endl;
		}
	}
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "Good by!" << std::endl;
	return 0;
}
