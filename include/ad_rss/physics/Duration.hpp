/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (c) 2018-2019 Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 *    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *    IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 *    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 *    OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *    POSSIBILITY OF SUCH DAMAGE.
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 */

#pragma once

#include <cmath>
#include <limits>
#include <stdexcept>
/*!
 * @brief namespace ad_rss
 */
namespace ad_rss {
/*!
 * @brief namespace physics
 */
namespace physics {

/*!
 * \brief Forward declaration of DurationSquared
 *
 * Since Duration is defined explicitly as a physical type we have to consider this
 * within operations. Therefore this squared type is defined.
 */
class DurationSquared;

/*!
 * \brief DataType Duration
 *
 * A duration represents a time interval.
 * The unit is: Second
 */
class Duration
{
public:
  /*!
   * \brief constant defining the minimum valid Duration value
   */
  static const double cMinValue;

  /*!
   * \brief constant defining the maximum valid Duration value
   */
  static const double cMaxValue;

  /*!
   * \brief constant defining the assumed Duration value accuracy
   *   used in comparison operator==(), operator!=().
   */
  static const double cPrecisionValue;

  /*!
   * \brief default constructor
   *
   * The default value of Duration is:
   * std::numeric_limits<double>::quiet_NaN()
   */
  Duration()
    : mDuration(std::numeric_limits<double>::quiet_NaN())
  {
  }

  /*!
   * \brief standard constructor
   */
  explicit Duration(double const iDuration)
    : mDuration(iDuration)
  {
  }

  /*!
   * \brief standard copy constructor
   */
  Duration(const Duration &other)
    : mDuration(other.mDuration)
  {
  }

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other Duration
   *
   * \returns Reference to this Duration.
   */
  Duration &operator=(const Duration &other)
  {
    if (&other != this)
    {
      mDuration = other.mDuration;
    }
    return *this;
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Duration
   *
   * \returns \c true if both Duration are valid and can be taken as numerically equal
   */
  bool operator==(const Duration &other) const
  {
    ensureValid();
    other.ensureValid();
    return std::fabs(mDuration - other.mDuration) < cPrecisionValue;
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Duration.
   *
   * \returns \c true if one of the Duration is not valid or they can be taken as numerically different
   */
  bool operator!=(const Duration &other) const
  {
    return !operator==(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Duration.
   *
   * \returns \c true if both Duration are valid and
   *   this Duration is strictly numerically greater than other.
   * \note the precision of Duration is considered
   */
  bool operator>(const Duration &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mDuration > other.mDuration) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Duration.
   *
   * \returns \c true if both Duration are valid and
   *   this Duration is strictly numerically smaller than other.
   * \note the precision of Duration is considered
   */
  bool operator<(const Duration &other) const
  {
    ensureValid();
    other.ensureValid();
    return (mDuration < other.mDuration) && operator!=(other);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Duration.
   *
   * \returns \c true if both Duration are valid and
   *   this Duration is numerically greater than other.
   * \note the precision of Duration is considered
   */
  bool operator>=(const Duration &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mDuration > other.mDuration) || operator==(other));
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Duration
   *
   * \returns \c true if both Duration are valid and
   *   this Duration is numerically smaller than other.
   * \note the precision of Duration is considered
   */
  bool operator<=(const Duration &other) const
  {
    ensureValid();
    other.ensureValid();
    return ((mDuration < other.mDuration) || operator==(other));
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Duration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Duration operator+(const Duration &other) const
  {
    ensureValid();
    other.ensureValid();
    Duration const result(mDuration + other.mDuration);
    result.ensureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Duration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Duration &operator+=(const Duration &other)
  {
    ensureValid();
    other.ensureValid();
    mDuration += other.mDuration;
    ensureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Duration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Duration operator-(const Duration &other) const
  {
    ensureValid();
    other.ensureValid();
    Duration const result(mDuration - other.mDuration);
    result.ensureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Duration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   */
  Duration operator-=(const Duration &other)
  {
    ensureValid();
    other.ensureValid();
    mDuration -= other.mDuration;
    ensureValid();
    return *this;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Duration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid
   * \note since Duration is a type with physical unit, the multiplication results in the Squared type.
   */
  DurationSquared operator*(const Duration &other) const;

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] scalar Scalar double value
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if \c value or the result of
   *   the operation is not valid
   */
  Duration operator*(const double &scalar) const
  {
    ensureValid();
    Duration const result(mDuration * scalar);
    result.ensureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] scalar Scalar double value
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if this or the result of
   *   the operation is not valid or other is zero
   */
  Duration operator/(const double &scalar) const
  {
    Duration const scalarDuration(scalar);
    Duration const result(operator/(scalarDuration));
    result.ensureValid();
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \param[in] other Other Duration
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if one of the two operands or the result of
   *   the operation is not valid or other is zero
   * \note since Duration is a type with physical unit, the division results in the dimensionless type.
   */
  double operator/(const Duration &other) const
  {
    ensureValid();
    other.ensureValidNonZero();
    double const result = mDuration / other.mDuration;
    return result;
  }

  /**
   * \brief standard arithmetic operator
   *
   * \returns Result of arithmetic operation.
   *
   * \note throws a std::out_of_range exception if this or the result of
   *   the operation is not valid
   */
  Duration operator-() const
  {
    ensureValid();
    Duration const result(-mDuration);
    result.ensureValid();
    return result;
  }

  /*!
   * \brief conversion to base type: double
   *
   * \note conversion to the base type removes the physical unit;
   * therefore only explicit calls are allowed
   */
  explicit operator double() const
  {
    return mDuration;
  }

  /*!
   * \returns \c true if the Duration in a valid range
   *
   * An Duration value is defined to be valid if:
   * - It is normal or zero (see std::fpclassify()
   * - cMinDurationValue <= value <= cMaxDurationValue
   */
  bool isValid() const
  {
    auto const valueClass = std::fpclassify(mDuration);
    return ((valueClass == FP_NORMAL) || (valueClass == FP_ZERO)) && (cMinValue <= mDuration)
      && (mDuration <= cMaxValue);
  }

  /*!
   * \brief ensure that the Duration is valid
   *
   * Throws an std::out_of_range() exception if the Duration
   * in not valid (i.e. isValid() returns false)
   */
  void ensureValid() const
  {
    if (!isValid())
    {
      throw std::out_of_range("Duration value out of range");
    }
  }

  /*!
   * \brief ensure that the Duration is valid and non zero
   *
   * Throws an std::out_of_range() exception if the Duration
   * in not valid or zero (i.e. isValid() returns false)
   */
  void ensureValidNonZero() const
  {
    ensureValid();
    if (operator==(Duration(0.)))
    {
      throw std::out_of_range("Duration value is zero");
    }
  }

  /*!
   * \brief get minimum valid Duration
   */
  static Duration getMin()
  {
    return Duration(cMinValue);
  }

  /*!
   * \brief get maximum valid Duration
   */
  static Duration getMax()
  {
    return Duration(cMaxValue);
  }

  /*!
   * \brief get assumed accuracy of Duration
   *   used in comparison operator==(), operator!=().
   */
  static Duration getPrecision()
  {
    return Duration(cPrecisionValue);
  }

private:
  /*!
   * \brief the actual value of the type
   */
  double mDuration;
};

} // namespace physics
} // namespace ad_rss
/**
 * \brief standard arithmetic operator
 *
 * \param[in] other Other Duration as double value
 * \param[in] value Duration value
 *
 * \returns Result of arithmetic operation.
 *
 * \note throws a std::out_of_range exception if \c value or the result of
 *   the operation is not valid
 */
inline ::ad_rss::physics::Duration operator*(const double &other, ::ad_rss::physics::Duration const &value)
{
  return value.operator*(other);
}

/*!
 * \brief namespace std
 */
namespace std {

/*!
 * \brief overload of the std::fabs for Duration
 */
inline ::ad_rss::physics::Duration fabs(const ::ad_rss::physics::Duration other)
{
  ::ad_rss::physics::Duration const result(std::fabs(static_cast<double>(other)));
  return result;
}

/*!
 * \brief specialization of the std::numeric_limits for Duration
 *
 * Derived from std::numeric_limits<double> with overloaded functions:
 * std::numeric_limits<Duration>::lowest()  (\see Duration::getMin())
 * std::numeric_limits<Duration>::max()  (\see Duration::getMax())
 * std::numeric_limits<Duration>::epsilon()  (\see Duration::getPrecision())
 */
template <> class numeric_limits<::ad_rss::physics::Duration> : public numeric_limits<double>
{
public:
  static inline ::ad_rss::physics::Duration lowest()
  {
    return ::ad_rss::physics::Duration::getMin();
  }
  static inline ::ad_rss::physics::Duration max()
  {
    return ::ad_rss::physics::Duration::getMax();
  }
  static inline ::ad_rss::physics::Duration epsilon()
  {
    return ::ad_rss::physics::Duration::getPrecision();
  }
};

} // namespace std
