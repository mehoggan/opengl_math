/* Copyright (C)
 *
 * Copyright 2013 Matthew Everett Hoggan
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writting, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "math/vector.h"
#include "matrices/type_matrix_3X3.h"
#include "matrices/type_matrix_4X4.h"
#include "primitives/points/type_point_2d.h"
#include "primitives/points/type_point_3d.h"
#include "primitives/vectors/type_vector_2d.h"
#include "primitives/vectors/type_vector_3d.h"
#include "primitives/vectors/type_vector_4d.h"

#include "math/trig.h"
#include "math/numbers.h"

namespace opengl_math
{
  /*! \brief This function returns a 3X3 matrix translated to point p
   */
  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> translate_to(const matrix_3X3<T, ML> &m,
    const point_2d<T> &p)
  {
    vector_2d<T> to(p.x() - m[2][0], p.y() - m[2][1]);
    matrix_3X3<T, ML> result(m);
    result[2] = m[0] * to[0] + m[1] * to[1] + m[2];
    return result;
  }

  /*! \brief This function returns a 4X4 matrix translated to point p
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> translate_to(const matrix_4X4<T, ML> &m,
    const point_3d<T> &p)
  {
    vector_3d<T> to(p.x() - m[3][0], p.y() - m[3][1], p.z() - m[3][2]);
    matrix_4X4<T, ML> result(m);
    result[3] = m[0] * to[0] + m[1] * to[1] + m[2] * to[2] + m[3];
    return result;
  }

  /*! \brief This function returns a matrix translated by vector v
   */
  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> translate_by(const matrix_3X3<T, ML> &m,
    const vector_2d<T> &v)
  {
    vector_2d<T> by(v);
    matrix_3X3<T, ML> result(m);
    result[2] = m[0] * by[0] + m[1] * by[1] + m[2];
    return result;
  }

  /*! \brief This function returns a matrix translated by vector v
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> translate_by(const matrix_4X4<T, ML> &m,
    const vector_3d<T> &v)
  {
    vector_3d<T> by(v);
    matrix_4X4<T, ML> result(m);
    result[3] = m[0] * by[0] + m[1] * by[1] + m[2] * by[2] + m[3];
    return result;
  }

  /*! \brief This function rotates 2d matrix m to angle angle
   */
  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> rotate_to(const matrix_3X3<T, ML> &m, const T &angle,
    opengl_math::angle_mode mode = opengl_math::radians)
  {
    T a = angle;
    if (mode == opengl_math::degrees) {
      a = opengl_math::degrees_to_radians(angle);
    }
    T c = opengl_math::cos<T, (opengl_math::radians)>(a);
    T s = opengl_math::sin<T, (opengl_math::radians)>(a);

    // Because of matrix indexing column and row matries are treated the same.
    matrix_3X3<T, ML> result(m);
    result[0][0] = c;
    result[0][1] = s;

    result[1][0] = -s;
    result[1][1] = c;

    return result;
  }

  /*! \brief This function rotates 3d matrix m to angle angle
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> rotate_to(const matrix_4X4<T, ML> &m, const T &angle,
    const vector_3d<T> &v, opengl_math::angle_mode mode = opengl_math::radians)
  {
    T a = angle;
    if (mode == opengl_math::degrees) {
      a = opengl_math::degrees_to_radians(angle);
    }
    const T c = opengl_math::cos<T, opengl_math::radians>(a);
    const T s = opengl_math::sin<T, opengl_math::radians>(a);
    const T k = (T(1) - c);

    vector_3d<T> axis(v);
    axis.normalize();
    const T &x = axis[0];
    const T &y = axis[1];
    const T &z = axis[2];

    // The matrix to rotate m by.
    matrix_4X4<T, ML> rotate(null);
    matrix_4X4<T, ML> result(m);

    // http://mathworld.wolfram.com/RodriguesRotationFormula.html
    rotate[0][0] = (x * x * k) + (c);
    rotate[0][1] = (y * x * k) + (z * s);
    rotate[0][2] = (x * z * k) - (y * s);

    rotate[1][0] = (x * y * k) - (z * s);
    rotate[1][1] = (y * y * k) + (c);
    rotate[1][2] = (y * z * k) + (x * s);

    rotate[2][0] = (x * z * k) + (y * s);
    rotate[2][1] = (y * z * k) - (x * s);
    rotate[2][2] = (z * z * k) + (c);

    result[0] = rotate[0];
    result[1] = rotate[1];
    result[2] = rotate[2];
    result[3] = m[3];

    return result;
  }

  /*! \brief This function rotates 2d matrix m by angle angle
   */
  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> rotate_by(const matrix_3X3<T, ML> &m, const T &angle,
    opengl_math::angle_mode mode = opengl_math::radians)
  {
    T a = angle;
    if (mode == opengl_math::degrees) {
      a = opengl_math::degrees_to_radians(angle);
    }
    T c = opengl_math::cos<T, opengl_math::radians>(a);
    T s = opengl_math::sin<T, opengl_math::radians>(a);

    matrix_3X3<T, ML> rotate(null);

    /* [col][row] */
    rotate[0][0] = c;
    rotate[0][1] = s;

    rotate[1][0] = -s;
    rotate[1][1] = c;

    rotate[2][2] = T(1);
    // A bit more expensive than a 2 X 2 matrix multiplication plus a copy of
    // position
    return (rotate * m);
  }

  /*! \brief This function rotates 3d matrix m by angle angle
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> rotate_by(const matrix_4X4<T, ML> &m, const T &angle,
    const vector_3d<T> &v, opengl_math::angle_mode mode = opengl_math::radians)
  {
    T a = angle;
    if (mode == opengl_math::degrees) {
      a = opengl_math::degrees_to_radians(angle);
    }
    const T c = opengl_math::cos<T, opengl_math::radians>(a);
    const T s = opengl_math::sin<T, opengl_math::radians>(a);
    const T k = (T(1) - c);

    vector_3d<T> axis(v);
    axis.normalize();
    const T &x = axis[0];
    const T &y = axis[1];
    const T &z = axis[2];

    matrix_4X4<T, ML> rotate(null);

    // http://mathworld.wolfram.com/RodriguesRotationFormula.html
    rotate[0][0] = (x * x * k) + (c);
    rotate[0][1] = (y * x * k) + (z * s);
    rotate[0][2] = (x * z * k) - (y * s);

    rotate[1][0] = (x * y * k) - (z * s);
    rotate[1][1] = (y * y * k) + (c);
    rotate[1][2] = (y * z * k) + (x * s);

    rotate[2][0] = (x * z * k) + (y * s);
    rotate[2][1] = (y * z * k) - (x * s);
    rotate[2][2] = (z * z * k) + (c);

    rotate[3][3] = T(1);

    // A bit more expensive than a 3 X 3 matrix multiplication plus a copy of
    // position
    return (rotate * m);
  }

/*! \brief This function creates an matrix scaled in the x direction by
   *  x in the y direction by y
   */
  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> scale_by(const matrix_3X3<T, ML> &m, const T &x, const T &y)
  {
    matrix_3X3<T, ML> result(null);
    result[0] = m[0] * x;
    result[1] = m[1] * y;
    result[2] = m[2];
    return result;
  }

  /*! \brief This function creates an matrix scaled in the x direction by
   *  x in the y direction by y and in the z direction by z
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> scale_by(const matrix_4X4<T, ML> &m, const T &x, const T &y,
    const T &z)
  {
    matrix_4X4<T, ML> result(null);
    result[0] = m[0] * x;
    result[1] = m[1] * y;
    result[2] = m[2] * z;
    result[3] = m[3];
    return result;
  }

  /*! \brief This function creates an orthographic matrix
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> ortho(const T &left, const T &right, const T &bottom,
    const T &top)
  {
    matrix_4X4<T, ML> result(identity);
    if (ML == column) {
        result[0][0] = T(2) / (right - left);
        result[1][1] = T(2) / (top - bottom);
        result[2][2] = -T(1);
        result[3][0] = -(right + left) / (right - left);
        result[3][1] = -(top + bottom) / (top - bottom);
    } else if (ML == row) {
        result[0][0] = T(2) / (right - left);
        result[1][1] = T(2) / (top - bottom);
        result[2][2] = T(1);
        result[3][0] = (1 + right) / (1 - right);
        result[3][1] = -(top + bottom) / (bottom - top);
    }
    return result;
  }

  /*! \brief This function creates an orthographic matrix
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> ortho(const T &left, const T &right, const T &bottom,
    const T &top, const T &znear, const T &zfar)
  {
    matrix_4X4<T, ML> result(identity);

    if (ML == column) {
      /* [col][row] */
      result[0][0] = T(2) / (right - left);
      result[1][1] = T(2) / (top - bottom);
      result[2][2] = -T(2) / (zfar - znear);
      result[3][0] = -(right + left) / (right - left);
      result[3][1] = -(top + bottom) / (top - bottom);
      result[3][2] = -(zfar + znear) / (zfar - znear);
    } else if (ML == row) {
      /* [row][col] */
      result[0][0] = T(2) / (right - left);
      result[1][1] = T(2) / (top - bottom);
      result[2][2] = T(1) / (zfar - znear);
      result[3][0] = (1 + right) / (1 - right);
      result[3][1] = (top + bottom) / (bottom - top);
      result[3][2] = znear / (znear - zfar);
    }

    return result;
  }

  /*! \brief This functin creates an perspective matrix
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> perspective(const T &fovy, const T &aspect,
    const T &znear, const T &zfar,
    opengl_math::angle_mode mode = opengl_math::radians)
  {
    T rad = fovy;
    if (mode == opengl_math::degrees) {
      rad = opengl_math::degrees_to_radians(fovy);
    }

    T tan_half_fovy = opengl_math::tan<T, opengl_math::radians>(rad / T(2));

    matrix_4X4<T, ML> result(null);
    result[0][0] = T(1) / (aspect * tan_half_fovy);
    result[1][1] = T(1) / (tan_half_fovy);
    result[2][2] = -(zfar + znear) / (zfar - znear);
    result[2][3] = -T(1);
    result[3][2] = -(T(2) * zfar * znear) / (zfar - znear);
    return result;
  }

  /*! \brief This functin creates an perspective matrix
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> perspective_fov(const T &fov, const T &width,
    const T &height, const T &znear, const T &zfar,
    opengl_math::angle_mode mode = opengl_math::radians)
  {
    const T rad = fov;
    if (mode == opengl_math::degrees) {
      rad = opengl_math::degrees_to_radians(fov);
    }

    T h = opengl_math::cos<T, opengl_math::radians>(T(0.5) * rad) /
      opengl_math::sin<T, opengl_math::radians>(T(0.5) * rad);
    T w = h * height / width;

    matrix_4X4<T, ML> result(null);
    result[0][0] = w;
    result[1][1] = h;
    result[2][2] = -(zfar + znear) / (zfar - znear);
    result[2][3] = -T(1);
    result[3][2] = -(T(2) * zfar * znear) / (zfar - znear);
    return result;
  }

  /*! \brief This function creates a inverse transformatin on the camera
   *  which moves all the objects away from the camera at (0, 0, 0) to
   *  make it appear as if the camera was positioned at (at.x, at.y, at.z) and
   *  looking at center.
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> look_at(const point_3d<T> &eye,
    const point_3d<T> &center, const vector_3d<T> &up)
  {
    vector_3d<T> e(eye.x(), eye.y(), eye.z());
    vector_3d<T> c(center.x(), center.y(), center.z());

    vector_3d<T> f = norm(center - eye);
    vector_3d<T> u = norm(up);
    vector_3d<T> s = norm(f.cross(u));
    u = s.cross(f);

    matrix_4X4<T, ML> result(identity);
    if (ML == column) {
      result[0][0] = s.x();
      result[1][0] = s.y();
      result[2][0] = s.z();
      result[0][1] = u.x();
      result[1][1] = u.y();
      result[2][1] = u.z();
      result[0][2] = -f.x();
      result[1][2] = -f.y();
      result[2][2] = -f.z();
      result[3][0] = -s.dot(e);
      result[3][1] = -u.dot(e);
      result[3][2] = f.dot(e);
    } else if (ML == row) {
      result[0][0] = s.x();
      result[0][1] = s.y();
      result[0][2] = s.z();
      result[1][0] = u.x();
      result[1][1] = u.y();
      result[1][2] = u.z();
      result[2][0] = -f.x();
      result[2][1] = -f.y();
      result[2][2] = -f.z();
      result[0][3] = -s.dot(e);
      result[1][3] = -u.dot(e);
      result[2][3] = f.dot(e);
    }

    return result;
  }

  /*! \brief This functoin returns the product of projection * view * model
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> model_view_projection(const matrix_4X4<T, ML> &model,
    const matrix_4X4<T, ML> &view, const matrix_4X4<T, ML> &projection)
  {
    return (projection * view * model);
  }

  /*! \brief This functoin returns the product of view * model
   */
  template <typename T, matrix_layout ML>
  matrix_4X4<T, ML> model_view(const matrix_4X4<T, ML> &model,
    const matrix_4X4<T, ML> &view)
  {
    return (view * model);
  }

  /*! \brief This functoin returns the upper left 3 X 3 matrix from
   * the a matrix with dimensions of 4 X 4
   */
  template <typename T, matrix_layout ML>
  matrix_3X3<T, ML> orientation_matrix(const matrix_4X4<T, ML> &m)
  {
    matrix_3X3<T, ML> result(identity);

    if (ML == column) {
      result = matrix_3X3<T, ML>(
        vector_3d<T>(m[0][0], m[0][1], m[0][2]),
        vector_3d<T>(m[1][0], m[1][1], m[1][2]),
        vector_3d<T>(m[2][0], m[2][1], m[2][2]));
    } else if (ML == row) {
      result = matrix_3X3<T, ML>(
        vector_3d<T>(m[0][0], m[1][0], m[2][0]),
        vector_3d<T>(m[0][1], m[1][1], m[2][1]),
        vector_3d<T>(m[0][2], m[1][2], m[2][2]));
    }

    return result;
  }
}
#endif
