/*
 * Problem 661 - Blowing Fuses
 */
#include <iostream>
#include <sstream>

struct Device {
    int amps;
    bool status;
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test {};
    int numberOfDevices;
    int numberOfOperations;
    int capacity;
    while (std::cin >> numberOfDevices >> numberOfOperations >> capacity) {
        if (numberOfDevices == 0 && numberOfOperations == 0 && capacity == 0) {
            break;
        }
        int currentAmps {};
        int maxAmps {};
        bool blown {};
        Device a[25] {};
        for (int i = 1; i <= numberOfDevices; ++i) {
            std::cin >> a[i].amps;
            a[i].status = false;
        }
        for (int i = 0; i < numberOfOperations; ++i) {
            int device;
            std::cin >> device;
            currentAmps += (a[device].status ? -a[device].amps : a[device].amps);
            a[device].status = !a[device].status;
            if (currentAmps > capacity) {
                blown = true;
            }
            maxAmps = std::max(maxAmps, currentAmps);
        }
        output << "Sequence " << ++test << '\n';
        output << "Fuse " << (blown ? "was" : "was not") << " blown.\n";
        if (!blown) {
            output << "Maximal power consumption was " << maxAmps << " amperes.\n";
        }
        output << "\n";
    }
    std::cout << output.str();
}
