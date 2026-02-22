#include "Matrice3x3.h"
#pragma once

template<typename T>
inline Maths::Matrix3<T>::Matrix3()
{
	tabMat[0][0] = 1; tabMat[0][1] = 0; tabMat[0][2] = 0;
	tabMat[1][0] = 0; tabMat[1][1] = 1; tabMat[1][2] = 0;
	tabMat[2][0] = 0; tabMat[2][1] = 0; tabMat[2][2] = 1;
}

// on met chaque numéro dans les parantheses de create et af ca nous fait la matrice car chaque num du tableau arrive en 
template<typename T>
void Maths::Matrix3<T>::create(T u, T d, T t, T q, T c, T si, T se, T h, T n)
{
	tabMat[0][0] = u;  tabMat[0][1] = d, tabMat[0][2] = t,
		tabMat[1][0] = q;  tabMat[1][1] = c; tabMat[1][2] = si,
		tabMat[2][0] = se; tabMat[2][1] = h, tabMat[2][2] = n;
}

template<typename T>
void Maths::Matrix3<T>::decomposeProjection()
{
	std::cout << tabMat[0][0] << ", " << tabMat[0][1] << ", " << tabMat[0][2] << ", " << std::endl;
	std::cout << tabMat[1][0] << ", " << tabMat[1][1] << ", " << tabMat[1][2] << ", " << std::endl;
	std::cout << tabMat[2][0] << ", " << tabMat[2][1] << ", " << tabMat[2][2] << std::endl << std::endl;
}

// det(A)=a(ei−fh)−b(di−fg)+c(dh−eg) 
template<typename T>
T Maths::Matrix3<T>::determinant()
{
	det = tabMat[0][0] * ((tabMat[1][1] * tabMat[2][2]) - (tabMat[2][1] * tabMat[1][2])) - tabMat[0][1] * ((tabMat[1][0] * tabMat[2][2]) - (tabMat[2][0] * tabMat[1][2])) + tabMat[0][2] * ((tabMat[1][0] * tabMat[2][1]) - (tabMat[2][0] * tabMat[1][1]));

	std::cout << "Determinant : " << det << std::endl << std::endl;

	return det;
}

template<typename T>
void Maths::Matrix3<T>::inverse()
{
	determinant();
	if (det != 0) {
		std::cout << "La matrice est inversible, " << std::endl;

		// calcul des cofacteurs

		tabCofacteur[0][0] = (tabMat[1][1] * tabMat[2][2] - tabMat[1][2] * tabMat[2][1]);     tabCofacteur[0][1] = -(tabMat[1][0] * tabMat[2][2] - tabMat[1][2] * tabMat[2][0]);     tabCofacteur[0][2] = (tabMat[1][0] * tabMat[2][1] - tabMat[1][1] * tabMat[2][0]);

		tabCofacteur[1][0] = -(tabMat[0][1] * tabMat[2][2] - tabMat[0][2] * tabMat[2][1]);    tabCofacteur[1][1] = (tabMat[0][0] * tabMat[2][2] - tabMat[0][2] * tabMat[2][0]);      tabCofacteur[1][2] = -(tabMat[0][0] * tabMat[2][1] - tabMat[0][1] * tabMat[2][0]);

		tabCofacteur[2][0] = (tabMat[0][1] * tabMat[1][2] - tabMat[0][2] * tabMat[1][1]);     tabCofacteur[2][1] = -(tabMat[0][0] * tabMat[1][2] - tabMat[0][2] * tabMat[1][0]);     tabCofacteur[2][2] = (tabMat[0][0] * tabMat[1][1] - tabMat[0][1] * tabMat[1][0]);

		// transposé 

		tabCofacteur[0][0]; tabCofacteur[1][0]; tabCofacteur[2][0];

		tabCofacteur[0][1]; tabCofacteur[1][1]; tabCofacteur[2][1];

		tabCofacteur[0][2]; tabCofacteur[1][2]; tabCofacteur[2][2];

		// calcul avec la division du determinant 

		tabCofacteur[0][0] = tabCofacteur[0][0] / det;
		tabCofacteur[0][1] = tabCofacteur[0][1] / det;
		tabCofacteur[0][2] = tabCofacteur[0][2] / det;
		tabCofacteur[1][0] = tabCofacteur[1][0] / det;
		tabCofacteur[1][1] = tabCofacteur[1][1] / det;
		tabCofacteur[1][2] = tabCofacteur[1][2] / det;
		tabCofacteur[2][0] = tabCofacteur[2][0] / det;
		tabCofacteur[2][1] = tabCofacteur[2][1] / det;
		tabCofacteur[2][2] = tabCofacteur[2][2] / det;

		std::cout << "Matrice inverse : " << std::endl << std::endl;
		std::cout << tabCofacteur[0][0] << ", " << tabCofacteur[1][0] << ", " << tabCofacteur[2][0] << ", " << std::endl;
		std::cout << tabCofacteur[0][1] << ", " << tabCofacteur[1][1] << ", " << tabCofacteur[2][1] << ", " << std::endl;
		std::cout << tabCofacteur[0][2] << ", " << tabCofacteur[1][2] << ", " << tabCofacteur[2][2] << std::endl << std::endl;

	}
	else {
		std::cout << "La matrice n'est pas inversible" << std::endl << std::endl;
	}
}

template<typename T>
void Maths::Matrix3<T>::isIdentity()
{
	if (tabMat[0][0] == 1 && tabMat[1][1] == 1 && tabMat[2][2] == 1) {
		std::cout << "La matrice est identitaire" << std::endl << std::endl;
		isIdentityBool = true;
	}
	else {
		std::cout << "La matrice n'est pas identitaire" << std::endl << std::endl;
		isIdentityBool = false;
	}
}

template<typename T>
void Maths::Matrix3<T>::transpose()
{
	std::cout << "Transpose" << std::endl << std::endl;
	std::cout << tabMat[0][0] << ", " << tabMat[1][0] << ", " << tabMat[2][0] << ", " << std::endl;
	std::cout << tabMat[0][1] << ", " << tabMat[1][1] << ", " << tabMat[2][1] << ", " << std::endl;
	std::cout << tabMat[0][2] << ", " << tabMat[1][2] << ", " << tabMat[2][2] << std::endl << std::endl;
}

/// <summary>
/// /////////////////////////////////////////////////////////////////
/// </summary>

template<typename T>
void Maths::Matrix3<T>::getColumn(int column)
{
	if (column == 1) {
		std::cout << tabMat[0][0] << " " << tabMat[0][1] << " " << tabMat[0][2] << std::endl << std::endl;
	}
	else if (column == 2) {
		std::cout << tabMat[1][0] << " " << tabMat[1][1] << " " << tabMat[1][2] << std::endl << std::endl;
	}
	else if (column == 3) {
		std::cout << tabMat[2][0] << " " << tabMat[2][1] << " " << tabMat[2][2] << std::endl << std::endl;
	}
	else {
		std::cout << "Un mauvais numero a ete entree, il faut un numero entre 0 et 2." << std::endl << std::endl;
	}
}

template<typename T>
void Maths::Matrix3<T>::getPosition(int row, int column)
{
	tabMat[row][column];

	std::cout << "Position : " << tabMat[row][column] << std::endl << std::endl;
}

template<typename T>
void Maths::Matrix3<T>::getRow(int row)
{
	if (row == 1) {
		std::cout << tabMat[0][0] << " " << tabMat[1][0] << " " << tabMat[2][0] << std::endl << std::endl;
	}
	else if (row == 2) {
		std::cout << tabMat[0][1] << " " << tabMat[1][1] << " " << tabMat[2][1] << std::endl << std::endl;
	}
	else if (row == 3) {
		std::cout << tabMat[0][2] << " " << tabMat[1][2] << " " << tabMat[2][2] << std::endl << std::endl;
	}
	else {
		std::cout << "Un mauvais numero a ete entree, il faut un numero entre 0 et 2." << std::endl << std::endl;
	}
}

template<typename T>
void Maths::Matrix3<T>::setColumn(int columnNumber, int number1, int number2, int number3)
{
	tabMat[0][columnNumber] = number1;
	tabMat[1][columnNumber] = number2;
	tabMat[2][columnNumber] = number3;
	decomposeProjection();
}

template<typename T>
void Maths::Matrix3<T>::setRow(int rowNumber, int number1, int number2, int number3)
{
	tabMat[rowNumber][0] = number1;
	tabMat[rowNumber][1] = number2;
	tabMat[rowNumber][2] = number3;
	decomposeProjection();
}

template<typename T>
void Maths::Matrix3<T>::ortho(T left, T right, T bottom, T top, T zNear, T zFar)
{
	tabMat[0][0] = 2 / (right - left);
	tabMat[0][1] = 0;
	tabMat[0][2] = 0;
	tabMat[1][0] = 0;
	tabMat[1][1] = 2 / (top - bottom);
	tabMat[1][2] = 0;
	tabMat[2][0] = -(right + left) / (right - left);
	tabMat[2][1] = -(top + bottom) / (top - bottom);
	tabMat[2][2] = 1;
	decomposeProjection();
}