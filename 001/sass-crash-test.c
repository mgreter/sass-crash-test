#include <string.h>

#include <sass.h>
#include <sass_context.h>

int
main()
{
  char data[40];
  strncpy(data, "/* First */", sizeof(data));
  struct Sass_Data_Context *dc;
  dc = sass_make_data_context(data);
  return sass_compile_data_context(dc);
}

