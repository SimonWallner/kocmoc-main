// Fragment Shader file "base.frag"

#version 120

varying vec3 outNormal;
varying vec2 outUv;
varying vec3 outTangent;

uniform sampler2D sDiffuse;

void main(void)
{
	vec3 lightDirection = normalize(vec3(-1, -1, -1));
	
	// float diffuse = max(0.0, dot(outNormal, lightDirection));
	// gl_FragColor = vec4(0.2, 0.2, 0.2, 0.2) * diffuse;
	
	gl_FragColor = texture2D(sDiffuse, outUv);
}