#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <format>

#include "debug.h"
#include "imu.h"

IMU load_data (const std::string ifilename) {
    std::ifstream infile (ifilename);
    debug::log ("Opening file" + ifilename + " for reading\n");
    IMU data;

    std::string line;
    std::getline (infile, line);
    std::istringstream stream (line);
    std::string thigh_ang, shin_ang, thigh_accel, vert_accel;
    stream >> thigh_ang >> shin_ang >> thigh_accel >> vert_accel;

    while (std::getline (infile, line)) {
        std::istringstream stream (line);
        double thigh_ang, shin_ang, thigh_accel, vert_accel;
        stream >> thigh_ang >> shin_ang >> thigh_accel >> vert_accel;
        if (!stream)
            throw std::runtime_error ("error while reading data from PPG file \"" + ifilename + "\"");
        data.thigh_ang.push_back(thigh_ang);
        data.shin_ang.push_back(shin_ang);
        data.thigh_accel.push_back(thigh_accel);
        data.vert_accel.push_back(vert_accel);
    }
    debug::log(std::format("Read {} entries from file\n", data.thigh_ang.size()));

    return data;
}
