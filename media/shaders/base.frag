// Fragment Shader file "base.frag"

#version 120

varying vec3 normal;
varying vec2 uv;
varying vec3 tangent;

uniform sampler2D sDiffuse;

void main(void)
{
	vec3 lightDirection = normalize(vec3(1, 1, 1));

	vec4 color = texture2D(sDiffuse, uv);	
	float diffuseFactor = max(0.0, dot(normal, lightDirection));
	float ambient = 0.4;
	
	gl_FragColor = vec4(0.2, 0.2, 0.2, 0.2) * max(diffuseFactor, ambient) * color;
}