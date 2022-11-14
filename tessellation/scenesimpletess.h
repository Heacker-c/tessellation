#ifndef SCENESIMPLETESS_H
#define SCENESIMPLETESS_H

#include "scene.h"
#include "glslprogram.h"

#include "cookbookogl.h"

#include <glm/glm.hpp>

class SceneSimpletess : public Scene
{
private:
    GLSLProgram prog;

    GLuint vaoHandle;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneSimpletess() {}

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};

#endif // SCENEBEZCURVE_H
