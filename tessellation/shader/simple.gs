#version 400

layout( triangles ) in;
layout( triangle_strip, max_vertices = 3 ) out;

out vec3 color;

void main()
{
#define p(i)  gl_in[i].gl_Position

    color = ((p(0) + p(1) + p(2)).xyz  + vec3(1.0))/ vec3(4.0);

    gl_Position = p(0);
    EmitVertex();

    gl_Position = p(1);
    EmitVertex();

    gl_Position = p(2);
    EmitVertex();

    EndPrimitive();
}
