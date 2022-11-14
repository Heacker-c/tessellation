#version 320 es

precision highp float;

uniform vec4 Color;

out vec4 FragColor;

void main()
{
    FragColor = Color;
}
