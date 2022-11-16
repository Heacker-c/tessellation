#ifndef SCENEBEZCURVEDEBUG_H
#define SCENEBEZCURVEDEBUG_H

#include "scene.h"
#include "glslprogram.h"

#include "cookbookogl.h"

#include <glm/glm.hpp>

class SceneBezCurveDebug : public Scene
{
private:
    GLSLProgram prog;
    GLSLProgram solidProg;

    GLuint vaoHandle;

    void setMatrices();
    void compileAndLinkShader();

public:
    SceneBezCurveDebug();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};

#endif // SceneBezCurveDebug_H
