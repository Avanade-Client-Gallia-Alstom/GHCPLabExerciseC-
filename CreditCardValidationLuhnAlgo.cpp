#include <iostream>
#include <string>

bool validateCreditCard(const std::string& cardNumber) {
    int sum = 0;
    bool doubleDigit = false;

    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) {
                digit = digit % 10 + 1;
            }
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return sum % 10 == 0;
}

int main() {
    std::string cardNumber;
    std::cout << "Enter credit card number: ";
    std::cin >> cardNumber;

    if (validateCreditCard(cardNumber)) {
        std::cout << "Valid credit card number" << std::endl;
    } else {
        std::cout << "Invalid credit card number" << std::endl;
    }

    return 0;
}
