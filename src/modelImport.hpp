#define TINYOBJLOADER_IMPLEMENTATION
#include "TOL/tiny_obj_loader.h"
#include <vector>
#include <string>
#include <iostream>





struct Vertex {
    float position[3];
    float normal[3];
    float texCoords[2];
};

class ModelLoader {
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    bool loadModel(const std::string& path) {
        tinyobj::attrib_t attrib;
        std::vector<tinyobj::shape_t> shapes;
        std::vector<tinyobj::material_t> materials;
        std::string warn, err;

        if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, path.c_str())) {
            return false;
        }

        for (const auto& shape : shapes) {
            for (const auto& index : shape.mesh.indices) {
                Vertex vertex{};

                // Координаты
                vertex.position[0] = attrib.vertices[3 * index.vertex_index + 0];
                vertex.position[1] = attrib.vertices[3 * index.vertex_index + 1];
                vertex.position[2] = attrib.vertices[3 * index.vertex_index + 2];

                // Нормали
                if (index.normal_index >= 0) {
                    vertex.normal[0] = attrib.normals[3 * index.normal_index + 0];
                    vertex.normal[1] = attrib.normals[3 * index.normal_index + 1];
                    vertex.normal[2] = attrib.normals[3 * index.normal_index + 2];
                }

                // UV
                if (index.texcoord_index >= 0) {
                    vertex.texCoords[0] = attrib.texcoords[2 * index.texcoord_index + 0];
                    vertex.texCoords[1] = 1.0f - attrib.texcoords[2 * index.texcoord_index + 1]; 
                } else {
                    vertex.texCoords[0] = 0.0f;
                    vertex.texCoords[1] = 0.0f;
                }

                vertices.push_back(vertex);
                indices.push_back((unsigned int)indices.size());
            }
        }
        return true;
    }
};
