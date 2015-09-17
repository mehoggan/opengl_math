#include "curve/core/TessellationQuality.h"

namespace curve
{

template<typename RealT>
static TessellationQualityImpl<RealT> CreatePrecise()
{
    TessellationQualityImpl<RealT> preciseQuality;
    preciseQuality.m_chordalTolerance = 0.0005f;
    return preciseQuality;
}

template<typename RealT>
const TessellationQualityImpl<RealT> TessellationQualityImpl<RealT>::cDefault;
template<typename RealT>
const TessellationQualityImpl<RealT> TessellationQualityImpl<RealT>::cPrecise = CreatePrecise<RealT>();

template<typename RealT>
TessellationQualityImpl<RealT>::TessellationQualityImpl()
    : m_chordalTolerance(0.01f)
{
}

template class TessellationQualityImpl<float>;
template class TessellationQualityImpl<double>;

} // namespace curve
