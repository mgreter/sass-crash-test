#include <string.h>
#include <stdlib.h>

#include <sass.h>
#include <sass_context.h>

int
main()
{
  char data[60];
  struct Sass_Data_Context *dc;
  struct Sass_Context *c;
  struct Sass_Options *o;
  char *data0;
  int rc;

  strncpy(data, "/* First */ a { color: red; }", sizeof(data));
  data0 = strdup(data);
  dc = sass_make_data_context(data0);
  c = sass_data_context_get_context(dc);
  o = sass_context_get_options(c);
  sass_option_set_output_path(o, "file.css");
  rc = sass_compile_data_context(dc);
  sass_delete_data_context(dc);
  return rc;
}

