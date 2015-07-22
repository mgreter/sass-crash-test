PROG=sass-crash-test

LIBSASS=${.CURDIR}/../../libsass

SRCS= sass-crash-test.c

CFLAGS+= -g
CFLAGS+= -I${LIBSASS}/include

LDADD+= -Wl,-rpath ${LIBSASS}/lib -L${LIBSASS}/lib -lsass

WARNS=9

.include <bsd.prog.mk>
