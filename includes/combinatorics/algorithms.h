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
#ifndef COMBINATORIC_H_INCLUDED
#define COMBINATORIC_H_INCLUDED

namespace opengl_math
{
  class combinatorics
  {
  public:
    template <typename CI, std::size_t N, typename T>
    static bool n_cr_k(CI &in, T k)
    {
      if (k >= N || k == 0 || N == 1) {
        return false;
      }

      T i = k;
      T ii = static_cast<T>(N - 1);

      while (i != 0) {
        if (in[--i] < in[ii]) {
          T j = static_cast<T>(k);
          while (!(in[i] < in[j])) {
            ++j;
          }
          std::swap(in[i], in[j]);
          ++i;
          ++j;
          ii = k;
          std::rotate(&in[i], &in[j], (&in[0] + N));
          while (j != N) {
            ++j;
            ++ii;
          }
          std::rotate(&in[k], &in[ii], (&in[0] + N));
          return true;
        }
      }
      std::rotate(&in[0], &in[k], (&in[0] + N));
      return false;
    }
  };
}
#endif
