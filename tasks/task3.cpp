#include "task3.h"

#include <array>
#include <vector>
#include <cmath>

#include "polyscope/polyscope.h"
#include "polyscope/point_cloud.h"
#include "polyscope/curve_network.h"
#include "polyscope/surface_mesh.h"


void task3() {
    polyscope::init();

    // Point
    std::vector<std::array<double, 3>> pointV = { {0.0, 0.0, 0.0} };
    auto* point = polyscope::registerPointCloud("point", pointV);
    point->setPointRadius(0.04);

    // TODO 1: Create at least:
    //   - one line using polyscope::registerCurveNetwork()
    //   - one triangle and one cube using polyscope::registerSurfaceMesh()
    //   Hints:
    //   - vertices: std::vector<std::array<double, 3>>
    //   - edges (for curve network): std::vector<std::array<int, 2>>
    //   - faces (for surface mesh):  std::vector<std::array<int, 3>>

    // TODO 1.1 Line
    std::vector<std::array<double, 3>> lineV = { {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0} };
    std::vector<std::array<int, 2>> lineE = { {0, 1} };
    auto* line = polyscope::registerCurveNetwork("line", lineV, lineE);
    line->setRadius(0.02);
    // TODO 1.2 Face (triangle)
    std::vector<std::array<double, 3>> triV = { {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.5, 1.0, 0.0} };
    std::vector<std::array<int, 3>> triF = { {0, 1, 2} };
    auto* tri = polyscope::registerSurfaceMesh("triangle", triV, triF);
     tri->setEdgeWidth(0.01);
     tri->setSurfaceColor({1.0, 0.0, 0.0});
     // TODO 1.3 Face (cube)
    std::vector<std::array<double, 3>> cubeV = { {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0},
                                                  {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 1.0, 1.0} };
    std::vector<std::array<int, 3>> cubeF = { {0, 1, 2}, {0, 2, 3}, {4, 5, 6}, {4, 6, 7},
                                              {0, 1, 5}, {0, 5, 4}, {2, 3, 7}, {2, 7, 6},
                                              {1, 2, 6}, {1, 6, 5}, {0, 3, 7}, {0, 7, 4} };
    auto* cube = polyscope::registerSurfaceMesh("cube", cubeV, cubeF);
     cube->setEdgeWidth(0.01);
     cube->setSurfaceColor({0.0, 1.0, 0.0});
    // TODO 2: Create a regu`lar tetrahedron and a regular hexagon.
    // TODO 2.1 Regular tetrahedron
    std::vector<std::array<double, 3>> tetraV = { {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.5, std::sqrt(3)/2, 0.0}, {0.5, std::sqrt(3)/6, std::sqrt(6)/3} };
    std::vector<std::array<int, 3>> tetraF = { {0, 1, 2}, {0, 1, 3}, {1, 2, 3}, {2, 0, 3} };
    auto* tetra = polyscope::registerSurfaceMesh("tetrahedron", tetraV, tetraF);
     tetra->setEdgeWidth(0.01);
     tetra->setSurfaceColor({0.0, 0.0, 1.0});
    // TODO 2.2 Regular hexagon
    std::vector<std::array<double, 3>> hexV = { {1.0, 0.0, 0.0}, {0.5, std::sqrt(3)/2, 0.0}, {-0.5, std::sqrt(3)/2, 0.0}, {-1.0, 0.0, 0.0}, {-0.5, -std::sqrt(3)/2, 0.0}, {0.5, -std::sqrt(3)/2, 0.0} };
    std::vector<std::array<int, 3>> hexF = { {0, 1, 2}, {0, 2, 3}, {0, 3, 4}, {0, 4, 5} };
    auto* hex = polyscope::registerSurfaceMesh("hexagon", hexV, hexF);
     hex->setEdgeWidth(0.01);
     hex->setSurfaceColor({1.0, 1.0, 1.0});
    
    polyscope::show();
}