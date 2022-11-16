#version 320 es

precision highp float;
layout ( location = 0 ) out vec4 FragColor;

in vec3 color;

void main()
{
    FragColor.xyz = vec3(1.0);
}
