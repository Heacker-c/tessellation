#version 320 es

precision highp float;

out vec4 fColor;

in vec3 color;

void main()
{
    fColor.xyz = color;
}