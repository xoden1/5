#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

bool is_positive(std::pair<int, std::string> p) {
	return (p.first > 0);
}

bool is_null(int i) {
	return i == 0;
}

int show(std::pair<int, std::string> p) {
	std::cout << p.first << " = " << p.second << "; ";
	return 0;
}

int show_v(int i) {
	std::cout << i << ' ';
	return 0;
}

int main() {
	//#1
	std::unordered_multimap<int, std::string> arr({ {0, "string0"},{-5, "string1"},{-1, "string2"},{3, "string3"},{5, "string4"},{7, "string5"},{8, "string6"} });
	std::cout << "1: ";
	std::for_each(arr.begin(), arr.end(), show);
	std::cout << std::endl;
	//#1.1
	arr.insert(std::make_pair(7, "string7"));
	arr.insert(std::make_pair(7, "string8"));
	arr.insert(std::make_pair(7, "string9"));
	std::cout << "1.1: ";
	std::for_each(arr.begin(), arr.end(), show);
	std::cout << std::endl;
	//#1.2
	arr.erase(3);
	std::cout << "1.2: ";
	std::for_each(arr.begin(), arr.end(), show);
	std::cout << std::endl;
	//#1.3
	std::map<int, std::string> arr2;
	for (auto i : arr) {
		arr2.insert(std::make_pair(i.first, i.second));
	}
	std::cout << "1.3: ";
	std::for_each(arr2.begin(), arr2.end(), show);
	std::cout << std::endl;
	//#2.1
	int cnt = std::count_if(arr2.begin(), arr2.end(), is_positive);
	std::cout << "2.1: " << cnt << std::endl;
	//#2.2
	std::vector<int> arr3;
	std::transform(arr2.begin(), arr2.end(), std::back_inserter(arr3), [](const std::pair<int, std::string> p) {return p.first;});
	std::cout << "2.2: ";
	std::for_each(arr3.begin(), arr3.end(), show_v);
	std::cout << std::endl;
	//#3.1
	auto idx = std::find(arr3.begin(), arr3.end(), -1);
	if (idx == arr3.end()) std::cout << "3.1: Not Found" << std::endl;
	else std::cout << "3.1: " << idx - arr3.begin() << std::endl;
	//#3.2
	std::replace_if(arr3.begin(), arr3.end(), is_null, 3);
	std::cout << "3.2: ";
	std::for_each(arr3.begin(), arr3.end(), show_v);
	std::cout << std::endl;
	//#3.3
	std::sort(arr3.begin(), arr3.end(), [](int a, int b) {return a > b;});
	std::cout << "3.3: ";
	std::for_each(arr3.begin(), arr3.end(), show_v);
	std::cout << std::endl;
	//#3.4
	std::set<int> arr4;
	for (auto i : arr3) {
		arr4.insert(i);
	}
	std::cout << "3.4: ";
	std::for_each(arr4.begin(), arr4.end(), show_v);
	std::cout << std::endl;
	return 0;
}
