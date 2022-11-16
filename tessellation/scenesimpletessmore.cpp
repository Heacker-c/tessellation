#include "scenesimpletessmore.h"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
using glm::vec3;
using glm::vec4;
using glm::mat4;

#define withoutCTS 0
#define withoutPatch 0
#define withoutELEMENT 1

const int  NumVertices = 4;  // vertices in our patch

void SceneSimpletessMore::initScene()
{
    compileAndLinkShader();
    glEnable(GL_DEPTH_TEST);

    float c = 3.5f;
    projection = glm::ortho(-0.4f * c, 0.4f * c, -0.3f * c, 0.3f * c, 0.1f, 100.0f);

    // Set up patch VBO
    GLfloat vertices[NumVertices * 2] =
    {
        -0.5, -0.5 ,
         0.5, -0.5 ,
         0.5,  0.5 ,
        -0.5,  0.5
    };

    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);

    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set up patch VAO
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

#if !withoutELEMENT
    GLint indeces[NumVertices] = { 0, 1, 2, 3 };
    glGenBuffers(1, &eboHandle);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);
#endif

    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

#if withoutCTS & !withoutPatch
    GLfloat levelInner[] = { 3.0f, 3.0f };
    GLfloat levelOuter[] = { 2.0f, 3.0f, 4.0f, 5.0f };
    glPatchParameterfv(GL_PATCH_DEFAULT_INNER_LEVEL, levelInner);
    glPatchParameterfv(GL_PATCH_DEFAULT_OUTER_LEVEL, levelOuter);
#endif

    prog.use();
#if 1
    glClearColor(0.0, 0.0, 0.0, 1.0);
    GLint prom;
    glGetProgramiv(prog.getHandle(), GL_TESS_CONTROL_OUTPUT_VERTICES, &prom);
    std::cout << "GL_TESS_CONTROL_OUTPUT_VERTICES : " << prom << std::endl;
    glGetProgramiv(prog.getHandle(), GL_TESS_GEN_MODE, &prom);
    std::cout << "GL_TESS_GEN_MODE : " << std::hex << prom << std::endl;
    glGetProgramiv(prog.getHandle(), GL_TESS_GEN_SPACING, &prom);
    std::cout << "GL_TESS_GEN_SPACING : " << std::hex << prom << std::endl;
    glGetProgramiv(prog.getHandle(), GL_TESS_GEN_VERTEX_ORDER, &prom);
    std::cout << "GL_TESS_GEN_VERTEX_ORDER : " << std::hex << prom << std::endl;
    glGetProgramiv(prog.getHandle(), GL_TESS_GEN_POINT_MODE, &prom);
    std::cout << "GL_TESS_GEN_POINT_MODE : " << std::hex << prom << std::endl;
#endif
    // Set the number of vertices per patch.  IMPORTANT!!
#if !withoutPatch
    glPatchParameteri(GL_PATCH_VERTICES, 4);
#endif
}

void SceneSimpletessMore::update(float t)
{

}

void SceneSimpletessMore::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    view = glm::lookAt(vec3(0.0f, 0.5f, 1.5f), vec3(0.0f, 0.2f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(mat4(1.0f), glm::radians(-90.0f), vec3(1.0f, 0.0f, 0.0f));

    glBindVertexArray(vaoHandle);
    setMatrices();

#if !withoutPatch
#if withoutELEMENT
    glDrawArrays(GL_PATCHES, 0, 4);
#else
    glDrawElements(GL_PATCHES, 4, GL_UNSIGNED_INT, 0);
#endif
#else
#if withoutELEMENT
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
#else
    glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, 0);
#endif
#endif
}

void SceneSimpletessMore::setMatrices()
{
    mat4 mv = view * model;
    static float theta;
    theta += 0.015f;
    mv = glm::rotate(mv, glm::radians(theta), vec3(0.0f, 0.0f, 1.0f));

    prog.use();
    prog.setUniform("MVP", projection * mv);
}

void SceneSimpletessMore::resize(int w, int h)
{
    glViewport(0, 0, w, h);
}

void SceneSimpletessMore::compileAndLinkShader()
{
    try
    {
#if !withoutPatch
#if !withoutCTS
        prog.compileShader("shader/simplemore.tcs");
#endif
        prog.compileShader("shader/simplemore.tes");
#endif
        prog.compileShader("shader/simplemore.vs");
        prog.compileShader("shader/simplemore.gs");
        prog.compileShader("shader/simplemore.fs");

        prog.link();
        prog.use();
    }
    catch (GLSLProgramException& e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

