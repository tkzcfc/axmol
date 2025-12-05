#version 310 es
precision highp float;
precision highp int;

#include "base.glsl"
#include "colorUtils.glsl"

layout(location = COLOR0) in vec4 v_color;
layout(location = TEXCOORD0) in vec2 v_texCoord;

layout(binding = 0) uniform sampler2D u_tex0; // y
layout(binding = 1) uniform sampler2D u_tex1; // cb
layout(binding = 2) uniform sampler2D u_tex2; // cr

mat4 rec601 = mat4(
	1.16438,  0.00000,  1.59603, -0.87079,
	1.16438, -0.39176, -0.81297,  0.52959,
	1.16438,  2.01723,  0.00000, -1.08139,
	0, 0, 0, 1
);

layout(location = SV_Target0) out vec4 FragColor;

void main()
{
    float y = texture(u_tex0, v_texCoord).r;
    float cb = texture(u_tex1, v_texCoord).r;
    float cr = texture(u_tex2, v_texCoord).r;
    
    FragColor = vec4(y, cb, cr, 1.0) * rec601;
}
