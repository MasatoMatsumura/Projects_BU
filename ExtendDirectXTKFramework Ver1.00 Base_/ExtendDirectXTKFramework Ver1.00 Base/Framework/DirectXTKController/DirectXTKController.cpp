#include "DirectXTKController.h"
#include "../DeviceController/DeviceController.h"

using namespace DirectX;
using namespace Framework;

DirectXTKController::DirectXTKController( )
{
}

DirectXTKController::~DirectXTKController( )
{
}

void DirectXTKController::InitializeDirectXTK( )
{
	this->g_pCommonStates.reset( new CommonStates( D3DDEVICES->pd3dDevice ) );
	this->g_pSpriteBatch.reset( new SpriteBatch( D3DDEVICES->pImmediateContext ) );
}

void DirectXTKController::DrawDefaultSpriteBegin( )
{
	this->g_pSpriteBatch->Begin( SpriteSortMode::SpriteSortMode_Deferred, this->g_pCommonStates->NonPremultiplied( ), this->g_pCommonStates->PointWrap( ) );
}

void DirectXTKController::DrawSpriteEnd( )
{
	this->g_pSpriteBatch->End( );
}