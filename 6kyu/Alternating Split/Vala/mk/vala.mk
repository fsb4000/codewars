VALAC = valac
PKGS += gee-0.8
PKG_CONFIG ?= pkg-config
VALA_C_FLAGS = `$(PKG_CONFIG) --cflags ${PKGS} glib-2.0 gobject-2.0` -w
VALA_C_LIBS = `$(PKG_CONFIG) --libs ${PKGS} glib-2.0 gobject-2.0`
VALA_FLAGS = -g -C $(addprefix --pkg ,${PKGS}) --pkg posix
