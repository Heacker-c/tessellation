#ifndef SCENESIMPLETESSMORE_H
#define SCENESIMPLETESSMORE_H

#include "scene.h"
#include "glslprogram.h"

#include "cookbookogl.h"

#include <glm/glm.hpp>

class SceneSimpletessMore : public Scene
{
private:
    GLSLProgram prog;

    GLuint vaoHandle;
    GLuint eboHandle;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneSimpletessMore() {}

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};

#endif // SCENEBEZCURVE_H
