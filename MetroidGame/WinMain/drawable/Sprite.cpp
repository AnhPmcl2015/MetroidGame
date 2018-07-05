#include "Sprite.h"

Sprite::Sprite()
{
	_Texture = NULL;
	_ScaleFactor.Set(1, 1);
	_RotationOrigin.Set(0, 0);
	_Rotation = 0;
	_Position.Set(0, 0);
	_IsCenterOrigin = true;
	_RectSize.Set(0, 0);
	_RectPosition.Set(0, 0);
	_Size.Set(0, 0);
	_FlipX = false;
	_FlipY = false;
}

Sprite::Sprite(Texture *texture)
{

	_Texture = texture;
	_ScaleFactor.Set(1, 1);
	_RotationOrigin.Set(0, 0);
	_Rotation = 0;
	_Position.Set(0, 0);
	_IsCenterOrigin = true;
	_RectSize.Set(texture->GetImageSize().x, texture->GetImageSize().y);
	_Size.Set(_RectSize.x, _RectSize.y);
	_RectPosition.Set(0, 0);
	_FlipX = false;
	_FlipY = false;
}

Sprite::Sprite(Texture *texture, float x, float y, float rectLeft, float rectTop, float rectWidth, float rectHeight)
{

	_Texture = texture;
	_ScaleFactor.Set(1, 1);
	_Size.Set(rectWidth, rectWidth);
	_RotationOrigin.Set(0, 0);
	_Position.Set(x, y);
	_IsCenterOrigin = true;
	_Rotation = 0;
	_RectSize.Set(rectWidth, rectHeight);
	_RectPosition.Set(rectLeft, rectTop);
	_FlipX = false;
	_FlipY = false;
}

//all get functions
const Vector2& Sprite::GetRotationOrigin() const
{
	return _RotationOrigin;
}
float Sprite::GetRotation() const
{
	return _Rotation;
}
const Vector2& Sprite::GetScale() const
{
	return _ScaleFactor;
}

Texture*  Sprite::GetTexture() const
{
	return _Texture;
}

const Vector2& Sprite::GetSize() const
{
	return _Size;
}

//all set functions
void Sprite::SetRotationOrigin(float centerX, float centerY)
{
	_RotationOrigin.Set(centerX, centerY);
}

void Sprite::SetRotation(float rotation)
{
	_Rotation = rotation;
}

void Sprite::SetRegion(const TextureRegion &textureRegion)
{
	_Texture = textureRegion.GetTexture();
	_RectSize = textureRegion.GetRectSize();
	_RectPosition = textureRegion.GetRectPosition();
}

const Vector2& Sprite::GetPosition() const
{
	return _Position;
}

const Vector2& Sprite::GetRectSize() const
{
	return _RectSize;
}
const Vector2& Sprite::GetRectPosition() const
{
	return _RectPosition;
}

void Sprite::SetPosition(float x, float y)
{
	_Position.Set(x, y);
}

void  Sprite::SetTexture(Texture *texture)
{
	_Texture = texture;
}

void Sprite::SetSize(float width, float height)
{
	_Size.Set(width, height);
	_ScaleFactor.Set(width / _RectSize.x, height / _RectSize.y);
}

void Sprite::SetCenterRotationOrigin(bool center)
{
	_IsCenterOrigin = center;
}

bool Sprite::IsCenterOrigin() const
{
	return _IsCenterOrigin;
}

void Sprite::SetRectPosition(float rectX, float rectY)
{
	_RectPosition.Set(rectX, rectY);
}
void Sprite::SetRectSize(float rectWidth, float rectHeight)
{
	_RectSize.Set(rectWidth, rectHeight);
}

//Flip the image 
void Sprite::Flip(bool flipX, bool flipY)
{
	_FlipX = flipX;
	_FlipY = flipY;

	if (flipX)
	{
		_ScaleFactor.x = abs(_ScaleFactor.x)* -1;
	}
	else
	{
		_ScaleFactor.x = abs(_ScaleFactor.x);
	}

	if (flipY)
	{
		_ScaleFactor.y = abs(_ScaleFactor.y)* -1;;
	}
	else
	{
		_ScaleFactor.y = abs(_ScaleFactor.y);
	}
}

bool Sprite::IsFlipX()
{
	return _FlipX;
}

bool Sprite::IsFlipY()
{
	return _FlipY;
}

void Sprite::ResetToWhole()
{
	_RectSize.Set(_Texture->GetImageSize().x, _Texture->GetImageSize().y);
	_ScaleFactor.Set(1, 1);
}

Sprite::~Sprite()
{

}
