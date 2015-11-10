LIBSASS=${.CURDIR}/../../libsass

CFLAGS+= -g
CFLAGS+= -I${LIBSASS}/include

.if exists(${LIBSASS}/lib)
LDADD+= -Wl,-rpath ${LIBSASS}/lib -L${LIBSASS}/lib -lsass
.else
LDADD+= -Wl,-rpath ${LIBSASS}/src/.libs -L${LIBSASS}/src/.libs -lsass
.endif
