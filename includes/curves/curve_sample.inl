#include "curve/core/CurveSample.h"
#include <NavCore/Math/Vector/Matrix34.h>


namespace curve
{

template<typename RealT>
CurveSampleImpl<RealT>::CurveSampleImpl()
    : m_position(NavCore::Math::Vector3Impl<RealType>::cZero)
    , m_tangent(NavCore::Math::Vector3Impl<RealType>::cZero)
    , m_parameter(0)
{}

template<typename RealT>
CurveSampleImpl<RealT>::CurveSampleImpl(const NavCore::Math::Vector3Impl<RealType>& position,
    const NavCore::Math::Vector3Impl<RealType>& tangent, RealType parameter)
    : m_position(position)
    , m_tangent(tangent)
    , m_parameter(parameter)
{}

template<typename RealT>
void CurveSampleImpl<RealT>::normalizeTangent()
{
    if (!m_tangent.IsLengthNearZero())
        m_tangent.Normalize();
}

template<typename RealT>
NavCore::Math::Matrix34Impl<RealT> CurveSampleImpl<RealT>::createFrame(
    const NavCore::Math::Vector3Impl<RealType>& upDirection) const
{
    NavCore::Math::Matrix34Impl<RealType> outMatrix;
    NavCore::Math::Vector3Impl<RealT> normTangent(m_tangent);
    normTangent.SafeNormalize();

    NT_ASSERT(NavCore::Math::FloatEquals(upDirection.LengthSquared(), static_cast<RealType>(1.0)));

    outMatrix.d = m_position;
    outMatrix.c.Negate(normTangent);
    outMatrix.a.Cross(upDirection, outMatrix.c);
    outMatrix.a.SafeNormalize();
    outMatrix.b.Cross(outMatrix.c, outMatrix.a);

    return outMatrix;
}

template class CurveSampleImpl<float>;
template class CurveSampleImpl<double>;

} // namespace curve
