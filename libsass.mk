LIBSASS=${.CURDIR}/../../libsass

CFLAGS+= -g
CFLAGS+= -I${LIBSASS}/include

.if exists(${LIBSASS}/src/.libs)
LDADD+= -Wl,-rpath ${LIBSASS}/src/.libs -L${LIBSASS}/src/.libs -lsass
.else
LDADD+= -Wl,-rpath ${LIBSASS}/lib -L${LIBSASS}/lib -lsass
.endif
