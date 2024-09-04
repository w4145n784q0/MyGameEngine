//	//������������������������������������������������������������������������������
//// �e�N�X�`�����T���v���[�f�[�^�̃O���[�o���ϐ���`
////������������������������������������������������������������������������������
    Texture2D g_texture : register(t0); //�e�N�X�`���[
    SamplerState g_sampler : register(s0); //�T���v���[
//}
//������������������������������������������������������������������������������
// �R���X�^���g�o�b�t�@
// DirectX �����瑗�M����Ă���A�|���S�����_�ȊO�̏����̒�`
//������������������������������������������������������������������������������
cbuffer global
{
    //�ϊ��s��A���_�A����
    float4x4 matW;
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_�[�o�́��s�N�Z���V�F�[�_�[���̓f�[�^�\����
//������������������������������������������������������������������������������
struct VS_OUT
{
    float4 pos : SV_POSITION; //�ʒu
    float2 uv : TEXCOORD; //UV���W
};
//������������������������������������������������������������������������������
// ���_�V�F�[�_
//������������������������������������������������������������������������������
VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD)
{
	//�s�N�Z���V�F�[�_�[�֓n�����
    VS_OUT outData;

	//���[�J�����W�ɁA���[���h�E�r���[�E�v���W�F�N�V�����s���������
    //�X�N���[�����W�ɕϊ����A �s�N�Z���V�F�[�_�[��

    outData.pos = mul(pos, matW);
    outData.uv = uv;
    
    //float4 light = float4(1, 0.8, 0.3, 0); //�����x�N�g���̋t�x�N�g��
    //light = normalize(light); //�P�ʃx�N�g����
    //normal = mul(normal, matW);
    //normal = normalize(normal);
    //outData.cos_alpha = clamp(dot(normal, light), 0, 1);
    
    //�܂Ƃ߂ďo��

    return outData;
}

//������������������������������������������������������������������������������
// �s�N�Z���V�F�[�_
//������������������������������������������������������������������������������
float4 PS(VS_OUT inData) : SV_Target
{
    return g_texture.Sample(g_sampler, inData.uv);
   // return float4(65/255, 105/255, 225/255, 1);
    //float4 my = { 0.125, 0.25, 0, 0 };
    //float4 Id = { 1.0, 1.0, 1.0, 1.0 };
    //float4 Kd = g_texture.Sample(g_sampler, inData.uv);
    //float cos_alpha = inData.cos_alpha;
    //float4 ambentSource = { 0.2, 0.2, 0.2, 1.0 }; //�����̋���
   
    //return Id * Kd * cos_alpha + Id * Kd * ambentSource;
    
    
    
    //return g_texture.Sample(g_sampler, inData.uv);
    //return g_texture.Sample(g_sampler, my);
}

