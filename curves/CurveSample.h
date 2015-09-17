#pragma once

#include <NavCore/Math/Vector/Matrix34Decl.h>
#include <NavCore/Math/Vector/Vector3.h>
#include "curve/CurveApi.h"
#include "curve/core/CurveSampleDecl.h"

namespace curve
{

/**
 * @brief A CurveSample contains the three most commonly used curve values: position, tangent, and
 * parametric value.
 */
template<typename RealT>
class CURVE_API CurveSampleImpl
{
public:
    using RealType = RealT;

    CurveSampleImpl();
    CurveSampleImpl(const NavCore::Math::Vector3Impl<RealType>& position,
        const NavCore::Math::Vector3Impl<RealType>& tangent, RealType parameter);

    void normalizeTangent();

    /**
     * @brief Returns an orthonormal matrix at this curve sample, where the matrix.c = -tangent.
     */
    NavCore::Math::Matrix34Impl<RealType> createFrame(
        const NavCore::Math::Vector3Impl<RealType>& upDirection =
        NavCore::Math::Vector3Impl<RealType>::cZAxis) const;

    NavCore::Math::Vector3Impl<RealType> m_position;
    NavCore::Math::Vector3Impl<RealType> m_tangent;
    RealType m_parameter;
};

} // namespace curve
