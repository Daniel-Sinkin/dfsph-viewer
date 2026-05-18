// src/development_markers.hpp

#ifndef DFSPH_VIEWER_SRC_DEVELOPMENT_MARKERS_HPP
#define DFSPH_VIEWER_SRC_DEVELOPMENT_MARKERS_HPP

#pragma once

// Internals
// Externals
// Standard Library
#include <type_traits>
//

#if defined(mut)
#    error "mut marker macro is already defined"
#endif

#if defined(cpy)
#    error "cpy marker macro is already defined"
#endif

#if defined(def)
#    error "def marker macro is already defined"
#endif

#if defined(__clang__)
#    define mut [[clang::annotate("mut")]]
#    define cpy [[clang::annotate("cpy")]]
#else
#    define mut
#    define cpy
#endif

#define def auto

namespace dfsph_viewer
{
template <typename T>
[[nodiscard]] constexpr def copy(const T& value) -> std::remove_cvref_t<T>
{
    return value;
}
}  // namespace dfsph_viewer

#endif  // DFSPH_VIEWER_SRC_DEVELOPMENT_MARKERS_HPP
