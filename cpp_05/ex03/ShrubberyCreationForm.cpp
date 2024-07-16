/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:16:01 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/16 14:58:54 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("unknown") {
	std::cout << GREEN"ShrubberyCreationForm default constructor called" DEF << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery creation", 145, 137), _target(target) {
	std::cout << GREEN"ShrubberyCreationForm parameter constructor called" DEF << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : AForm(cpy), _target(cpy._target){
	std::cout << GREEN"ShrubberyCreationForm copy constructor called" DEF << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << RED"ShrubberyCreationForm destructor called" DEF << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (getSigned() == false)
		throw(FormNotSignedException());
	else if (executor.getGrade() > getGradeExec())
		throw(GradeTooLowException());
	else {
		std::ofstream	file((_target + "_shrubbery").c_str());
		if (!file.is_open())
			std::cerr << "ERROR: unable to open file" << std::endl;
		file << GREEN"					%%                 \n";
		file << GREEN"		%       #%   %%%%      %     %#%                \n";
		file << GREEN"	     %%%    %###    %%###   %%%   ##%%    %%%      \n";
		file << GREEN"		%%% #####%%%  % %%%#% #%%#  ####%%%%% %         \n";
		file << GREEN"		%#%#####% %%% %%##% %%%%#%#%%%##%#%%#% %%       \n";
		file << GREEN"		%%%%%%%%%%##%####%%#%#% %%  #%%%%#%%%##%%         \n";
		file << GREEN"	 %%%%%%%%%%%###% %% %%            % %  %%%%%%%%%    \n";
		file << GREEN"	%% %% % %%##%   ##%##%%#%##% % % %%%%%%%%% % %%##%%  \n";
		file << GREEN"	%%%%% ##%%%% %# %# %%%%%###%%%%%# % %%% %% %%#%%%%% \n";
		file << GREEN"	 %  %##%  ###% %% %%#  %      % # ###%%%%%% %%  %   \n";
		file << GREEN"		%%%%%%%%% %%%  %% ##% %   % %  %  %% %%## %#%%%% \n";
		file << GREEN"\t       ###% %%%%% %%#  % %       %%%%      %%   %%%  %# \n";
		file << GREEN"\t  %%   % %%% #%%%%    %%%  ###%   %%###%  %%%%  % %     \n";
		file << GREEN"	%%%  %%   %#% %%  %%  %%%%%%    %#%%#  %%    #%#     \n";
		file << GREEN"\t%  %##%#%#%%%%%#%#%%%%#% %%#% %       #%%     %% %  %    \n";
		file << GREEN"\t%#%%%%# %%%%  %      %      %  #%        % %  %  %       \n";
		file << GREEN"\t%%% %#% %% % %%%%%%%% %%  %       %     #% % % %%       \n";
		file << GREEN"\t%##%%%%%#% %   %%   ##% %%%#%      %          %        \n";
		file << GREEN"	  % %    %        %###%% #                           \n";
		file << GREEN"	         %   % %%#                     %           \n";
		file << GREEN"	              #%                       %           \n";
		file << GREEN"			%% %   %%   \033[38;5;130m%%                          \n" DEF;
		file << GREEN"			%        \033[38;5;130m% %                          \n";
		file << "				\033[38;5;130m% %                          \n";
		file << "				\033[38;5;130m%%%                          \n";
		file << "				\033[38;5;130m%%%                          \n";
		file << "				\033[38;5;130m%%%%                          \n";
		file << "				\033[38;5;130m%%%%                          \n";
		file << "				\033[38;5;130m%                            \n";
		file << "				\033[38;5;130m%%%                           \n" DEF;
	}
}
