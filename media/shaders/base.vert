// vertex Shader base.vert

#version 120

attribute vec3 inPosition;
attribute vec3 inNormal;
attribute vec2 inUv;
attribute vec3 inTangent;

varying vec3 outNormal;
varying vec2 outUv;
varying vec3 outTangent;

void main(void)
{
	gl_Position = vec4(inPosition, 0);
	outNormal = inNormal;
	outUv = inUv;
	outTangent = inTangent;
}