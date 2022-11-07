#version 400

out vec4 fColor;

in vec3 color;

void main()
{
    fColor.xyz = color;
}