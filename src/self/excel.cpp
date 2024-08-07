#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
struct Person {
    std::string name;
    int age;
    std::string occupation;
};

std::vector<Person> readCSV(const std::string& filename) {
    std::vector<Person> people;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return people;
    }

    std::string line;
    std::getline(file, line); // Skip the header row

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Person person;
        std::getline(iss, person.name, ',');
        std::string ageStr;
        std::getline(iss, ageStr, ',');
        person.age = std::stoi(ageStr); // Convert age string to integer
        std::getline(iss, person.occupation, ',');
        people.push_back(person);
    }

    file.close();
    return people;
}

void writeCSV(const std::string& filename, const std::vector<Person>& people) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }
    file << "Name,Age,Occupation\n"; // Write the header row
    for (const auto& person : people) {
        file << person.name << "," << person.age << "," << person.occupation << "\n"; // Write each person's data
    }
    file.close();
}
int main() {
    std::string filename = "D:\\programming\\C++\\example.csv";
    // Create the CSV file
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return 1;
    }
    
    file << "Name,Age,Occupation\n";
    // Write some sample data
    file << "John,25,Software Engineer\n";
    file << "Alice,30,Doctor\n";
    file << "Bob,35,Teacher\n";

    file.close();

    std::cout << "CSV file created successfully!" << std::endl;

    fflush(stdin);
    std::cin.get();
    return 0;
}