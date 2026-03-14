#include "io_building_elements.h"
#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
building_elements_in read_input(const char* filename)
{
    building_elements_in d{};
    std::ifstream file(filename);

    if(!file)
    {
        std::cerr << "Cannot open input!\n";
        return d;
    }

    std::string word;

    while(file >> word)
    {
        if(word == "height_floor") file >> d.height_floor;
        else if(word == "vertical_step") file >> d.vertical_step;
        else if(word == "horizontal_step") file >> d.horizontal_step;
        else if(word == "S") file >> d.S;
        else if(word == "G1") file >> d.G1;
        else if(word == "G2") file >> d.G2;
        else if(word == "n_floors") file >> d.n_floors;
        else if(word == "fc28") file >> d.fc28;
        else if(word == "fe") file >> d.fe;
        else if(word == "Q_rooftop") file >> d.Q_rooftop;
        else if(word == "Q_curent_floor") file >> d.Q_current_floor;
        else if(word == "Q_ground_floor") file >> d.Q_ground_floor;
    }

    return d;
}

void write_result(const char* filename, const stair_result& stair,
                  const RC_column_result& column)
{
    std::ofstream file(filename);

    if(file.is_open())
    {
        file << "-----------------\n";
        file << "stairs \n";
        file << "-----------------\n";
        file << "height_stairs cm " << stair.height_stairs << "\n\n";
        file << "Number of stairs " << stair.n_stairs << "\n\n";
        file << "stair length cm " << stair.length_stairs << "\n\n";

        if(stair.rule_valid)
            file << "Comfort rule validated\n";
        else
            file << "Comfort rule NOT validated\n";

        file << "-----------------\n";
        file << "reinforced concrete column  \n";
        file << "-----------------\n";
        file << std::fixed << std::setprecision(3);
        file << "Smaj " << column.Smaj << "\n\n";
        file << "NG KN " << column.NG << "\n\n";
        file << "NQ KN " << column.NQ << "\n\n";
        file << "Nu KN " << column.Nu << "\n\n";
        file << "alpha " << column.alpha << "\n\n";
        file << "gamma c concrete factor " << column.gamma_c << "\n\n";
        file << "gamma s steel factor  " << column.gamma_s << "\n\n";
        file << "Br min  m2 " << column.Br_min << "\n\n";
        file << "a min  m " << column.a_min << "\n\n";


        file.close();
    }
}
