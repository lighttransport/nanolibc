project('nanolibc', 'c')

if meson.get_compiler('c').get_id() == 'clang'
  # Raise compiler warning level.
  extra_args = ['-Weverything', '-Werror']
else
  extra_args = []
endif

srcs = [
    'src/nanostdio.c'
  , 'src/nanoassert.c'
  ]
incdir = include_directories('include')

static_library( 'nanolibc', srcs,
  include_directories : incdir,
  c_args : extra_args )
