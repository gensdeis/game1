#pragma once

//#include <pb_game_struct.pb.h>
#include <cstdint>
#include <math.h>
#include "gameCommon.h"
#include "define.h"
#include "protocol/struct/mps_vector.h"

namespace mir3d
{
	struct sRECTANGLE
	{
		sRECTANGLE()
		{
			_centerX = 0;
			_centerY = 0;
			_left = 0;
			_right = 0;
			_top = 0;
			_bottom = 0;
		}

		// inline int32_t Width() { return abs(_right - _left); }
		// inline int32_t Heght() { return abs(_top - _bottom); }
		inline bool IsValid( int32_t x, int32_t y)
		{
			return (_left <= x && x <= _right && _bottom <= y && y <= _top);
		}

		int32_t _centerX;
		int32_t _centerY;
		int32_t _left;
		int32_t _right;
		int32_t _top;
		int32_t _bottom;
	};
	
	struct VECTOR2D
	{
		int32_t X;
		int32_t Y;

	public:
		inline bool operator == (const VECTOR2D& rhs)
		{
			return (this->X == rhs.X && this->Y == rhs.Y);
		}

		inline bool operator != (const VECTOR2D& rhs)
		{
			return (this->X != rhs.X || this->Y != rhs.Y);
		}

		inline const VECTOR2D& operator = (const VECTOR2D& rhs)
		{
			X = rhs.X; Y = rhs.Y;

			return *this;
		}

		inline VECTOR2D operator + (const VECTOR2D& rhs) const
		{
			VECTOR2D vTmp;

			vTmp.X = X + rhs.X;
			vTmp.Y = Y + rhs.Y;

			return vTmp;
		}

		inline VECTOR2D operator - (const VECTOR2D& rhs) const
		{
			VECTOR2D vTmp;

			vTmp.X = X - rhs.X;
			vTmp.Y = Y - rhs.Y;

			return vTmp;
		}

	public:
		VECTOR2D() = default;
		VECTOR2D(int32_t x_, int32_t y_) { X = x_; Y = y_; }
		VECTOR2D(const VECTOR2D& vec) { X = vec.X; Y = vec.Y; }
		VECTOR2D(int32_t vec[2]) { X = vec[0]; Y = vec[1]; }
		~VECTOR2D() = default;
	};

    struct VECTOR3D
    {
    public:
        union
        {
            struct
            {
                float X, Y, Z;
            };
            float _Element[3];
        };

    public:
        bool operator == (const VECTOR3D& rhs );
		bool operator != (const VECTOR3D& rhs );
		
		const VECTOR3D& operator = (const VECTOR3D& vec);
		const VECTOR3D& operator = (const float vec[3]);

		VECTOR3D operator + (const VECTOR3D& vec) const;
		VECTOR3D operator - (const VECTOR3D& vec) const;
		VECTOR3D operator * (const VECTOR3D& vec) const;
		VECTOR3D operator / (const VECTOR3D& vec) const;

		void operator += (const VECTOR3D& vec);
		void operator -= (const VECTOR3D& vec);
		void operator *= (const VECTOR3D& vec);
		void operator /= (const VECTOR3D& vec);

		inline void ZeroVector3D() {X = 0.f; Y = 0.f; Z = 0.f;}
		inline float length() const { return sqrtf( (X*X) + (Y*Y) + (Z*Z) ); }
		inline float length2D() const { return sqrtf((X*X) + (Y*Y)); }
		inline float normalize();
		inline void DegreesToPos(float degrees, int32_t distance);
		inline void RadiansToPos(float radians, int32_t distance);
		inline float PosToDegrees(VECTOR3D targetPos);
		inline float DegreesToRadian(float degrees);
		inline void directionVector(float Yaw);
		inline void sincos(float* ScalarSin, float* ScalarCos, float Value);

		inline float GetRadian(VECTOR3D targetPos)
		{
			return atan2f(targetPos.Y - Y, targetPos.X - X);
		}
		inline VECTOR3D operator * (float scalar ) const
		{
			return VECTOR3D( (X * scalar), (Y * scalar), Z );
		}

		inline VECTOR3D GetDirectionPos(float scalar)
		{
			return VECTOR3D( (X * scalar), (Y * scalar), (Z * scalar) );
		}

		inline bool CheckDistance(int32_t distance)
		{
			if ((int32_t)length2D() > distance && 0 != distance)
			{
				return false;
			}

			return true;
		}

		inline bool CheckPosition(VECTOR3D& check_pos)
		{
			if( (int32_t)X != (int32_t)check_pos.X )
				return false;

			if( (int32_t)Y != (int32_t)check_pos.Y )
				return false;

			check_pos.Z = Z;

			return true;
		}
		
		inline float Clamp(const float X, const float Min, const float Max)
		{
			return X < Min ? Min : X < Max ? X : Max;
		}
		inline VECTOR3D BoundToBox(const VECTOR3D& Min, const VECTOR3D Max) 
		{
			return VECTOR3D
			(
				
				Clamp(X, Min.X, Max.X),
				Clamp(Y, Min.Y, Max.Y),
				Clamp(Z, Min.Z, Max.Z)
			);
		}
	public:
		VECTOR3D() = default;
		VECTOR3D(float x_, float y_, float z_)	{ X = x_; Y = y_; Z = z_; }
		VECTOR3D(const VECTOR3D& vec)			{ X = vec.X; Y = vec.Y; Z = vec.Z; }
        VECTOR3D(float vec[3])					{ X = vec[0]; Y = vec[1]; Z = vec[2]; }
		VECTOR3D(const mps_vector& vec)			{ X = vec.x; Y = vec.y; Z = vec.z; }
		~VECTOR3D() = default;
	};

	inline bool VECTOR3D::operator == (const VECTOR3D& rhs)
	{
		return (static_cast<int32_t>(this->X) == static_cast<int32_t>(rhs.X) && static_cast<int32_t>(this->Y) == static_cast<int32_t>(rhs.Y) /*&& this->z == rhs.z*/);
	} 

	inline bool VECTOR3D::operator != (const VECTOR3D& rhs)
	{
		return (static_cast<int32_t>(this->X) != static_cast<int32_t>(rhs.X) || static_cast<int32_t>(this->Y) != static_cast<int32_t>(rhs.Y) /* || this->z != rhs.z*/);
	}

	inline const VECTOR3D& VECTOR3D::operator = (const VECTOR3D& vec)
	{
		X = vec.X; Y = vec.Y; Z = vec.Z;

		return *this;
	}

	inline const VECTOR3D& VECTOR3D::operator = (const float* vec)
	{
		X = vec[0]; Y = vec[1]; Z = vec[2];

		return *this;
	}

	inline VECTOR3D VECTOR3D::operator + (const VECTOR3D& vec) const
	{
		VECTOR3D vTmp;

		vTmp.X = X + vec.X;
		vTmp.Y = Y + vec.Y;
		vTmp.Z = Z;

		return vTmp;
	}

	inline VECTOR3D VECTOR3D::operator - (const VECTOR3D& vec) const 
	{
		VECTOR3D vTmp;

		vTmp.X = X - vec.X;
		vTmp.Y = Y - vec.Y;
		vTmp.Z = Z - vec.Z;

		return vTmp;
	}

	inline VECTOR3D VECTOR3D::operator * (const VECTOR3D& vec) const 
	{
		VECTOR3D vTmp;

		vTmp.X = X * vec.X;
		vTmp.Y = Y * vec.Y;
		vTmp.Z = Z * vec.Z;

		return vTmp;
	}

	inline VECTOR3D VECTOR3D::operator / (const VECTOR3D& vec) const
	{
		VECTOR3D vTmp;

		vTmp.X = X / vec.X;
		vTmp.Y = Y / vec.Y;
		vTmp.Z = Z / vec.Z;
		
		return vTmp;
	}

	inline void VECTOR3D::operator += (const VECTOR3D& vec) 
	{
		X += vec.X;
		Y += vec.Y;
		Z += vec.Z;
	}

	inline void VECTOR3D::operator -= (const VECTOR3D& vec) 
	{
		X -= vec.X;
	    Y -= vec.Y;
		Z -= vec.Z;
	}

	inline void VECTOR3D::operator *= (const VECTOR3D& vec) 
	{
		X *= vec.X;
		Y *= vec.Y;
		Z *= vec.Z;
	}

	inline void VECTOR3D::operator /= (const VECTOR3D& vec) 
	{
		X /= vec.X;
		Y /= vec.Y;
		Z /= vec.Z;
	}

	inline float VECTOR3D::normalize()
	{
		float len = length();
		if (len > 1e-6f)
		{
			float recip = 1.0f / len;
			X *= recip;
			Y *= recip;
			Z *= recip;
		}
		else
		{
			X = 0.0f;
			Y = 0.0f;
			Z = 0.0f;
			len = 0.0f;
		}

		return len;
	}

	inline void VECTOR3D::DegreesToPos(float degrees, int32_t distance)
	{
		float angle = degrees * DEGREES_TO_RADIANS;

		X = (float)distance * cosf(angle);
		Y = (float)distance * sinf(angle);
		// Z = 0.0f;
	}

	inline void VECTOR3D::RadiansToPos(float radians, int32_t distance)
	{
		X = (float)distance * cosf(radians);
		Y = (float)distance * sinf(radians);
		// Z = 0.0f;
	}

	inline float VECTOR3D::PosToDegrees(VECTOR3D targetPos)
	{
		return atan2f(targetPos.Y - Y, targetPos.X - X) * RADIANS_TO_DEGREES;
	}

	inline float VECTOR3D::DegreesToRadian(float degrees)
	{
		return degrees * DEGREES_TO_RADIANS;
	}

	inline void VECTOR3D::sincos(float* ScalarSin, float* ScalarCos, float Value)
	{
		// Map Value to y in [-pi,pi], x = 2*pi*quotient + remainder.
		float quotient = (SHARE_INV_PI*0.5f)*Value;
		if (Value >= 0.0f)
		{
			quotient = (float)((int)(quotient + 0.5f));
		}
		else
		{
			quotient = (float)((int)(quotient - 0.5f));
		}
		float y = Value - (2.0f*SHARE_PI)*quotient;

		// Map y to [-pi/2,pi/2] with sin(y) = sin(Value).
		float sign;
		if (y > SHARE_HALF_PI)
		{
			y = SHARE_PI - y;
			sign = -1.0f;
		}
		else if (y < -SHARE_HALF_PI)
		{
			y = -SHARE_PI - y;
			sign = -1.0f;
		}
		else
		{
			sign = +1.0f;
		}

		float y2 = y * y;

		// 11-degree minimax approximation
		*ScalarSin = (((((-2.3889859e-08f * y2 + 2.7525562e-06f) * y2 - 0.00019840874f) * y2 + 0.0083333310f) * y2 - 0.16666667f) * y2 + 1.0f) * y;

		// 10-degree minimax approximation
		float p = ((((-2.6051615e-07f * y2 + 2.4760495e-05f) * y2 - 0.0013888378f) * y2 + 0.041666638f) * y2 - 0.5f) * y2 + 1.0f;
		*ScalarCos = sign*p;
	}

	inline void VECTOR3D::directionVector(float Yaw)
	{
		float CP, SP, CY, SY;
		float r = DegreesToRadian(0.0f);
		float y = DegreesToRadian(Yaw);

		sincos(&SP, &CP, r);
		sincos(&SY, &CY, y);

		
		X = CP*CY;
		Y = CP*SY;
		Z = SP;
	}

	
}   //namespace mir3d	
	