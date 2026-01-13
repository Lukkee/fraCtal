#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <vector>

class Mesh {
public:
    unsigned int VAO, VBO;
    Mesh(std::vector<float> vertices);
    ~Mesh();
    void draw();
};

#endif
