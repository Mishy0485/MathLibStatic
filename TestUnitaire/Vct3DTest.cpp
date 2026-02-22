#include "CppUnitTest.h"
#include "Vector3D.h"

using namespace Maths;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace TestUnitaire
{
    TEST_CLASS(TestVct3D)
    {
    public:
        TEST_METHOD(TestConstructor)
        {
            Vct3D<float> v(1.0f, 2.0f, 3.0f);
            Assert::AreEqual(1.0f, v.GetX());
            Assert::AreEqual(2.0f, v.GetY());
            Assert::AreEqual(3.0f, v.GetZ());

            Vct3D<float> defaultV;
            Assert::AreEqual(0.0f, defaultV.GetX());
            Assert::AreEqual(0.0f, defaultV.GetY());
            Assert::AreEqual(0.0f, defaultV.GetZ());
           
        }
        TEST_METHOD(TestSettersGetters)
        {
            Vct3D<float> v;
            v.SetVector3D(5.0f, 6.0f, 7.0f);
            Assert::AreEqual(5.0f, v.GetX());
            Assert::AreEqual(6.0f, v.GetY());
            Assert::AreEqual(7.0f, v.GetZ());

        }
        TEST_METHOD(TestUp)
        {
            Vct3D<float> v(0, 0, 0);
            v.up();
            Assert::IsTrue(v.GetY() > 0);
        }
        TEST_METHOD(TestDown)
        {
            Vct3D<float> v(0, 0, 0);
            v.down();
            Assert::IsTrue(v.GetY() < 0);
        }
        TEST_METHOD(TestLeft)
        {
            Vct3D<float> v(0, 0, 0);
            v.left();
            Assert::IsTrue(v.GetX() < 0);
        }
        TEST_METHOD(TestRight)
        {
            Vct3D<float> v(0, 0, 0);
            v.right();
            Assert::IsTrue(v.GetX() > 0);
        }
        TEST_METHOD(TestFoward)
        {
            Vct3D<float> v(0, 0, 0);
            v.foward();
            Assert::IsTrue(v.GetZ() > 0);
        }
        TEST_METHOD(TestBack)
        {
            Vct3D<float> v(0, 0, 0);
            v.back();
            Assert::IsTrue(v.GetZ() < 0);
        }
        TEST_METHOD(TestOne)
        {
            Vct3D<float> v;
            v.one();
            Assert::AreEqual(1.0f, v.GetX());
            Assert::AreEqual(1.0f, v.GetY());
            Assert::AreEqual(1.0f, v.GetZ());
        }
        TEST_METHOD(TestNegativeInfinity)
        {
            Vct3D<float> v;
            v.nega_tiveInfinity();
            Assert::IsTrue(v.GetX() == -INFINITY || v.GetY() == -INFINITY || v.GetZ() == -INFINITY);
        }
        TEST_METHOD(TestPositiveInfinity)
        {
            Vct3D<float> v;
            v.positiveInfinity();
            Assert::IsTrue(v.GetX() == INFINITY || v.GetY() == INFINITY || v.GetZ() == INFINITY);
        }
        TEST_METHOD(TestZero)
        {
            Vct3D<float> v(5, 6, 7);
            v.zero();
            Assert::AreEqual(0.0f, v.GetX());
            Assert::AreEqual(0.0f, v.GetY());
            Assert::AreEqual(0.0f, v.GetZ());
        }
        TEST_METHOD(TestMagnitude)
        {
            Vct3D<float> v(3, 4, 12);
            Assert::AreEqual(13.0f, v.magnitude());
        }
        TEST_METHOD(TestSqrMagnitude)
        {
            Vct3D<float> v(3, 4, 12);
            Assert::AreEqual(169.0f, v.sqrMagnitude());
        }
        TEST_METHOD(TestNormalized)
        {
            Vct3D<float> v(3, 4, 0);
            Vct3D<float> n = v.Normalized();
            Assert::AreEqual(0.6f, n.GetX(), 0.01f);
            Assert::AreEqual(0.8f, n.GetY(), 0.01f);
        }
        TEST_METHOD(TestNormalize)
        {
            Vct3D<float> v(3, 4, 0);
            v.normalized();
            Assert::AreEqual(0.6f, v.GetX(), 0.01f);
            Assert::AreEqual(0.8f, v.GetY(), 0.01f);
        }
        TEST_METHOD(TestDot)
        {
            Vct3D<float> a(1, 2, 3);
            Vct3D<float> b(4, -5, 6);
            float result = a.Dot(b);
            Assert::AreEqual(12.0f, result, 0.001f);
        }
        TEST_METHOD(TestScale)
        {
            Vct3D<float> a(1, 2, 3);
            Vct3D<float> b(2, 3, 4);
            Vct3D<float> result = a.Scale(b);
            Assert::AreEqual(2.0f, result.GetX());
            Assert::AreEqual(6.0f, result.GetY());
            Assert::AreEqual(12.0f, result.GetZ());
        }
        TEST_METHOD(TestAddition)
        {
            Vct3D<float> a(1, 2, 3);
            Vct3D<float> b(4, 5, 6);
            Vct3D<float> result = a + b;
            Assert::AreEqual(5.0f, result.GetX());
            Assert::AreEqual(7.0f, result.GetY());
            Assert::AreEqual(9.0f, result.GetZ());
        }
        TEST_METHOD(TestSubtraction)
        {
            Vct3D<float> a(5, 6, 7);
            Vct3D<float> b(2, 3, 4);
            Vct3D<float> result = a - b;
            Assert::AreEqual(3.0f, result.GetX());
            Assert::AreEqual(3.0f, result.GetY());
            Assert::AreEqual(3.0f, result.GetZ());
        }
        TEST_METHOD(TestMultiplicationScalar)
        {
            Vct3D<float> v(1, 2, 3);
            Vct3D<float> result = v * 2.0f;
            Assert::AreEqual(2.0f, result.GetX());
            Assert::AreEqual(4.0f, result.GetY());
            Assert::AreEqual(6.0f, result.GetZ());
        }
        TEST_METHOD(TestDivisionScalar)
        {
            Vct3D<float> v(2, 4, 6);
            Vct3D<float> result = v / 2.0f;
            Assert::AreEqual(1.0f, result.GetX());
            Assert::AreEqual(2.0f, result.GetY());
            Assert::AreEqual(3.0f, result.GetZ());
        }
        TEST_METHOD(TestAngle)
        {
            Vct3D<float> a(1, 0, 0);
            Vct3D<float> b(0, 1, 0);
            float angle = a.Angle(b);
            Assert::AreEqual(90.0f, angle, 0.1f);
        }
        TEST_METHOD(TestSignedAngle)
        {
            Vct3D<float> a(1, 0, 0);
            Vct3D<float> b(0, 1, 0);
            float angle = a.SignedAngle(b);
            Assert::AreEqual(90.0f, angle, 0.1f);
        }
        TEST_METHOD(TestDistance)
        {
            Vct3D<float> a(0, 0, 0);
            Vct3D<float> b(0, 3, 4);
            float dist = a.Distance(b);
            Assert::AreEqual(5.0f, dist, 0.001f);
        }
        TEST_METHOD(TestClampMagnitude)
        {
            Vct3D<float> v(3, 4, 0);
            Vct3D<float> result = v.ClampMagnitude(v, 2.0f);
            Assert::AreEqual(2.0f, result.magnitude(), 0.001f);
        }
        TEST_METHOD(TestLerpClamp)
        {
            Vct3D<float> a(0, 0, 0);
            Vct3D<float> b(10, 0, 0);
            Vct3D<float> result = a.LerpClamp(b, 0.5f);
            Assert::AreEqual(5.0f, result.GetX());
        }
        TEST_METHOD(TestLerpUnClamp)
        {
            Vct3D<float> a(0, 0, 0);
            Vct3D<float> b(10, 0, 0);
            Vct3D<float> result = a.LerpUnClamp(b, 1.5f);
            Assert::AreEqual(15.0f, result.GetX());
        }
        TEST_METHOD(TestMax)
        {
            Vct3D<float> a(1, 5, 3);
            Vct3D<float> b(2, 3, 7);
            Vct3D<float> result = a.Max(b);
            Assert::AreEqual(2.0f, result.GetX());
            Assert::AreEqual(5.0f, result.GetY());
            Assert::AreEqual(7.0f, result.GetZ());
        }
        TEST_METHOD(TestMin)
        {
            Vct3D<float> a(1, 5, 3);
            Vct3D<float> b(2, 3, 7);
            Vct3D<float> result = a.Min(b);
            Assert::AreEqual(1.0f, result.GetX());
            Assert::AreEqual(3.0f, result.GetY());
            Assert::AreEqual(3.0f, result.GetZ());
        }
        TEST_METHOD(TestMoveTowards)
        {
            Vct3D<float> start(0, 0, 0);
            Vct3D<float> target(10, 0, 0);
            Vct3D<float> result = start.MoveTowards(target, 2.0f);
            Assert::AreEqual(2.0f, result.GetX());
        }
        TEST_METHOD(TestReflect)
        {
            Vct3D<float> v(1, -1, 0);
            Vct3D<float> normal(0, 1, 0);
            Vct3D<float> result = v.Reflect(normal);
            Assert::AreEqual(1.0f, result.GetX());
            Assert::AreEqual(1.0f, result.GetY());
        }
        TEST_METHOD(TestProject)
        {
            Vct3D<float> a(2, 3, 4);
            Vct3D<float> b(0, 1, 0);
            Vct3D<float> result = a.Projet(b);
            Assert::AreEqual(0.0f, result.GetX());
            Assert::AreEqual(3.0f, result.GetY());
            Assert::AreEqual(0.0f, result.GetZ());
        }
        TEST_METHOD(TestProjectPlane)
        {
            Vct3D<float> a(2, 3, 4);
            Vct3D<float> normal(0, 1, 0);
            Vct3D<float> result = a.Projet_Plan(normal);
            Assert::AreEqual(2.0f, result.GetX());
            Assert::AreEqual(0.0f, result.GetY());
            Assert::AreEqual(4.0f, result.GetZ());
        }
        TEST_METHOD(TestOrthoNormalise)
        {
            Vct3D<float> a(1, 0, 0);
            Vct3D<float> b(0, 1, 0);
            Vct3D<float> c(0, 0, 1);
            a.OrthoNormalise(b, c);
            Assert::AreEqual(1.0f, a.magnitude(), 0.001f);
            Assert::AreEqual(1.0f, b.magnitude(), 0.001f);
        }
        TEST_METHOD(TestEquals)
        {
            Vct3D<float> a(1, 2, 3);
            Vct3D<float> b(1, 2, 3);
            Assert::IsTrue(a == b);
        }
        TEST_METHOD(TestThisInt)
        {
            Vct3D<float> v(1, 2, 3);
            v.thisInt(5.0f, 1);
            Assert::AreEqual(5.0f, v.GetY());
        }
        TEST_METHOD(TestToString)
        {
            Vct3D<float> v(1, 2, 3);
            v.toString();
        }

    };
}
