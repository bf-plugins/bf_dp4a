#  Bifrost wrapper file
project('bf_dp4a', 'cpp', 'cuda', version: '0.0.1')

add_global_arguments('-std=c++11', language : 'c')
add_global_arguments('-std=c++11', language : 'cuda')

plugin_name = 'bf_dp4a'
cc = meson.get_compiler('cpp')
builddir = meson.project_build_root()

# Dependency: bifrost
bf_dep = dependency('bifrost')
bifrost_src_path = '/home/dancpr/software/bifrost/src'

bf_include = include_directories(
    bifrost_src_path, 
    bifrost_src_path / 'cuda',
    bifrost_src_path / 'bifrost', 
    )

cuda_dep = dependency('cuda', version : '>=11', modules : ['cudart', 'nvrtc'])

# Generate python wrapper from .h file
r = run_command('./generate_wrapper.py', check: true)
message(r.stdout())

srcs =  ['src/xcorr_lite.cu', 'src/beanfarmer.cu']

# Generate shared object from .cu file  
lib = library(plugin_name, srcs,  
              version : '0.0.1', soversion : '0', 
              dependencies: [bf_dep, cuda_dep], include_directories: bf_include)


