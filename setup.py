#!/usr/bin/env python3
from distutils.core import setup, Extension

module_dummy = Extension('dummy',
                    define_macros = [('MAJOR_VERSION', '1'),
                                     ('MINOR_VERSION', '0')],
                    include_dirs = ['/usr/local/include', 'datapy/core/include'],
                    library_dirs = ['/usr/local/lib', 'datapy/core/src'],
                    sources = ['datapy/core/src/dummy_module.c'])

setup (name = 'datapy',
       version = '1.0',
       description = 'This is a demo package',
       author = 'Chungyi Chi',
       author_email = 'demonic@csie.io',
       url = '',
       long_description = '''
This is really just a demo package.
''',
       ext_modules = [module_dummy])
