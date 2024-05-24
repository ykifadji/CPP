/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:37:39 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/24 08:00:49 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Usage: " << av[0] << " <nom_du_fichier> <s1> <s2>" << std::endl;
		return 1;
	}
	for (int i = 1; i <= 3; ++i) {
		if (std::string(av[i]).empty()) {
			std::cout << "Arguments cannot be empty." << std::endl;
			return 1;
		}
	}
	std::string	s1 = std::string(av[2]);
	std::string	s2 = std::string(av[3]);

	std::ifstream	filesrc(av[1]);
	if (!filesrc.is_open()) {
		std::cout << "Error: unable to open file." << std::endl;
		return 1;
	}
	std::stringstream	buffer;

	buffer << filesrc.rdbuf();
	std::string	content = buffer.str();

	std::cout << "\033[1m\033[38;5;202m\t\tOriginal content\033[0m" << std::endl;
	std::cout << content << std::endl;

	std::ostringstream	modifiedContent;

	size_t	pos = 0;
	while (pos < content.size()) {
		size_t	foundPos = content.find(s1, pos);
		if (foundPos == std::string::npos) {
			modifiedContent << content.substr(pos);
			break;
		}
		modifiedContent << content.substr(pos, foundPos - pos);
		modifiedContent << s2;
		pos = foundPos + s1.size();
	}

	std::cout << "\033[1m\033[38;5;48m\t\tFinal content\033[0m" << std::endl;

	std::ofstream	filedst((std::string(av[1]) + ".replace").c_str());

	filedst << modifiedContent.str();
	std::cout << modifiedContent.str() << std::endl;

	return 0;
}
