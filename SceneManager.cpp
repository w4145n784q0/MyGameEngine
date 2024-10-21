#include "SceneManager.h"
#include"TestScene.h"
#include"PlayScene.h"
#include"Engine/Direct3D.h"
#include"Model.h"
SceneManager::SceneManager(GameObject* parent)
    :GameObject(parent,"SceneManager")
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID = SCENE_ID_TEST;
	nextSceneID = currentSceneID;
	Instantiate<TestScene>(this);
}

void SceneManager::Update()
{
    //���̃V�[�������݂̃V�[���ƈႤ �� �V�[����؂�ւ��Ȃ���΂Ȃ�Ȃ�
    if (currentSceneID != nextSceneID)
    {
        //���̃V�[���̃I�u�W�F�N�g��S�폜�i�q�I�u�W�F�N�g��S�폜�j
        for (auto itr : childList_)
        {
            itr->ReleaseSub();
            SAFE_DELETE(itr);
            childList_.clear();
        }
        Model::Release();

        //���[�h�����f�[�^��S�폜

        //���̃V�[�����쐬
        switch (nextSceneID)
        {
        case SCENE_ID_TEST: Instantiate<TestScene>(this); break;
        case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
        }

        //�V�[���𐶐��ł�����J�����g�V�[�����X�V
        currentSceneID = nextSceneID;
    }
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}
