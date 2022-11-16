#version 320 es

precision highp float;
layout ( location = 0 ) out vec4 FragColor;

in vec4 color1;
in vec4 color2;
in vec4 color3;
in vec4 color4;

void main()
{
    FragColor.xyz = color1.xyz;
}
