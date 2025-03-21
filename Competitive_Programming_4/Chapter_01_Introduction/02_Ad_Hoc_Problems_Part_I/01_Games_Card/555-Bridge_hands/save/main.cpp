/*
 * Problem 555 - Bridge Hands
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int charToInt(char c)
{
	if (c == '2') return 2;
	if (c == '3') return 3;
	if (c == '4') return 4;
	if (c == '5') return 5;
	if (c == '6') return 6;
	if (c == '7') return 7;
	if (c == '8') return 8;
	if (c == '9') return 9;
	if (c == 'T') return 10;
	if (c == 'J') return 11;
	if (c == 'Q') return 12;
	if (c == 'K') return 13;
	return 14;
}

class Card
{
	public:
		char suite;
		char value;
		int num;

		bool operator<(const Card &rhs) const {
			return num < rhs.num;
		}
};

int dealerToPlayer(char c)
{
	if (c == 'N') 
		return 2;
	if (c == 'S')
		return 0;
	if (c == 'E') 
		return 3;
	return 1;
}

std::vector<Card> southClubs;
std::vector<Card> southSpades;
std::vector<Card> southDiamonds;
std::vector<Card> southHearts;

std::vector<Card> northClubs;
std::vector<Card> northSpades;
std::vector<Card> northDiamonds;
std::vector<Card> northHearts;

std::vector<Card> eastClubs;
std::vector<Card> eastSpades;
std::vector<Card> eastDiamonds;
std::vector<Card> eastHearts;

std::vector<Card> westClubs;
std::vector<Card> westSpades;
std::vector<Card> westDiamonds;
std::vector<Card> westHearts;

int main()
{
	std::ios::sync_with_stdio(false);
	std::ostringstream output;

	char dealer;
	while (std::cin >> dealer && dealer != '#') {
		int player = dealerToPlayer(dealer);

		southClubs.clear();
		northClubs.clear();
		eastClubs.clear();
		westClubs.clear();
		southSpades.clear();
		northSpades.clear();
		eastSpades.clear();
		westSpades.clear();
		southHearts.clear();
		northHearts.clear();
		eastHearts.clear();
		westHearts.clear();
		southDiamonds.clear();
		northDiamonds.clear();
		eastDiamonds.clear();
		westDiamonds.clear();

		std::string s1, s2;
		std::cin >> s1 >> s2;
		std::string in = s1 + s2;
		for (int i = 0; i < in.size(); i += 2) {

			player = (player + 1) % 4;
			Card card;
			card.suite = in[i];
			card.value = in[i + 1];
			card.num = charToInt(in[i + 1]);
			switch (player) {
				case 1:		// west
					if (in[i] == 'C') {
						westClubs.push_back(card);
					} else if (in[i] == 'S') {
						westSpades.push_back(card);
					} else if (in[i] == 'D') {
						westDiamonds.push_back(card);
					} else if (in[i] == 'H') {
						westHearts.push_back(card);
					}
					break;

				case 2:		// north
					if (in[i] == 'C') {
						northClubs.push_back(card);
					} else if (in[i] == 'S') {
						northSpades.push_back(card);
					} else if (in[i] == 'D') {
						northDiamonds.push_back(card);
					} else if (in[i] == 'H') {
						northHearts.push_back(card);
					}
					break;

				case 3:		// east
					if (in[i] == 'C') {
						eastClubs.push_back(card);
					} else if (in[i] == 'S') {
						eastSpades.push_back(card);
					} else if (in[i] == 'D') {
						eastDiamonds.push_back(card);
					} else if (in[i] == 'H') {
						eastHearts.push_back(card);
					}
					break;

				case 0:		// south
					if (in[i] == 'C') {
						southClubs.push_back(card);
					} else if (in[i] == 'S') {
						southSpades.push_back(card);
					} else if (in[i] == 'D') {
						southDiamonds.push_back(card);
					} else if (in[i] == 'H') {
						southHearts.push_back(card);
					}
					break;
			}
		}
		std::sort(southClubs.begin(), southClubs.end());
		std::sort(southSpades.begin(), southSpades.end());
		std::sort(southDiamonds.begin(), southDiamonds.end());
		std::sort(southHearts.begin(), southHearts.end());

		std::sort(northClubs.begin(), northClubs.end());
		std::sort(northSpades.begin(), northSpades.end());
		std::sort(northDiamonds.begin(), northDiamonds.end());
		std::sort(northHearts.begin(), northHearts.end());

		std::sort(eastClubs.begin(), eastClubs.end());
		std::sort(eastSpades.begin(), eastSpades.end());
		std::sort(eastDiamonds.begin(), eastDiamonds.end());
		std::sort(eastHearts.begin(), eastHearts.end());

		std::sort(westClubs.begin(), westClubs.end());
		std::sort(westSpades.begin(), westSpades.end());
		std::sort(westDiamonds.begin(), westDiamonds.end());
		std::sort(westHearts.begin(), westHearts.end());

		output << "S:";
		for (int i = 0; i < southClubs.size(); ++i) {
			output << " " << southClubs[i].suite << southClubs[i].value;
		}
		for (int i = 0; i < southDiamonds.size(); ++i) {
			output << " " << southDiamonds[i].suite << southDiamonds[i].value;
		}
		for (int i = 0; i < southSpades.size(); ++i) {
			output << " " << southSpades[i].suite << southSpades[i].value;
		}
		for (int i = 0; i < southHearts.size(); ++i) {
			output << " " << southHearts[i].suite << southHearts[i].value;
		}
		output << '\n';

		output << "W:";
		for (int i = 0; i < westClubs.size(); ++i) {
			output << " " << westClubs[i].suite << westClubs[i].value;
		}
		for (int i = 0; i < westDiamonds.size(); ++i) {
			output << " " << westDiamonds[i].suite << westDiamonds[i].value;
		}
		for (int i = 0; i < westSpades.size(); ++i) {
			output << " " << westSpades[i].suite << westSpades[i].value;
		}
		for (int i = 0; i < westHearts.size(); ++i) {
			output << " " << westHearts[i].suite << westHearts[i].value;
		}
		output << '\n';

		output << "N:";
		for (int i = 0; i < northClubs.size(); ++i) {
			output << " " << northClubs[i].suite << northClubs[i].value;
		}
		for (int i = 0; i < northDiamonds.size(); ++i) {
			output << " " << northDiamonds[i].suite << northDiamonds[i].value;
		}
		for (int i = 0; i < northSpades.size(); ++i) {
			output << " " << northSpades[i].suite << northSpades[i].value;
		}
		for (int i = 0; i < northHearts.size(); ++i) {
			output << " " << northHearts[i].suite << northHearts[i].value;
		}
		output << '\n';

		output << "E:";
		for (int i = 0; i < eastClubs.size(); ++i) {
			output << " " << eastClubs[i].suite << eastClubs[i].value;
		}
		for (int i = 0; i < eastDiamonds.size(); ++i) {
			output << " " << eastDiamonds[i].suite << eastDiamonds[i].value;
		}
		for (int i = 0; i < eastSpades.size(); ++i) {
			output << " " << eastSpades[i].suite << eastSpades[i].value;
		}
		for (int i = 0; i < eastHearts.size(); ++i) {
			output << " " << eastHearts[i].suite << eastHearts[i].value;
		}
		output << '\n';
	}
	std::cout << output.str();
}
