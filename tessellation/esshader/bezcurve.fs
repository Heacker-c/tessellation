#version 320 es

precision highp float;

out vec4 FragColor;

in vec3 color;

void main()
{
    FragColor.xyz = color;
}
