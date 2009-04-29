// Copyright (c) 2009  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
// Author(s)     : Sebastien Loriot, Sylvain Pion

#ifndef CGAL_TUPLE_H
#define CGAL_TUPLE_H

// A wrapper around C++0x, TR1 or Boost tuple<>.
// Together with the Is_in_tuple<> tool.

#include <CGAL/config.h>

#ifndef CGAL_CFG_NO_CPP0X_TUPLE
#  include <tuple>
#elif !defined CGAL_CFG_NO_TR1_TUPLE
#  include <tr1/tuple>
#else
#  include <boost/tuple/tuple.hpp>
#endif

CGAL_BEGIN_NAMESPACE

#ifndef CGAL_CFG_NO_CPP0X_TUPLE
using std::tuple;
using std::make_tuple;
using std::tie;
using std::get;
#elif !defined CGAL_CFG_NO_TR1_TUPLE
using std::tr1::tuple;
using std::tr1::make_tuple;
using std::tr1::tie;
using std::tr1::get;
#else
using boost::tuple;
using boost::make_tuple;
using boost::tie;
using boost::get;
#endif


#ifndef CGAL_CFG_NO_CPP0X_VARIADIC_TEMPLATES

// Tool to test whether a type V is among the types of a tuple<...> = T.
template <typename V, typename T>
struct Is_in_tuple;

template <typename V, typename T0, typename... T>
struct Is_in_tuple <V, tuple<T0, T...> >
{
  static const bool value = Is_in_tuple<V, tuple<T...> >::value;
};

template <typename V, typename... T>
struct Is_in_tuple <V, tuple<V, T...> >
{
  static const bool value = true;
};

template <typename V>
struct Is_in_tuple <V, tuple<> >
{
  static const bool value = false;
};

#else

// Non-variadic version

template <typename V, typename T>
struct Is_in_tuple;

template <typename V, typename T0, typename T1>
struct Is_in_tuple <V, tuple<T0, T1> >
{
  static const bool value = Is_in_tuple<V, tuple<T1> >::value;
};

template <typename V, typename T1>
struct Is_in_tuple <V, tuple<V,T1> >
{
  static const bool value = true;
};

template <typename V>
struct Is_in_tuple <V, tuple<V> >
{
  static const bool value = true;
};

template <typename V, typename T1>
struct Is_in_tuple <V, tuple<T1> >
{
  static const bool value = false;
};

#endif 

CGAL_END_NAMESPACE

#endif // CGAL_TUPLE_H
