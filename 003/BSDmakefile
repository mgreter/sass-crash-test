PROG=sass-crash-test

LIBSASS=${.CURDIR}/../../libsass

SRCS= sass-crash-test.c

CFLAGS+= -g
CFLAGS+= -I${LIBSASS}/include

LDADD+= -Wl,-rpath ${LIBSASS}/lib -L${LIBSASS}/lib -lsass

.include <bsd.prog.mk>
