#version 320 es

layout( triangles ) in;
layout( triangle_strip, max_vertices = 3 ) out;

void main()
{
#define p(i)  gl_in[i].gl_Position

    gl_Position = p(0);
    EmitVertex();

    gl_Position = p(1);
    EmitVertex();

    gl_Position = p(2);
    EmitVertex();

    EndPrimitive();
}
