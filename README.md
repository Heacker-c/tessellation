# tessellation
opengl tessellation test

如果想要opengl代码切换opengles的测试程序切换
打开#define EGL 1 表示使用 opengles
注释掉表示使用opengl

修改shader的话，注意重新cmake，才会拷贝到运行目录下，或者直接修改运行目录下的shader也可以
注意：opengl走的shader文件夹，opengles走的esshader文件夹
