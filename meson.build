#  Bifrost wrapper file
project('bf_dp4a', 'cpp', 'cuda', version: '0.0.1')

# c_std flags don't get passed to NVCC?
add_global_arguments(['-g', '-std=c++14'], language : ['c', 'cpp', 'cuda'])
#add_global_arguments(['-g', '-L/home/dancpr/software/bifrost/lib', '-l:libbifrost.so', '-std=c++14'], language : 'cuda')
#add_global_arguments(['-g', '-std=c++14',  '-L/home/dancpr/software/bifrost/lib', '-l:libbifrost.so'], language : 'cuda')


c_std = 'c++14'
buildtype = 'debug'

plugin_name = 'bf_dp4a'
cc = meson.get_compiler('cpp')
builddir = meson.project_build_root()

# Dependency: bifrost
bf_dep = dependency('bifrost')
bifrost_src_path = '/home/dancpr/software/bifrost/src'

bf_include = include_directories(
    'src',
    bifrost_src_path, 
    bifrost_src_path / 'cuda',
    bifrost_src_path / 'bifrost', 
    )

cuda_dep = dependency('cuda', version : '>=11', modules : ['cudart', 'nvrtc'])


# Dependency: python
python_sources = [
  'pythonsrc/__init__.py',
  'pythonsrc/libbf_dp4a_wrapper.py',
  'pythonsrc/blocks/__init__.py'
]




srcs =  ['src/xcorr_lite.cu', 'src/beanfarmer.cu']

# Generate shared object from .cu file  
lib = library(plugin_name, srcs,  
              version : '0.0.1', soversion : '0', 
              link_args : ['-Wl,--no-as-needed'],
              dependencies: [bf_dep, cuda_dep], include_directories: bf_include, 
              install: true)

# Python install
py_mod = import('python')
py3 = py_mod.find_installation()
py3_dep = py3.dependency()

py3.install_sources(python_sources, 
                   subdir: plugin_name)

# Need to copy compiled .so over to install dir too
py3_install_dir = py3.get_install_dir()

# Generate python wrapper from .h file
if get_option('generate_wrapper')
  message('Python wrapper generation enabled.')
  r = run_command(f'./generate_wrapper.py', check: true)
  message(r.stdout())
endif 

# Generate shared object
py3.extension_module(plugin_name, srcs,  
              dependencies: [bf_dep, cuda_dep], include_directories: bf_include, 
              subdir: plugin_name,
              install: true)
