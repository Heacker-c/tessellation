#include "scenerunner.h"
#include "scenetessteapot.h"
#include "scenetessteapotdepth.h"


int main(int argc, char *argv[])
{
	std::string recipe("tess-teapot");

	SceneRunner runner("Tessellation - " + recipe);

	std::unique_ptr<Scene> scene;
    if( recipe == "tess-teapot" )
    {
        scene = std::unique_ptr<Scene>( new SceneTessTeapot() );
    } else if( recipe == "tess-teapot-depth" )
    {
        scene = std::unique_ptr<Scene>( new SceneTessTeapotDepth() );
    } else {
        printf("Unknown recipe: %s\n", recipe.c_str());
        exit(EXIT_FAILURE);
    }

    return runner.run(std::move(scene));
}
