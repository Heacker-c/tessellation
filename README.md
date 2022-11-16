# tessellation
opengl/opengles tessellation test

如果想要opengl代码切换opengles的测试程序切换,修改glad.h中的宏
#define EGL 1 表示使用 opengles
#define EGL 0 表示使用 opengl

修改shader的话，注意重新cmake，才会拷贝到运行目录下，或者直接修改运行目录下的shader也可以
注意：opengl走的shader文件夹，opengles走的esshader文件夹