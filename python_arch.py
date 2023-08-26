import sys, platform

print("Is 64 bit: %x" % sys.maxsize, sys.maxsize > 2**32)
print("Platform: %s" % platform.architecture()[0])