//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <queue>

// explicit queue(Container&& = Container()); // before C++20
// queue() : queue(Container()) {}            // C++20
// explicit queue(Container&&);               // before C++20

#include <queue>
#include <cassert>

#include "test_macros.h"
#include "test_allocator.h"
#if TEST_STD_VER >= 11
#  include "test_convertible.h"
#endif

int main(int, char**) {
  typedef std::vector<int, limited_allocator<int, 10> > Container;
  typedef std::queue<int, Container> Q;
  Q q;
  assert(q.size() == 0);
  q.push(1);
  q.push(2);
  assert(q.size() == 2);
  assert(q.front() == 1);
  assert(q.back() == 2);

#if TEST_STD_VER >= 11
  // It should be explicit, so not convertible before C++20.
  static_assert(test_convertible<Q>(), "");
#endif

  return 0;
}
