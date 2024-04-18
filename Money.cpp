#include <iostream>
using namespace std;

class Money {
private:
    int amount;
    string currency;

public:
    Money(int amount, const string& currency)
        : amount(amount), currency(currency) {}

    int getAmount() const {
        return amount;
    }

    string getCurrency() const {
        return currency;
    }

    Money operator+(const Money& other) const {
        if (currency != other.currency) {
            throw invalid_argument("Cannot add values in different currencies");
        }
        return Money(amount + other.amount, currency);
    }

    Money operator-(const Money& other) const {
        if (currency != other.currency) {
            throw invalid_argument("Cannot subtract values in different currencies");
        }
        return Money(amount - other.amount, currency);
    }

    Money operator*(int multiplier) const {
        return Money(amount * multiplier, currency);
    }

    Money operator/(int divisor) const {
        return Money(amount / divisor, currency);
    }

    bool operator==(const Money& other) const {
        return amount == other.amount && currency == other.currency;
    }

    bool operator!=(const Money& other) const {
        return !(*this == other);
    }

    bool operator<(const Money& other) const {
        if (currency != other.currency) {
            throw invalid_argument("Cannot compare values in different currencies");
        }
        return amount < other.amount;
    }

    bool operator>(const Money& other) const {
        if (currency != other.currency) {
            throw invalid_argument("Cannot compare values in different currencies");
        }
        return amount > other.amount;
    }
};


ostream& operator<<(ostream& os, const Money& money) {
    return os << money.getAmount() << " " << money.getCurrency();
}


int main() {
    try {
        Money indianRupee(100, "INR");
        Money otherIndianRupee(50, "INR");
        Money usd(100, "USD");

        Money indianRupeeSum = indianRupee + otherIndianRupee;
        cout << "Sum of INR : " << indianRupeeSum << endl;
        
        Money indianRupeeDiff = indianRupee - otherIndianRupee;
        cout << "Diff of INR : " << indianRupeeDiff << endl;
        
        Money indianRupeeMult = indianRupee * 2;
        cout << "Mult of INR : " << indianRupeeMult << endl;
        
        Money indianRupeeDiv = indianRupee / 2;
        cout << "Div of INR : " << indianRupeeDiv << endl;


        cout << boolalpha;

        cout << "Indian Rupee objects are equal : " << (indianRupee == otherIndianRupee) << endl;
        cout << "Indian Rupee objects are not equal : " << (indianRupee != otherIndianRupee) << endl;
        cout << "Indian Rupee objects are less than : " << (indianRupee < otherIndianRupee) << endl;
        cout << "Indian Rupee objects are greater than : " << (indianRupee > otherIndianRupee) << endl;



    } catch (const invalid_argument& e) {
        cout << "Invalid operation: " << e.what() << endl;
    }
    return 0;
}

