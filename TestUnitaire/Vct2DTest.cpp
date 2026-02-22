#include "CppUnitTest.h"
#include "Vector2D.h"

using namespace Maths;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestUnitaire
{
    TEST_CLASS(TestVct2D)
    {
        TEST_METHOD(TestConstructorDefault)
        {
            Vct2D<float> v;
            Assert::AreEqual(0.0f, v.GetX());
            Assert::AreEqual(0.0f, v.GetY());
        }
        TEST_METHOD(TestConstructorValues)
        {
            Vct2D<float> v(3.0f, 4.0f);
            Assert::AreEqual(3.0f, v.GetX());
            Assert::AreEqual(4.0f, v.GetY());
        }
        TEST_METHOD(TestSettersGetters)
        {
            Vct2D<float> v;
            v.SetX(5.0f);
            v.SetY(-2.0f);
            Assert::AreEqual(5.0f, v.GetX());
            Assert::AreEqual(-2.0f, v.GetY());

            v.SetVector2D(1.0f, 2.0f);
            Assert::AreEqual(1.0f, v.GetX());
            Assert::AreEqual(2.0f, v.GetY());
        }
        TEST_METHOD(TestDown)
        {
            Vct2D<float> v(0, 0);
            v.down();
        }

        TEST_METHOD(TestUp)
        {
            Vct2D<float> v(0, 0); v.up();

        }
        TEST_METHOD(TestLeft)
        {
            Vct2D<float> v(0, 0); v.left();
        }
        TEST_METHOD(TestRight)
        {
            Vct2D<float> v(0, 0); v.right();
        }
        TEST_METHOD(TestOne)
        {
            Vct2D<float> v; v.one();
        }
        TEST_METHOD(TestNegativeInfinity)
        {
            Vct2D<float> v; v.nega_tiveInfinity();
        }
        TEST_METHOD(TestPositiveInfinity)
        {
            Vct2D<float> v; v.positiveInfinity();
        }
        TEST_METHOD(TestZero)
        {
            Vct2D<float> v(5, 6); v.zero(); Assert::AreEqual(0.0f, v.GetX()); Assert::AreEqual(0.0f, v.GetY());
        }
        TEST_METHOD(TestMagnitude)
        {
            Vct2D<float> v(3, 4);
            Assert::AreEqual(5.0f, v.magnitude());
        }
        TEST_METHOD(TestSqrMagnitude)
        {
            Vct2D<float> v(3, 4);
            Assert::AreEqual(25.0f, v.sqrMagnitude());
        }
        TEST_METHOD(TestNormalized)
        {
            Vct2D<float> v(3, 4);
            Vct2D<float> n = v.Normalized();
            Assert::AreEqual(0.6f, n.GetX(), 0.0001f);
            Assert::AreEqual(0.8f, n.GetY(), 0.0001f);
        }
        TEST_METHOD(TestNormalizeInPlace)
        {
            Vct2D<float> v(3, 4);
            v.normalized();
            Assert::AreEqual(0.6f, v.GetX(), 0.0001f);
            Assert::AreEqual(0.8f, v.GetY(), 0.0001f);
        }
        TEST_METHOD(TestThisInt)
        {
            Vct2D<float> v;
            v.thisInt(5, 0);
            v.thisInt(6, 1);
            Assert::AreEqual(5.0f, v.GetX());
            Assert::AreEqual(6.0f, v.GetY());
        }
        TEST_METHOD(TestIndexOperator)
        {
            Vct2D<float> v(1, 2);
            Assert::AreEqual(1.0f, v[0]);
            Assert::AreEqual(2.0f, v[1]);
        }
        TEST_METHOD(TestEquality)
        {
            Vct2D<float> v1(1, 2);
            Vct2D<float> v2(1, 2);
            Assert::IsTrue(v1 == v2);
        }
        TEST_METHOD(TestToString)
        {
            Vct2D<float> v(1, 2);
            v.ToString();
        }
        TEST_METHOD(TestAngle)
        {
            Vct2D<float> v1(1, 0);
            Vct2D<float> v2(0, 1);
            float angle = v1.Angle(v2);
            Assert::AreEqual(90.0f, angle, 0.1f);
        }
        TEST_METHOD(TestClampMagnitude)
        {
            Vct2D<float> v(3, 4);
            Vct2D<float> c = v.ClampMagnitude(v, 2);
            Assert::AreEqual(2.0f, c.magnitude(), 0.01f);
        }
        TEST_METHOD(TestDistance)
        {
            Vct2D<float> v1(0, 0);
            Vct2D<float> v2(3, 4);
            Assert::AreEqual(5.0f, v1.Distance(v2));
        }
        TEST_METHOD(TestDot)
        {
            Vct2D<float> v1(1, 2);
            Vct2D<float> v2(3, 4);
            Assert::AreEqual(11.0f, v1.Dot(v2));
        }
        TEST_METHOD(TestLerpClamp)
        {
            Vct2D<float> v1(0, 0);
            Vct2D<float> v2(10, 0);
            Vct2D<float> v = v1.LerpClamp(v2, 0.5f);
            Assert::AreEqual(5.0f, v.GetX());
        }
        TEST_METHOD(TestLerpUnClamp)
        {
            Vct2D<float> v1(0, 0);
            Vct2D<float> v2(10, 0);
            Vct2D<float> v = v1.LerpUnClamp(v2, 1.5f);
            Assert::AreEqual(15.0f, v.GetX());
        }
        TEST_METHOD(TestMax)
        {
            Vct2D<float> v1(1, 5);
            Vct2D<float> v2(3, 2);
            Vct2D<float> v = v1.Max(v2);
            Assert::AreEqual(3.0f, v.GetX());
            Assert::AreEqual(5.0f, v.GetY());
        }
        TEST_METHOD(TestMin)
        {
            Vct2D<float> v1(1, 5);
            Vct2D<float> v2(3, 2);
            Vct2D<float> v = v1.Min(v2);
            Assert::AreEqual(1.0f, v.GetX());
            Assert::AreEqual(2.0f, v.GetY());
        }
        TEST_METHOD(TestMoveTowards)
        {
            Vct2D<float> v1(0, 0);
            Vct2D<float> v2(10, 0);
            Vct2D<float> v = v1.MoveTowards(v2, 5);
            Assert::AreEqual(5.0f, v.GetX());
        }
        TEST_METHOD(TestPerpendicular)
        {
            Vct2D<float> v(1, 0);
            Vct2D<float> p = v.Perpendicular();
            Assert::AreEqual(0.0f, p.GetX(), 0.0001f);
            Assert::AreEqual(1.0f, p.GetY(), 0.0001f);
        }
        TEST_METHOD(TestReflect)
        {
            Vct2D<float> v(1, 1);
            Vct2D<float> n(0, 1);
            Vct2D<float> r = v.Reflect(n);
            Assert::AreEqual(1.0f, r.GetX(), 0.0001f);
            Assert::AreEqual(-1.0f, r.GetY(), 0.0001f);
        }
        TEST_METHOD(TestScale)
        {
            Vct2D<float> v1(2, 3);
            Vct2D<float> v2(4, 5);
            Vct2D<float> s = v1.Scale(v2);
            Assert::AreEqual(8.0f, s.GetX());
            Assert::AreEqual(15.0f, s.GetY());
        }
        TEST_METHOD(TestSignedAngle)
        {
            Vct2D<float> v1(1, 0);
            Vct2D<float> v2(0, 1);
            float angle = v1.SignedAngle(v2);
            Assert::AreEqual(90.0f, angle, 0.1f);
        }
        TEST_METHOD(TestAddition)
        {
            Vct2D<float> v1(1, 2);
            Vct2D<float> v2(3, 4);
            Vct2D<float> v = v1 + v2;
            Assert::AreEqual(4.0f, v.GetX());
            Assert::AreEqual(6.0f, v.GetY());
        }
        TEST_METHOD(TestSubtraction)
        {
            Vct2D<float> v1(5, 6);
            Vct2D<float> v2(3, 4);
            Vct2D<float> v = v1 - v2;
            Assert::AreEqual(2.0f, v.GetX());
            Assert::AreEqual(2.0f, v.GetY());
        }
        TEST_METHOD(TestMultiplicationByScalar)
        {
            Vct2D<float> v(2, 3);
            Vct2D<float> r = v * 2;
            Assert::AreEqual(4.0f, r.GetX());
            Assert::AreEqual(6.0f, r.GetY());
        }
        TEST_METHOD(TestSubTestDivisionByScalartraction)
        {
            Vct2D<float> v(4, 6);
            Vct2D<float> r = v / 2;
            Assert::AreEqual(2.0f, r.GetX());
            Assert::AreEqual(3.0f, r.GetY());
        }
    };
}
