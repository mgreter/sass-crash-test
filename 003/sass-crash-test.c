#include <string.h>

#include <sass.h>
#include <sass_context.h>

int
main()
{
  char data[40];
  struct Sass_Data_Context *dc;
  struct Sass_Context *c;
  struct Sass_Options *o;
  int rc;
  strncpy(data, "/* First */", sizeof(data));
  dc = sass_make_data_context(data);
  c = sass_data_context_get_context(dc);
  o = sass_context_get_options(c);
  sass_option_set_output_path(o, "file.css");
  rc = sass_compile_data_context(dc);
  sass_delete_data_context(dc);
  return rc;
}

