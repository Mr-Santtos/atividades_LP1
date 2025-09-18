import pyopencl as cl

platforms = cl.get_platforms()
print("Plataformas OpenCL:", [p.name for p in platforms])
devices = platforms[0].get_devices()
print("Dispositivos da plataforma:", [d.name for d in devices])

