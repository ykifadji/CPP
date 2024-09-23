#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& cpy) {*this = cpy;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_paires = other._paires;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::parseArgs(std::string av) {
	long int	tmp = std::strtol(av.c_str(), NULL, 0);
	if (tmp > INT_MAX)
		throw std::invalid_argument("Error: int max limit.");
	for (size_t i = 0; i < av.size(); i++) {
		if (!isdigit(av.at(i)))
			throw std::invalid_argument("Error: is not a positive number.");
	}
}

PmergeMe::PmergeMe(char **av, int ac) {
	size_t	size = ac;
	for (size_t i = 1; i < size; i++) {
		parseArgs(av[i]);
		_vec.push_back(std::atoi(av[i]));
	}
	createPairs();
}

void	PmergeMe::createPairs() {
	for (size_t	i = 0; i < _vec.size(); i += 2) {
		if (i + 1 < _vec.size()) {
			if (_vec[i] > _vec[i + 1])
				_paires.push_back(std::make_pair(_vec[i + 1], _vec[i]));
			else
				_paires.push_back(std::make_pair(_vec[i], _vec[i + 1]));
		} else {
			_paires.push_back(std::make_pair(_vec[i], -1));
		}
	}
	sortFusionInsertion();
}

std::vector<int>	generateJacobsthal(int n) {
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	if (n > 1) jacobsthal.push_back(3);

	for (int i = 2; i < n; ++i) {
		int	next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		if (next >= n) break;
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

void	PmergeMe::merge(std::vector<int>& vec, int left, int mid, int right) {
	int	n1 = mid - left + 1;
	int	n2 = right - mid;

	std::vector<int>	leftVec(n1);
	std::vector<int>	rightVec(n2);

	for (int i = 0; i < n1; ++i)
		leftVec[i] = vec[left + i];
	for (int i = 0; i < n2; ++i)
		rightVec[i] = vec[mid + i + 1];

	int	i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftVec[i] <= rightVec[j])
			vec[k++] = leftVec[i++];
		else
			vec[k++] = rightVec[j++];
	} 
	while (i < n1)
		vec[k++] = leftVec[i++];
	while (j < n2)
		vec[k++] = rightVec[j++];
}

void	PmergeMe::mergeSort(std::vector<int>& vec, int left, int right) {
	if (left < right) {
		int	mid = left + (right - left) / 2;
		mergeSort(vec, left, mid);
		mergeSort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}
}

void	PmergeMe::sortFusionInsertion() {
	std::vector<int>	first;
	std::vector<int>	seconds;

	for (size_t	i = 0; i < _paires.size(); i++) {
		first.push_back(_paires[i].first);
		if (_paires[i].second != -1)
			seconds.push_back(_paires[i].second);
	}
	//PRINT FIRST ET SECONDS
	std::cout << "first: ";
	for (size_t	i = 0; i < first.size(); ++i)
		std::cout << first[i] << ' ';
	std::cout << std::endl;

	std::cout << "seconds: ";
	for (size_t	i = 0; i < seconds.size(); ++i)
		std::cout << seconds[i] << ' ';
	std::cout << std::endl;

	//Trier recursivement les max
	mergeSort(seconds, 0, seconds.size() - 1);

	//PRINT SECONDS APRES TRI
	std::cout << "seconds after merge sort: ";
	for (size_t	i = 0; i < seconds.size(); ++i)
		std::cout << seconds[i] << ' ';
	std::cout << std::endl;

	//generer la suite de jacobsthal selon la taille des valeurs max
	std::vector<int> jacobsthal = generateJacobsthal(seconds.size());

	//PRINT SUITE DE JACOBSTHAL
	std::cout << "jacobsthal: ";
	for (size_t	i = 0; i < jacobsthal.size(); ++i)
		std::cout << jacobsthal[i] << ' ';
	std::cout << std::endl;

	//Inserer une valeur de min à la bonne place dans max selon la suite de jacobsthal
	for (size_t i = 0; i < first.size(); ++i) {
		size_t index = jacobsthal[i];  // Index dans la suite de Jacobsthal

		if (index < first.size()) {
		// Insérer la valeur de first[index] dans seconds à la bonne place
			std::cout << "index = " << first[index] << std::endl;
			std::vector<int>::iterator pos = std::lower_bound(seconds.begin(), seconds.end(), first[index]);
			seconds.insert(pos, first[index]);
		}

		// Afficher le vecteur pour vérifier l'insertion
		std::cout << "Après insertion de " << first[i] << " : ";
		for (size_t j = 0; j < seconds.size(); ++j) {
			std::cout << seconds[j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "final sort: ";
	for (size_t	i = 0; i < seconds.size(); ++i)
		std::cout << seconds[i] << ' ';
	std::cout << std::endl;
}
