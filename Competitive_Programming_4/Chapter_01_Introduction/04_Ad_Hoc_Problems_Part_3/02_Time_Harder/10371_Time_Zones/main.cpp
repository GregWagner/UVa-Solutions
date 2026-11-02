#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

// Map time zone abbreviations to UTC offsets in minutes
std::unordered_map<std::string, int> tzOffset = {
    {"UTC", 0},     {"GMT", 0},     {"BST", 60},   {"IST", 60},   {"WET", 0},
    {"WEST", 60},   {"CET", 60},    {"CEST", 120}, {"EET", 120},  {"EEST", 180},
    {"MSK", 180},   {"MSD", 240},   {"AST", -240}, {"ADT", -180}, {"NST", -210},
    {"NDT", -150},  {"EST", -300},  {"EDT", -240}, {"CST", -360}, {"CDT", -300},
    {"MST", -420},  {"MDT", -360},  {"PST", -480}, {"PDT", -420}, {"HST", -600},
    {"AKST", -540}, {"AKDT", -480}, {"AEST", 600}, {"AEDT", 660}, {"ACST", 570},
    {"ACDT", 630},  {"AWST", 480}};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {

        std::string timeStr;
        std::cin >> timeStr;

        int totalMinutes{};

        if (timeStr == "noon") {
            totalMinutes = 12 * 60; // 12:00 PM
        } else if (timeStr == "midnight") {
            totalMinutes = 0; // 12:00 AM
        } else {
            std::string ampm;
            std::cin >> ampm;

            int hour{stoi(timeStr.substr(0, timeStr.find(':')))};
            int minute{stoi(timeStr.substr(timeStr.find(':') + 1))};

            if (hour == 12) {
                hour = 0;
            }
            if (ampm == "p.m.") {
                hour += 12;
            }

            totalMinutes = hour * 60 + minute;
        }

        std::string srcTZ, destTZ;
        std::cin >> srcTZ >> destTZ;

        // Convert from source time zone to UTC
        totalMinutes -= tzOffset[srcTZ];

        // Convert from UTC to destination time zone
        totalMinutes += tzOffset[destTZ];

        // Normalize minutes to [0, 1439]
        totalMinutes = ((totalMinutes % 1440) + 1440) % 1440;

        if (totalMinutes == 0) {
            output << "midnight\n";
        } else if (totalMinutes == 12 * 60) {
            output << "noon\n";
        } else {
            int hour{totalMinutes / 60};
            int minute{totalMinutes % 60};

            std::string ampm = (hour >= 12) ? "p.m." : "a.m.";
            hour %= 12;
            if (hour == 0) {
                hour = 12;
            }

            output << hour << ":" << std::setfill('0') << std::setw(2) << minute
                   << " " << ampm << "\n";
            std::cout << std::setfill(' ');
        }
    }
    std::cout << output.str();
}
