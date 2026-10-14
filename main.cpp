// A modular, menu-driven program that computes health club membership fees.

#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

namespace {

struct Membership {
    std::string name;
    long monthlyCents;  // money is kept in whole cents so totals are exact
};

// The menu is built from this table: add a row and it appears as an option.
const Membership MEMBERSHIPS[] = {
    {"Standard Adult", 4000},
    {"Child",          2000},
    {"Senior Citizen", 3000},
};
constexpr int MEMBERSHIP_COUNT = static_cast<int>(std::size(MEMBERSHIPS));
constexpr int QUIT_CHOICE      = MEMBERSHIP_COUNT + 1;
constexpr int MAX_MONTHS       = 120;

std::string formatCents(long cents)
{
    std::ostringstream out;
    out << '$' << cents / 100 << '.' << std::setw(2) << std::setfill('0') << cents % 100;
    return out.str();
}

// Reads a whole line and accepts it only if it is an integer in [low, high].
// Returns false at end of input, so the caller can stop instead of looping.
bool readInt(const std::string& prompt, int low, int high, int& value)
{
    std::string line;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, line)) {
            return false;
        }
        std::istringstream in(line);
        char extra;
        if (in >> value && !(in >> extra) && value >= low && value <= high) {
            return true;
        }
        std::cout << "Please enter a whole number from " << low << " to " << high << ".\n";
    }
}

void displayMenu()
{
    std::cout << "\n    Health Club Membership Menu\n\n";
    for (int i = 0; i < MEMBERSHIP_COUNT; ++i) {
        std::cout << "  " << i + 1 << ". " << std::left << std::setw(16) << MEMBERSHIPS[i].name
                  << formatCents(MEMBERSHIPS[i].monthlyCents) << " / month\n";
    }
    std::cout << "  " << QUIT_CHOICE << ". Quit\n\n";
}

void showFees(const Membership& membership, int months)
{
    std::cout << "\n  Membership type : " << membership.name
              << "\n  Number of months: " << months
              << "\n  Total charges   : " << formatCents(membership.monthlyCents * months) << "\n";
}

}  // namespace

int main()
{
    int choice;
    while (true) {
        displayMenu();
        if (!readInt("Enter your choice: ", 1, QUIT_CHOICE, choice) || choice == QUIT_CHOICE) {
            break;
        }
        int months;
        if (!readInt("For how many months? ", 1, MAX_MONTHS, months)) {
            break;
        }
        showFees(MEMBERSHIPS[choice - 1], months);
    }
    std::cout << "\nGoodbye!\n";
    return 0;
}
