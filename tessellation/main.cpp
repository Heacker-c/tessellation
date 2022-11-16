#include "scenerunner.h"
#include "scenebezcurve.h"
#include "scenebezcurve-debug.h"
#include "scenesimpletessmore.h"
#include "scenesimpletess.h"
#include "scenetessteapot.h"
#include "scenetessteapotdepth.h"

#include <map>

std::map<std::string, std::string> sceneInfo = {
            { "bez-curve", "2D Bezier curve with tessellation shader" },
            { "tess-simple", "simple tessellation demo" },
            { "tess-teapot", "Uses tessellation to draw a teapot" },
            { "tess-teapot-depth", "Varies the amount of tessellation with depth" }
};

int main(int argc, char* argv[])
{
    std::string recipe("bez-curve-debug");

    SceneRunner runner("Tessellation - " + recipe);

    std::unique_ptr<Scene> scene;
    if (recipe == "bez-curve")
    {
        scene = std::unique_ptr<Scene>(new SceneBezCurve());
    }
    else if (recipe == "bez-curve-debug")
    {
        scene = std::unique_ptr<Scene>(new SceneBezCurveDebug());
    }
    else if (recipe == "tess-simple-more")
    {
        scene = std::unique_ptr<Scene>(new SceneSimpletessMore());
    }
    else if (recipe == "tess-simple")
    {
        scene = std::unique_ptr<Scene>(new SceneSimpletess());
    }
    else if (recipe == "tess-teapot")
    {
        scene = std::unique_ptr<Scene>(new SceneTessTeapot());
    }
    else if (recipe == "tess-teapot-depth")
    {
        scene = std::unique_ptr<Scene>(new SceneTessTeapotDepth());
    }
    else
    {
        printf("Unknown recipe: %s\n", recipe.c_str());
        exit(EXIT_FAILURE);
    }

    return runner.run(std::move(scene));
}
