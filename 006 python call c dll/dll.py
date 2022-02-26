from ctypes import *
import typing

dll = CDLL('./build/libmain.dylib')

dll.print_hello_world.restype = None
dll.print_hello_world.argtypes = None
def print_hello_world() -> None:
    return dll.print_hello_world()

print_hello_world()

dll.print_format.restype = None
dll.print_format.argtypes = c_char_p,
def print_format(c_char_p, *args):
    return dll.print_format(c_char_p, *args)

print_format('format %d %f\n'.encode(), c_int(12), c_double(12.3))

dll.add.restype = c_int
dll.add.argtypes = c_int, c_int
def add(a: c_int, b: c_int) -> c_int:
    return dll.add(a, b)

a = c_int(1)
b = c_int(2)
c = add(a, b)
print(c)

dll.add_arr.restype = None
dll.add_arr.argtypes = POINTER(c_int), POINTER(c_int), POINTER(c_int), c_int
def add_arr(a: POINTER(c_int), b: POINTER(c_int), c: POINTER(c_int), n: c_int) -> None:
    return dll.add_arr(a, b, c, n)

n = c_int(2)
a = (c_int * n.value)()
a[0] = 1
a[1] = 2
b = (c_int * n.value)()
b[0] = 3
b[1] = 4
c = (c_int * n.value)()
add_arr(cast(a, POINTER(c_int)), cast(b, POINTER(c_int)), cast(c, POINTER(c_int)), n)
print(f'{c[0]}, {c[1]}')

class c_Point(Structure):
    _fields_ = [
        ('x', c_int), 
        ('y', c_int) 
        ]

dll.add_point.restype = None
dll.add_point.argtypes = POINTER(c_Point), POINTER(c_Point), POINTER(c_Point)
def add_point(a: POINTER(c_Point), b: POINTER(c_Point), c: POINTER(c_Point)) -> None:
    return dll.add_point(a, b, c)

a = c_Point()
a.x = 1
a.y = 2
b = c_Point()
b.x = 3
b.y = 4
c = c_Point()
add_point(pointer(a), pointer(b), pointer(c))
print(f'{c.x}, {c.y}')
