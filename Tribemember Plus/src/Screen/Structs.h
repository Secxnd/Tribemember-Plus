#pragma once
#include <Windows.h>
typedef unsigned char uint8;
typedef unsigned short uint16;

struct rgb {
	uint8 R = 0;
	uint8 G = 0;
	uint8 B = 0;

	rgb(uint8 r, uint8 g, uint8 b) : R(r), G(g), B(b) {}

	bool operator==(const rgb& Other) { return R == Other.R && G == Other.G && B == Other.B; }
	bool operator!=(const rgb& Other) { return R != Other.R || G != Other.G || B != Other.B; }
	bool operator!() { return R == 0 && G == 0 && B == 0; }

	void operator=(const rgb& Other) { 
		R = Other.R;
		G = Other.G;
		B = Other.B;
	}

	rgb operator+(const rgb& Other) { return rgb(R + Other.R, G + Other.G, B + Other.B); }
	rgb operator-(const rgb& Other) { return rgb(R - Other.R, G - Other.G, B - Other.B); }

	bool IsWithinThreshold(uint8 Threshold) { return R <= Threshold && R >= (Threshold - Threshold * 2) && G <= Threshold && G >= (Threshold - Threshold * 2) && B <= Threshold && B >= (Threshold - Threshold * 2); }
};

struct Vector2D {
	uint16 X = 0;
	uint16 Y = 0;

	Vector2D(uint16 x, uint16 y) : X(x), Y(y) {}

	bool operator==(const Vector2D& Other) { return X == Other.X && Y == Other.Y; }
	bool operator!=(const Vector2D& Other) { return X != Other.X || Y != Other.Y; }
	bool operator!() { return X == 0 && Y == 0; }

	Vector2D operator+(const Vector2D& Other) { return Vector2D(X + Other.X, Y + Other.Y); }
	Vector2D operator-(const Vector2D& Other) { return Vector2D(X - Other.X, Y - Other.Y); }

	rgb GetColor() {
		COLORREF PixelColor = GetPixel(GetDC(0), X, Y);
		return rgb(GetRValue(PixelColor), GetGValue(PixelColor), GetBValue(PixelColor));
	}
};

struct Icon {
	Vector2D Position;
	rgb Color;

	Icon(Vector2D PixelPosition, rgb PixelColor) : Position(PixelPosition), Color(PixelColor) {}

	bool IsIconActive() { return Color == Position.GetColor(); }
	bool IsIconActive(uint8 Threshold) { return (Color - Position.GetColor()).IsWithinThreshold(Threshold); }
};