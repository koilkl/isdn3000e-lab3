#include "task4.h"

#include <array>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "polyscope/polyscope.h"
#include "polyscope/surface_mesh.h"
#include "polyscope/point_cloud.h"
#include "imgui.h"

void task4() {
    polyscope::init();

    // ============================================================
    // 1) Read mesh
    // ============================================================
    std::ifstream in("assets/bunny.obj");
    if (!in) {
        std::cerr << "Failed to open assets/bunny.obj\n";
        return;
    }
    std::vector<std::array<double, 3>> V0;
    std::vector<std::array<int, 3>> F;
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string tag;
        iss >> tag;

        if (tag == "v") {
            double x, y, z;
            iss >> x >> y >> z;
            V0.push_back({x, y, z});
        } else if (tag == "f") {
            int a, b, c;
            iss >> a >> b >> c;
            F.push_back({a - 1, b - 1, c - 1});
        }
    }
    auto* bunny = polyscope::registerSurfaceMesh("bunny", V0, F);
    auto* bunnyPts = polyscope::registerPointCloud("bunny_points", V0);

    // ============================================================
    // 2) UI initial setting
    // ============================================================
    bool showMesh = true;
    bool showPoints = true;
    float alpha = 0.5f;
    float pointRadius = 0.001f;
    bunny->setEnabled(showMesh);
    bunnyPts->setEnabled(showPoints);
    bunny->setTransparency(alpha);
    bunnyPts->setPointRadius(pointRadius);
    // TODO 1: Set the initial appearance of the mesh.
    //  - You must explicitly call: setSurfaceColor(), setPosition() or translate() to define the starting color and location of the object.
    //  - You can set the input color or position value by {0.1, 0.1, 0.1}
    //  - You can also set the initial transparency and point radius values using setTransparency() and setPointRadius().

     bunny->setSurfaceColor({0.1, 0.1, 0.1});
     bunnyPts->setPointColor({0.1, 0.1, 0.1});
     bunny->setPosition({0.1, 0.1, 0.1});
     bunnyPts->setPosition({0.1, 0.1, 0.1});
     bunny->setTransparency(0.5f);
     bunnyPts->setPointRadius(0.001f);

    // ============================================================
    // 3) UI callback (runs every frame)
    // ============================================================
    polyscope::state::userCallback = [&]() {

        // TODO 2: Add a title text to the UI window using ImGui::Text(). The title should describe what this control panel is for.

        ImGui::Separator();
        ImGui::Text("Mesh Appearance Control Panel");
        bool changed = false;
        if (ImGui::Checkbox("Show Mesh", &showMesh))
            changed = true;
        if (ImGui::Checkbox("Show Points", &showPoints))
            changed = true;
        if (ImGui::SliderFloat("Mesh Transparency", &alpha, 0.0f, 1.0f))
            changed = true;
        if (ImGui::SliderFloat("Point Radius", &pointRadius, 0.0001f, 0.01f))
            changed = true;
        if (ImGui::Button("Reset")) {
            changed = true;
        }
        // TODO 3: Add at least:
        //      - ONE Checkbox (e.g. checkbox to show point cloud of the mesh)
        //      - ONE Slider (e.g. sliders to change transparency or point radius values)
        //      - ONE Button (e.g. reset button to set all properties back to initial values)
        //  - You may control ANY property of the mesh (e.g., position, color, rotation, size, transparency, etc.)
        if (changed) {
            bunny->setEnabled(showMesh);
            bunnyPts->setEnabled(showPoints);
            bunny->setTransparency(alpha);
            bunnyPts->setPointRadius(pointRadius);
        }
        

        // TODO 4: Use the 'changed' variable to update the object properties.
        //  - When the UI value changes, apply the new settings so that the object updates dynamically every frame.
        //  - You can start with a "if (changed) { ... }"

    };

    polyscope::show();
}