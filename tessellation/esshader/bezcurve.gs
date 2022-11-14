#version 320 es

layout( lines ) in;
layout( line_strip, max_vertices = 2 ) out;

out vec3 color;

void main()
{
#define p(i)  gl_in[i].gl_Position

    color.xy = (p(0).xy + p(1).xy) / vec2(1.5);
    color.x = 1.0 - color.x;
    color.z = color.x + color.y;

    gl_Position = p(0);
    EmitVertex();

    gl_Position = p(1);
    EmitVertex();

    EndPrimitive();
}
