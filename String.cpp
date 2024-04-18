#include <cstring>
#include <iostream>

using namespace std;

class String {
    private:
        char *data;
        unsigned int length;

    public:
        String() : data(nullptr), length(0) {}

        String(const char *str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }

        String(const String &other) {
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }

        ~String() {
            delete[] data;
        }

    char* toCharArray() const {
        char* result = new char[length + 1];
        strcpy(result, data);
        return result;
    }


        String &operator=(const char arr[]) {
            length = strlen(arr);
            data = new char[length + 1];
            strcpy(data, arr);
            return *this;
        }

        String operator+(const String &other) const {
            String result;
            result.length = length + other.length;
            result.data = new char[result.length + 1];
            strcpy(result.data, data);
            strcat(result.data, other.data);
            return result;
        }

        bool operator==(const String &other) const {
            return (length == other.length) && (strcmp(data, other.data) == 0);
        }

        bool operator!=(const String &other) const {
            return !(*this == other);
        }

        const char &operator[](unsigned int index) const {
            if (index >= length) {
                throw out_of_range("Index out of range");
            }
            return data[index];
        }


};


ostream &operator<<(ostream &os, const String &str) {
    os << str.toCharArray();
    return os;
}



int main() {
    String hello("Hello");
    String world = "world";

    String helloWorld = hello + world;

    cout << boolalpha;
    cout << (hello == hello) << " - same string" << endl;  // true
    cout << (hello != world) << " - different strings" << endl;  // true
    cout << helloWorld[5] << " - 6th character of helloWorld" << endl;  // l
    

    cout << hello << " - Hello" << endl;

    return 0;
}


