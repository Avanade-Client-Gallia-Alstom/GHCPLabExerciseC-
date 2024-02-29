#include <iostream>
#include <regex>

bool validateCreditCard(const std::string& cardNumber) {
    // Define the regex pattern for credit card validation
    std::regex pattern("^\\d{4}-\\d{4}-\\d{4}-\\d{4}$");

    // Check if the card number matches the pattern
    return std::regex_match(cardNumber, pattern);
}

int main() {
    std::string cardNumber;

    // Get the credit card number from the user
    std::cout << "Enter credit card number: ";
    std::cin >> cardNumber;

    // Validate the credit card number
    if (validateCreditCard(cardNumber)) {
        std::cout << "Valid credit card number" << std::endl;
    } else {
        std::cout << "Invalid credit card number" << std::endl;
    }

    return 0;
}


