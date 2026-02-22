#pragma once
#include "Vector3D.h"

template <typename T>
void Maths::Vct3D<T>::SetVector3D(T x, T y, T z)
{
	SetX(x);
	SetY(y);
	SetZ(z);


}


template <typename T>
void Maths::Vct3D<T>::back()
{
	SetX(0);
	SetY(0);
	SetZ(-1);


}


template <typename T>
void Maths::Vct3D<T>::down()
{
	SetX(0);
	SetY(-1);
	SetZ(0);


}


template <typename T>
void Maths::Vct3D<T>::foward()
{
	SetX(0);
	SetY(0);
	SetZ(1);


}


template <typename T>
void Maths::Vct3D<T>::left()
{
	SetX(-1);
	SetY(0);
	SetZ(0);


}


template <typename T>
void Maths::Vct3D<T>::nega_tiveInfinity()
{
	if constexpr (std::is_floating_point_v<T>) {		//verifie si T est un type � virgule flottante
		SetX(-std::numeric_limits<T>::infinity());
		SetY(-std::numeric_limits<T>::infinity());
		SetZ(-std::numeric_limits<T>::infinity());
	}
	else {												//si T est un type entier
		SetX(std::numeric_limits<T>::lowest());
		SetY(std::numeric_limits<T>::lowest());
		SetZ(std::numeric_limits<T>::lowest());
	}
}


template <typename T>
void Maths::Vct3D<T>::one()
{
	SetX(1);
	SetY(1);
	SetZ(1);
}


template <typename T>
void Maths::Vct3D<T>::positiveInfinity()
{
	if constexpr (std::is_floating_point_v<T>) {		//verifie si T est un type � virgule flottante
		SetX(std::numeric_limits<T>::infinity());
		SetY(std::numeric_limits<T>::infinity());
		SetZ(std::numeric_limits<T>::infinity());
	}
	else {												//si T est un type entier
		SetX(std::numeric_limits<T>::max());
		SetY(std::numeric_limits<T>::max());
		SetZ(std::numeric_limits<T>::max());
	}
}


template <typename T>
void Maths::Vct3D<T>::right()
{
	SetX(1);
	SetY(0);
	SetZ(0);
}


template <typename T>
void Maths::Vct3D<T>::up()
{
	SetX(0);
	SetY(1);
	SetZ(0);
}


template <typename T>
void Maths::Vct3D<T>::zero()
{
	SetX(0);
	SetY(0);
	SetZ(0);
}


template <typename T>
T Maths::Vct3D<T>::magnitude() const
{
	T m = GetX() * GetX() + GetY() * GetY() + GetZ() * GetZ();
	T r = std::sqrt(m);
	return r;
}


template <typename T>
T Maths::Vct3D<T>::sqrMagnitude() const {

	return GetX() * GetX() + GetY() * GetY() + GetZ() * GetZ();

}


template <typename T>
void Maths::Vct3D<T>::normalized() {

	T m = GetX() * GetX() + GetY() * GetY() + GetZ() * GetZ();
	T r = std::sqrt(m);
	if (r == 0)
	{
		throw std::runtime_error("Magnitude nulle");
		return;
	}
	SetX(GetX() / r);
	SetY(GetY() / r);
	SetZ(GetZ() / r);


}


template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::Normalized() const {


	T m = GetX() * GetX() + GetY() * GetY() + GetZ() * GetZ();
	T r = std::sqrt(m);
	if (r == 0)
	{
		throw std::runtime_error("Magnitude nulle");
	}
	return Vct3D<T>(GetX() / r, GetY() / r, GetZ() / r);
}

template <typename T>
bool Maths::Vct3D<T>::Equal(const Vct3D<T>& other) const
{
	return GetX() == other.GetX() && GetY() == other.GetY() && GetZ() == other.GetZ();
}

template <typename T>
void Maths::Vct3D<T>::thisInt(T i, int index) {
	if (index == 0)
	{
		SetX(i);
	}
	else if (index == 1)
	{
		SetY(i);
	}
	else if (index == 2)
	{
		SetZ(i);
	}
	else
	{
		throw std::out_of_range("Index invalide");
	}

}


template <typename T>
bool Maths::Vct3D<T>::operator==(const Vct3D<T>& other) const
{
	return x == other.x && y == other.y && z == other.z;
}


template <typename T>
void Maths::Vct3D<T>::toString() const
{
	std::cout << "X: " << GetX() << " Y: " << GetY() << " Z: " << GetZ() << std::endl;
}



template <typename T>
T Maths::Vct3D<T>::Angle(const Vct3D<T>& other) const
{
	T ps = x * other.x + y * other.y + z * other.z;
	T m1 = std::sqrt(x * x + y * y + z * z);
	T m2 = std::sqrt(other.x * other.x + other.y * other.y + other.z * other.z);
	if (m1 != 0 && m2 != 0)
	{
		T cosAngle = std::clamp(ps / (m1 * m2), -1.0f, 1.0f);
		return std::acos(cosAngle) * (180.0f / 3.14159265f);
	}
	throw std::runtime_error("Magnitude nulle");
	return 0;
}


template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::ClampMagnitude(const Vct3D<T>& v, T maxLength)
{
	T m = v.GetX() * v.GetX() + v.GetY() * v.GetY() + v.GetZ() * v.GetZ();
	T r = std::sqrt(m);
	if (r > maxLength)
	{
		T re_scale = maxLength / r;
		return Vct3D<T>(v.GetX() * re_scale, v.GetY() * re_scale, v.GetZ() * re_scale);
	}
	return v;
}


template <typename T>
T Maths::Vct3D<T>::Distance(const Vct3D<T>& other) const
{
	T dx = other.GetX() - GetX();
	T dy = other.GetY() - GetY();
	T dz = other.GetZ() - GetZ();
	return std::sqrt(dx * dx + dy * dy + dz * dz);
}


template <typename T>
T Maths::Vct3D<T>::Dot(const Vct3D<T>& other) const
{
	return GetX() * other.GetX() + GetY() * other.GetY() + GetZ() * other.GetZ();
}



template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::LerpClamp(const Vct3D<T>& target, T t) const
{
	t = std::clamp(t, 0.0f, 1.0f); // Affectation de la valeur clamp�e � t sinon la valeur est ignorer
	T newX = GetX() + (target.GetX() - GetX()) * t;
	T newY = GetY() + (target.GetY() - GetY()) * t;
	T newZ = GetZ() + (target.GetZ() - GetZ()) * t;
	return Vct3D<T>(newX, newY, newZ);
}


template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::LerpUnClamp(const Vct3D<T>& target, T t) const
{
	T newX = GetX() + (target.GetX() - GetX()) * t;
	T newY = GetY() + (target.GetY() - GetY()) * t;
	T newZ = GetZ() + (target.GetZ() - GetZ()) * t;
	return Vct3D<T>(newX, newY, newZ);
}


template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::Max(const Vct3D<T>& other) const
{

	T maxX = std::max(GetX(), other.GetX());
	T maxY = std::max(GetY(), other.GetY());
	T maxZ = std::max(GetZ(), other.GetZ());
	return Vct3D<T>(maxX, maxY, maxZ);
}


template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::Min(const Vct3D<T>& other) const
{
	T minX = std::min(GetX(), other.GetX());
	T minY = std::min(GetY(), other.GetY());
	T minZ = std::min(GetZ(), other.GetZ());
	return Vct3D<T>(minX, minY, minZ);
}


template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::MoveTowards(Vct3D<T> target, T maxDistanceDelta) const
{
	T dX = target.GetX() - GetX();
	T dY = target.GetY() - GetY();
	T dZ = target.GetZ() - GetZ();
	T distance = std::sqrt(dX * dX + dY * dY + dZ * dZ);
	if (distance == 0 || (maxDistanceDelta >= 0 && distance <= maxDistanceDelta))
	{
		return target;
	}

	T r = maxDistanceDelta / distance;
	return Vct3D<T>(GetX() + dX * r, GetY() + dY * r, GetZ() + dZ * r);
}


template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::Reflect(const Vct3D<T>& vct_normaliser) const
{
	if (vct_normaliser.magnitude() == 0) {
		throw std::runtime_error("Vecteur nulle");
	}
	Vct3D<T> Vn = vct_normaliser.Normalized();		//Vn = vecteur normalis�
	T dotPdt = this->Dot(Vn);				//dotPdt = dot product


	T rx = GetX() - 2 * dotPdt * Vn.GetX();
	T ry = GetY() - 2 * dotPdt * Vn.GetY();
	T rz = GetZ() - 2 * dotPdt * Vn.GetZ();
	return Vct3D<T>(rx, ry, rz);
}


template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::Scale(const Vct3D<T>& other) const
{
	return Vct3D<T>(GetX() * other.GetX(), GetY() * other.GetY(), GetZ() * other.GetZ());
}


template <typename T>
void  Maths::Vct3D<T>::OrthoNormalise(Vct3D<T>& b, Vct3D<T>& c)
{
	b = b.Normalized();

	c = c - b * b.Dot(c);

	c = c.Normalized();
}


template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::Projet(const Vct3D<T>& onNormal) const
{
	Vct3D<T> onNormalN = onNormal.Normalized();
	T dot = this->Dot(onNormalN);
	return onNormalN * dot;
}


template <typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::Projet_Plan(const Vct3D<T>& planeNormal) const
{
	return Vct3D<T>(GetX(), GetY(), GetZ()) - Projet(planeNormal);
}

// C'est pour les matrices tkt
template<typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::Cross(const Maths::Vct3D<T>& a, const Maths::Vct3D<T>& b)
{
	return Maths::Vct3D<T>(
		a.GetY() * b.GetZ() - a.GetZ() * b.GetY(),
		a.GetZ() * b.GetX() - a.GetX() * b.GetZ(),
		a.GetX() * b.GetY() - a.GetY() * b.GetX()
	);
}

template<typename T>
Maths::Vct3D<T> Maths::Vct3D<T>::AddVector(const Maths::Vct3D<T>& a, const Maths::Vct3D<T>& b) {
		return Maths::Vct3D<T>(
		a.GetX() + b.GetX(),
		a.GetY() + b.GetY(),
		a.GetZ() + b.GetZ()
	);
}


//template <typename T>
//MathsVct2D::Vct2D<T> MathsVct3D::Vct3D<T>::Transfo2D(const Vct3D<T>& vct_transfo) const
//{
//	T x = vct_transfo.GetX();
//	T y = vct_transfo.GetY();
//
//	return MathsVct2D::Vct2D<T>(x, y);
//}


template <typename T>
T Maths::Vct3D<T>::SignedAngle(Vct3D<T>& other) const
{
	T angle = Vct3D<T>::Angle(other);

	// vrai produit vectoriel
	T crossX = GetY() * other.GetZ() - GetZ() * other.GetY();
	T crossY = GetZ() * other.GetX() - GetX() * other.GetZ();
	T crossZ = GetX() * other.GetY() - GetY() * other.GetX();

	// utilisation du Z pour d�terminer le signe (approximation si rotation autour de Z)
	if (crossZ < 0)
	{
		angle = -angle;
	}
	return angle;
}

