#include "scenebezcurve-debug.h"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include <vector>
using glm::vec3;
using glm::vec4;
using glm::mat4;

SceneBezCurveDebug::SceneBezCurveDebug() {}

std::vector<float>data;
void SceneBezCurveDebug::initScene()
{
    compileAndLinkShader();
    glEnable(GL_DEPTH_TEST);

    float c = 3.5f;
    projection = glm::ortho(-0.4f * c, 0.4f * c, -0.3f * c, 0.3f * c, 0.1f, 100.0f);
    glPointSize(4.0f);

    // Set up patch VBO
    float v[] =
    {
        -0.75f, -0.5f, 
        -0.5f, 0.5f,
        -0.5f, -0.5f, 
        -0.25f, 0.5f
    };

    for (int i = -8; i < 28; ++i)
    {
        data.push_back(v[0] + i * 0.07);
        data.push_back(v[1]);
        data.push_back(v[2] + i * 0.07);
        data.push_back(v[3]);
        data.push_back(v[4] + i * 0.07);
        data.push_back(v[5]);
        data.push_back(v[6] + i * 0.07);
        data.push_back(v[7]);
    }

    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);

    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);

    // Set up patch VAO
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    // Set the number of vertices per patch.  IMPORTANT!!
    glPatchParameteri(GL_PATCH_VERTICES, 4);

    // Segments and strips may be inverted on NVIDIA
    //prog.use();
    //prog.setUniform("NumSegments", 32);
    //prog.setUniform("NumStrips", 32);
    //prog.setUniform("LineColor", vec4(1.0f, 1.0f, 0.5f, 1.0f));

    solidProg.use();
    solidProg.setUniform("NumSegments", 1);
    solidProg.setUniform("NumStrips", 32);
    solidProg.setUniform("Color", vec4(0.5f, 1.0f, 1.0f, 1.0f));
}

void SceneBezCurveDebug::update(float t) {}

void SceneBezCurveDebug::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    vec3 cameraPos(0.0f, 0.0f, 1.5f);
    view = glm::lookAt(cameraPos, vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));

    model = mat4(1.0f);

    glBindVertexArray(vaoHandle);
    setMatrices();

    // Draw the control points
    solidProg.use();
    glDrawArrays(GL_PATCHES, 0, data.size() >> 1);

    // Draw the curve
    //prog.use();
    //glDrawArrays(GL_PATCHES, 0, data.size() >> 1);
}

void SceneBezCurveDebug::setMatrices()
{
    mat4 mv = view * model;
    //prog.use();
    //prog.setUniform("MVP", projection * mv);
    solidProg.use();
    solidProg.setUniform("MVP", projection * mv);
}

void SceneBezCurveDebug::resize(int w, int h)
{
    glViewport(0, 0, w, h);
}

void SceneBezCurveDebug::compileAndLinkShader()
{
    try
    {
        //prog.compileShader("shader/bezcurve-debug.vs");
        //prog.compileShader("shader/bezcurve-debug.gs");
        //prog.compileShader("shader/bezcurve-debug.fs");
        //prog.compileShader("shader/bezcurve-debug.tes");
        //prog.compileShader("shader/bezcurve-debug.tcs");
        //prog.link();

        solidProg.compileShader("shader/bezcurve-debug.vs");
        //solidProg.compileShader("shader/bezcurve-debug2.gs");
        solidProg.compileShader("shader/bezcurve-debug2.fs");
        solidProg.compileShader("shader/bezcurve-debug.tes");
        solidProg.compileShader("shader/bezcurve-debug.tcs");
        solidProg.link();
    }
    catch (GLSLProgramException& e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}
