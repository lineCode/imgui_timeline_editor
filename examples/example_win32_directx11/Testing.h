#pragma once

#include <string>
#include <vector>
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

// Data structure
struct VEC2 { VEC2(){} VEC2(float x, float y) : x(x), y(y) {} float x; float y; };
struct VEC4 { VEC4(){} VEC4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {} float x; float y; float z; float w; };

template <typename SpecialNode>
struct Animation {
    //Animation() {}
    /*Animation(std::string name, VEC2 pos, VEC2 scale, VEC4 color) :
        name(name), pos(pos), scale(scale), color(color) {}*/

    void addTransformNode(VEC2 new_transform, float time) { transformNodes.push_back(std::pair<VEC2,float>(new_transform, time)); }
    void addScaleNode(VEC2 new_scale, float time) { scaleNodes.push_back(std::pair<VEC2, float>(new_scale, time)); }
    void addColorNode(VEC4 new_color, float time) { colorNodes.push_back(std::pair<VEC4, float>(new_color, time)); }
    void addSpecialNode(SpecialNode new_special, float time) { specialNodes.push_back(std::pair<SpecialNode, float>(new_special, time)); }

    static void displayTransformPopup(std::pair<VEC2, float> node, int id) {
        ImGui::Text("Transform");
        ImGui::Text("");
        ImGui::Text("Node: %d", id);
        ImGui::Text("X: %.2f  Y: %.2f", node.first.x, node.first.y);
        ImGui::Text("Time: %.2f", node.second);
    }
    static void displayScalePopup(std::pair<VEC2, float> node, int id){
        ImGui::Text("Scale");
        ImGui::Text("");
        ImGui::Text("Node: %d", id);
        ImGui::Text("X: %.2f  Y: %.2f", node.first.x, node.first.y);
        ImGui::Text("Time: %.2f", node.second);
    }
    static void displayColorPopup(std::pair<VEC4, float> node, int id) {
        ImGui::Text("Color");
        ImGui::Text("");
        ImGui::Text("Node: %d", id);
        ImGui::Text("Color: RGBA: %.2f %.2f %.2f %.2f", node.first.x, node.first.y, node.first.z, node.first.w);
        ImGui::SameLine();
        ImGui::ColorEdit4("##2f", (float*)& node.first, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
        ImGui::Text("Time: %.2f", node.second);
    }
    //virtual void displaySpecialPopup() = 0;

    static void displayTransformContextMenu(std::pair<VEC2, float> node, int id) {
        ImGui::Text("Transform");
        ImGui::DragFloat2("##transform", &node.first.x, 0.01f, -100.0f, 100.0f, "%.2f");
    }

    std::string name;
    std::vector<std::pair<VEC2, float>> transformNodes;
    std::vector<std::pair<VEC2, float>> scaleNodes;
    std::vector<std::pair<VEC4, float>> colorNodes;
    std::vector<std::pair<SpecialNode, float>> specialNodes;
    float time = 0.0f;
};

class Testing
{
public:
	Testing();
	~Testing();
    void Render();
    float position = 2.0f;

private:
    float max_time = 10.0f;
    bool show_columns = true;
    std::vector<Animation<float>*> _animations;
    Animation<float> a1;
    ImGuiColorEditFlags misc_flags = ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_AlphaPreview;
};

