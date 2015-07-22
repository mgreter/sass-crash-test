#include <sass.h>
#include <sass_context.h>
#include <string.h>

int
main()
{
  char data[40];
  strncpy(data, "/* First */", 40);
  struct Sass_Data_Context *dc;
  dc = sass_make_data_context(data);
  return sass_compile_data_context(dc);
}

