#version 400

out highp vec4 fColor;

in highp vec3 color;

void main()
{
    fColor.xyz = color;
}