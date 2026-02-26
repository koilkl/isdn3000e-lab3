#include "task2.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

#include "polyscope/polyscope.h"
#include "polyscope/surface_mesh.h"

#include <igl/readOBJ.h>
#include <Eigen/Core>

void task2() {
    polyscope::init();

    std::ifstream in("assets/bunny.obj");
    if (!in) {
        std::cerr << "Failed to open assets/bunny.obj\n";
        return;
    }

    std::vector<std::array<double, 3>> V;
    std::vector<std::array<int, 3>> F;

    // TODO 1: Please parse the bunny.obj input, get the vertices and faces, and visualize the mesh.

    std::string line;
    while (std::getline(in, line)) {
    std::istringstream iss(line);
    std::string tag;
    iss >> tag;
    if (tag == "v") {
    double x, y, z;
    iss >> x >> y >> z;
    V.push_back({x, y, z});
    } else if (tag == "f") {
    int a, b, c;
    iss >> a >> b >> c; // assumes "f a b c"
    F.push_back({a - 1, b - 1, c - 1});
    }
    }  
    auto* obj = polyscope::registerSurfaceMesh("bunny", V, F);
    polyscope::show();
}

// TODO 2: import Eigen and libigl in CMakeLists.txt and use methods from those to read and visualize the bunny.obj mesh.
void task2_with_libigl() {
    polyscope::init();

    Eigen::MatrixXd V;
    Eigen::MatrixXi F;

    // Use libigl's readOBJ method to parse the mesh
    igl::readOBJ("assets/bunny.obj", V, F);

    auto* obj = polyscope::registerSurfaceMesh("bunny", V, F);
    polyscope::show();
}
