#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cmath>

std::ostringstream output;

struct Entry {
    std::string account;
    long long amountInCents;
};

auto formatCurrency(long long cents) -> std::string {
    bool negative{cents < 0};
    if (negative) {
        cents = -cents;
    }

    long long dollars = cents / 100;
    long long remaindingCents = cents % 100;

    std::string result = std::to_string(dollars) + "." +
                         (remaindingCents < 10 ? "0" : "") +
                         std::to_string(remaindingCents);
    if (negative)
        result = "-" + result;

    return result;
}

auto processTransaction(
    const std::string& seq, const std::vector<Entry>& entries,
    long long totalCents,
    const std::unordered_map<std::string, std::string>& accounts) -> void {

    if (totalCents == 0) {
        // balanced transaction
        return;
    }
    output << "*** Transaction " << seq << " is out of balance ***\n";

    for (const auto& entry : entries) {
        std::string name =
            accounts.count(entry.account) ? accounts.at(entry.account) : "";
        output << entry.account << ' ' << std::left << std::setw(30) << name
               << std::right << std::setw(11)
               << formatCurrency(entry.amountInCents) << '\n';
    }

    output << "999 " << std::left << std::setw(30) << "Out of Balance"
           << std::right << std::setw(11) << formatCurrency(-totalCents)
           << "\n\n";
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<std::string, std::string> accounts;

    // read in account numbers and names
    std::string input;
    while (std::getline(std::cin, input) && input.length() >= 3) {
        std::string accountNumber = input.substr(0, 3);
        if (accountNumber == "000") {
            break;
        }
        std::string accountName = input.substr(3);
        std::size_t start = accountName.find_first_not_of(' ');
        if (start != std::string::npos) accountName = accountName.substr(start);
        else accountName.clear();
        accounts[accountNumber] = accountName;
    }

    // read in transactions
    std::string current{};
    std::vector<Entry> currentEntries;
    long long runningSum{};

    while (std::getline(std::cin, input) && input.length() >= 6) {
        std::string sequence{input.substr(0, 3)};
        if (sequence == "000") {
            break;
        }
        std::string accountNumber = input.substr(3, 3);
        long long cents = std::stoll(input.substr(6));

        if (!current.empty() && sequence != current) {
            processTransaction(current, currentEntries, runningSum, accounts);
            currentEntries.clear();
            runningSum = 0;
        }
        current = sequence;
        currentEntries.push_back({accountNumber, cents});
        runningSum += cents;
    }

    // process the last transactions
    if (!current.empty()) {
        processTransaction(current, currentEntries, runningSum, accounts);
    }
    std::cout << output.str();
}
