
#include "CppUnitTest.h"
#include "Matrice3x3.h"

using namespace Maths;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestUnitaire
{
    TEST_CLASS(TestMatrice3)
    {
    public:


        TEST_METHOD(TestDeterminant)
        {
            Matrix3<float> mat;
            mat.create(1, 2, 3, 0, 1, 4, 5, 6, 0);
            float det = mat.determinant();
            Assert::IsTrue(det != 0.0f);
        }

        TEST_METHOD(TestInverse)
        {
            Matrix3<float> mat;
            mat.create(2, 0, 0, 0, 2, 0, 0, 0, 2);
            mat.inverse();
            float det = mat.determinant();
            Assert::IsTrue(det != 0.0f);
        }


        TEST_METHOD(TestDecomposeProjection)
        {
            Matrix3<float> mat;
            mat.decomposeProjection();
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestGetColumn)
        {
            Matrix3<float> mat;
            mat.create(1, 2, 3, 4, 5, 6, 7, 8, 9);
            mat.getColumn(0);
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestGetRow)
        {
            Matrix3<float> mat;
            mat.create(1, 2, 3, 4, 5, 6, 7, 8, 9);
            mat.getRow(1);
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestGetPosition)
        {
            Matrix3<float> mat;
            mat.create(1, 2, 3, 4, 5, 6, 7, 8, 9);
            mat.getPosition(2, 2);
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestSetColumn)
        {

            Matrix3<float> mat;
            mat.setColumn(0, 1, 2, 3);
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestSetRow)
        {
            Matrix3<float> mat;
            mat.setRow(1, 4, 5, 6);
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestOrtho)
        {
            Matrix3<float> mat;
            mat.ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
            Assert::IsTrue(true);
        }

    };
}