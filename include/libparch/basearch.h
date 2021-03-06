#ifndef LIBPARCH_BASEARCH_H
#define LIBPARCH_BASEARCH_H


/// Return list of native architectures compatible with a given basearch.
/// Order of items in the result has no special meaning.
///
/// Data ownership: The returned list MUST be freed. The individual list items are static and MUST NOT be freed.
const char ** libparch_basearch_get_compatible_native_arches(const char * basearch);


/// Return list of multilib architectures compatible with a given basearch.
/// Order of items in the result has no special meaning.
///
/// Data ownership: The returned list MUST be freed. The individual list items are static and MUST NOT be freed.
const char ** libparch_basearch_get_compatible_multilib_arches(const char * basearch);


#endif  // LIBPARCH_BASEARCH_H
