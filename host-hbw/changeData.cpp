#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Read the JSON file
    std::ifstream input("Data/Config.HBW.Storage.json");
    json jsonData;
    input >> jsonData;
    input.close();

    // Modify the JSON data
    jsonData["Storage"]["A2"]["state"] = 1;
    jsonData["Storage"]["A2"]["tag_uid"] = "new_tag_uid";
    jsonData["Storage"]["A2"]["type"] = 2;

    // Write the modified JSON data back to the file
    std::ofstream output("Data/Config.HBW.Storage.json");
    output << jsonData.dump(4);  // You can use dump(4) for pretty formatting
    output.close();

    std::cout << "JSON file updated." << std::endl;

    return 0;
}

