// Fragment Shader file "base.frag"

varying vec3 outNormal;
varying vec3 outUv;
varying vec3 outTangent;

void main(void)
{
	gl_FragColor = vec4(0.0, 0.5, 0.5, 1.0);
}