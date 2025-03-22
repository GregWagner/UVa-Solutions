#include <iostream>

int main() {
	float velocity, acceleration, time;
	std::cin >> velocity >> acceleration >> time;

	std::cout << velocity * time + 0.5 * acceleration * time * time << '\n';
}